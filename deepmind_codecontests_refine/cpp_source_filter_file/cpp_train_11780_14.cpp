#include <bits/stdc++.h>
using namespace std;
class sparse {
 public:
  vector<vector<int>> indo;
  sparse(vector<int> &arr) {
    int k = 32 - __builtin_clz(arr.size());
    indo.reserve(k + 1);
    for (int i = 0; i < k; i++) {
      indo.push_back(vector<int>(arr.size()));
    }
    for (int i = 0; i < arr.size(); i++) {
      indo[0][i] = arr[i];
    }
    int t = 1;
    for (int i = 1; i < k; i++) {
      for (int j = 0; j <= arr.size() - (1 << i); j++) {
        indo[i][j] = min(indo[i - 1][j], indo[i - 1][j + t]);
      }
      t = (t << 1);
    }
  }
  int query(int a, int b) {
    b++;
    int d = b - a;
    int k = 31 - __builtin_clz(d);
    return min(indo[k][a], indo[k][b - (1 << k)]);
  }
};
const int maxn = 2e5 + 10;
const int maxlog = 20;
int perm[maxn];
int v[maxn];
int prox[maxn];
int pai[maxn];
int dp[maxn][maxlog];
int jmp(int a, int j) {
  for (int i = 0; i < maxlog; i++)
    if ((j >> i) & 1) a = dp[a][i];
  return a;
}
int main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> perm(n);
  for (auto &k : perm) cin >> k;
  unordered_map<int, int> anterior;
  unordered_map<int, int> lastap;
  for (int i = 1; i < n; i++) {
    anterior[perm[i - 1]] = perm[i];
  }
  anterior[perm[perm.size() - 1]] = perm[0];
  for (int i = 1; i <= m; i++) cin >> v[i];
  for (int i = m; i > 0; i--) {
    pai[i] = lastap[anterior[v[i]]];
    lastap[v[i]] = i;
  }
  for (int i = 0; i < maxn; i++) {
    dp[i][0] = pai[i];
  }
  for (int j = 1; j < maxlog; j++)
    for (int i = 0; i < maxn; i++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
  vector<int> proximo(m + 1);
  for (int i = 1; i <= m; i++) {
    proximo[i] = jmp(i, n - 1);
  }
  for (auto &k : proximo)
    if (k == 0) k = INT_MAX;
  sparse seg1 = sparse(proximo);
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (seg1.query(a, b + 1) <= b)
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
}
