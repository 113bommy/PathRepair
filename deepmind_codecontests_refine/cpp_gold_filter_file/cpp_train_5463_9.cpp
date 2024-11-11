#include <bits/stdc++.h>
long long INF = (1ll << 30);
using namespace std;
int rm[18][100005][5];
void init(vector<long long>& tab, int qq) {
  int n = tab.size();
  for (int i = 0; i < n; i++) rm[0][i][qq] = tab[i];
  for (int k = 1; k < 18; k++)
    for (int i = 0; i <= n - (1 << k); i++)
      rm[k][i][qq] = max(rm[k - 1][i][qq], rm[k - 1][i + (1 << (k - 1))][qq]);
}
long long max_query(int a, int b, int qq) {
  if (a > b) return 0;
  int k = 31 - __builtin_clz(b - a + 1);
  return max(rm[k][a][qq], rm[k][b - (1 << k) + 1][qq]);
}
long long n, m, k;
bool check(int i, int x) {
  long long ans = 0;
  for (int j = 0; j < m; j++) {
    ans += max_query(i, x, j);
  }
  return ans <= k;
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  vector<vector<long long> > grid;
  grid.assign(m, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[j][i];
    }
  }
  for (int i = 0; i < m; i++) {
    init(grid[i], i);
  }
  pair<long long, long long> ans = make_pair(0, -1);
  for (int i = 0; i < n; i++) {
    int x = i - 1, y = n - 1;
    while (x < y) {
      int z = (x + y + 1) / 2;
      if (check(i, z)) {
        x = z;
      } else {
        y = z - 1;
      }
    }
    if (ans.second - ans.first < x - i) {
      ans = make_pair(i, x);
    }
  }
  for (int i = 0; i < m; i++) {
    cout << max_query(ans.first, ans.second, i) << " ";
  }
  cout << endl;
  return 0;
}
