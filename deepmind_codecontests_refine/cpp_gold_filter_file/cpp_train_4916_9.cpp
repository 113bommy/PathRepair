#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 5010;
int x[MAXN];
int f[MAXN][680], sum[MAXN], r[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> p;
  for (int i = 2; i <= 5000; ++i) {
    bool flag = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) flag = false;
    }
    if (flag) p.push_back(i);
  }
  int m = p.size();
  r[0] = r[1] = -1;
  for (int i = 2; i <= 5000; ++i) {
    int temp = i;
    r[i] = r[i - 1];
    for (int j = 0; j < m; ++j) {
      f[i][j] = f[i - 1][j];
      while (temp % p[j] == 0) {
        temp /= p[j];
        ++f[i][j];
        r[i] = max(r[i], j);
      }
      sum[i] += f[i][j];
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++x[a];
  }
  LL ans = 0;
  for (int i = 2; i <= 5000; ++i) ans += 1LL * x[i] * sum[i];
  for (int i = m - 1; i >= 0;) {
    LL temp = ans;
    int count = 0;
    for (int j = 0; j <= 5000; ++j) {
      if (r[j] == i) count += x[j];
    }
    if (count + count <= n) {
      --i;
      continue;
    }
    for (int j = 0; j <= 5000; ++j) {
      if (r[j] != i) {
        r[j] = -1;
        continue;
      }
      --f[j][r[j]];
      if (f[j][r[j]] > 0) continue;
      while (r[j] >= 0 && f[j][r[j]] == 0) --r[j];
    }
    ans = ans - count + n - count;
  }
  cout << ans << endl;
  return 0;
}
