#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const long long inf = 1ll << 50;
int n, a, b, color, l[maxn], bio[maxn][3];
long long dp[maxn][3], sol = 1ll << 62;
long long rek(int p, int na, int id);
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int d = max(sqrt(l[0]), sqrt(l[n - 1]));
  vector<int> v{l[0] - 1, l[0], l[0] + 1, l[n - 1] - 1, l[n - 1], l[n - 1] + 1};
  set<int> pr;
  for (int i = 2; i <= d; i++) {
    for (int j = 0; j < 6; j++) {
      bool ima = false;
      while (v[j] % i == 0) {
        v[j] /= i;
        ima = true;
      }
      if (ima) {
        pr.insert(i);
      }
    }
  }
  for (int i = 0; i < 6; i++) {
    if (v[i] != 1) {
      pr.insert(v[i]);
    }
  }
  for (int i : pr) {
    color++;
    if (rek(i, n - 1, 0) >= 0) sol = min(sol, rek(i, n - 1, 0));
  }
  cout << sol << endl;
}
long long rek(int p, int na, int id) {
  if (na == -1) return 0;
  if (bio[na][id] == color) return dp[na][id];
  bio[na][id] = color;
  int x = l[na];
  long long c = inf;
  if ((x + 1) % p == 0 || (x - 1) % p == 0)
    c = b;
  else if (x % p == 0)
    c = 0;
  if (id == 0)
    return dp[na][id] = min(c + rek(p, na - 1, 0), a + rek(p, na - 1, 1));
  if (id == 1)
    return dp[na][id] = min(c + rek(p, na - 1, 2), a + rek(p, na - 1, 1));
  return dp[na][id] = c + rek(p, na - 1, 2);
}
