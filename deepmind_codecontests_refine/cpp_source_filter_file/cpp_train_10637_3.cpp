#include <bits/stdc++.h>
using namespace std;
long long n, m, k, i, j, c, t, a, b, d[100005], l[100005], len[100005],
    g[100005][11], pos[50][50], p[50], res, ans, mod = 998244353;
string s;
vector<int> v;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    for (j = d[i], t = 0; j > 0; t++, j /= 10) {
      g[i][t] = j % 10;
    }
    l[i] = t;
    len[t]++;
  }
  p[0] = 1;
  for (int i = 1; i <= 22; i++) p[i] = (p[i - 1] * 10) % mod;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l[i]; j++) {
      for (int t = 0; t <= 10; t++) {
        if (t <= j) {
          pos[g[i][j]][t + j] += len[t];
          pos[g[i][j]][t + j] += len[t];
        } else {
          pos[g[i][j]][2 * j + 1] += len[t];
          pos[g[i][j]][2 * j] += len[t];
        }
      }
    }
  }
  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j < 25; j++) {
      if (pos[i][j] == 0) continue;
      res = (res + (i * (pos[i][j] * p[j]) % mod) % mod) % mod;
    }
  }
  cout << res;
}
