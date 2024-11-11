#include <bits/stdc++.h>
using namespace std;
long long gcd1(long long a, long long b) {
  if (a == 0) return b;
  return gcd1(b % a, a);
}
long long modx(long long base, long long ex) {
  long long ans = 1LL, val = base;
  while (ex > 0LL) {
    if (ex & 1LL) ans = (ans * val) % 998244353LL;
    val = (val * val) % 998244353LL;
    ex = ex >> 1LL;
  }
  return ans;
}
const int maxn = 105;
char c[maxn][maxn];
int n, m, left1[maxn][maxn], right1[maxn][maxn], down[maxn][maxn],
    up[maxn][maxn], ans[maxn][maxn];
vector<pair<int, pair<int, int> > > v;
bool mark[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> c[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == '*')
        left1[i][j] = 1 + left1[i][j - 1];
      else
        left1[i][j] = 0;
    }
    for (int j = m; j >= 1; j--) {
      if (c[i][j] == '*') {
        right1[i][j] = right1[i][j + 1] + 1;
      } else {
        right1[i][j] = 0;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (c[i][j] == '*')
        up[i][j] = up[i - 1][j] + 1;
      else
        up[i][j] = 0;
    }
    for (int i = n; i >= 1; i--) {
      if (c[i][j] == '*')
        down[i][j] = down[i + 1][j] + 1;
      else
        down[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans[i][j] =
          min(up[i][j], min(down[i][j], min(right1[i][j], left1[i][j])));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == '*' && ans[i][j] >= 2) {
        mark[i][j] = true;
        for (int k = j + 1; k < j + ans[i][j]; k++) mark[i][k] = true;
        for (int k = j - 1; k > j - ans[i][j]; k--) mark[i][k] = true;
        for (int k = i + 1; k < i + ans[i][j]; k++) mark[k][j] = true;
        for (int k = i - 1; k > i - ans[i][j]; k--) mark[k][j] = true;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i][j] == '*' && !mark[i][j]) {
        cout << -1 << endl;
        return 0;
      } else if (c[i][j] && ans[i][j] >= 2)
        v.push_back(make_pair(ans[i][j] - 1, make_pair(i, j)));
    }
  }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i].second.first << " " << v[i].second.second << " " << v[i].first
         << endl;
  return 0;
}
