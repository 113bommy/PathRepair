#include <bits/stdc++.h>
using namespace std;
const int N = 17;
long long k, t;
long long f[N][N], c[N][N], lim[N], g[N][N];
vector<int> ans;
string s = "";
void read() { cin >> k >> t; }
char hex(int first) {
  if (first >= 10) return 'a' + (first - 10);
  return '0' + first;
}
long long C(int n, int k) {
  if (k == 0 || k == n) return 1;
  if (c[n][k] != -1) return c[n][k];
  return c[n][k] = C(n - 1, k - 1) + C(n - 1, k);
}
long long F(int i, int j) {
  if (i == 0) return 1;
  if (j == 16) return 0;
  if (f[i][j] != -1) return f[i][j];
  f[i][j] = 0;
  for (int k = 0; k <= min(i - (j == 0), (int)t); k++) {
    f[i][j] += C(i - (j == 0), k) * F(i - k, j + 1);
  }
  return f[i][j];
}
long long G(int i, int j) {
  if (i == 0) return 1;
  if (j == -1) return 0;
  if (g[i][j] != -1) return g[i][j];
  g[i][j] = 0;
  for (int k = 0; k <= min(i, (int)(t - lim[j])); k++) {
    g[i][j] += C(i, k) * G(i - k, j - 1);
  }
  return g[i][j];
}
long long cal(int len) {
  if (len == 0) return 0;
  return cal(len - 1) + F(len, 0);
}
void solve() {
  memset(f, 255, sizeof(f));
  memset(c, 255, sizeof(c));
  memset(g, 255, sizeof(g));
  int i = 15, ld = 1;
  while (cal(i) > k) i--;
  i++;
  k -= cal(i - 1);
  while (i > 0) {
    for (int j = ld; j <= 15; j++)
      if (lim[j] + 1 <= t) {
        lim[j]++;
        ld = 0;
        memset(g, 255, sizeof(g));
        long long tmp = G(i - 1, 15);
        if (tmp < k)
          k -= tmp;
        else {
          ans.push_back(j);
          cout << hex(j);
          break;
        }
        lim[j]--;
      }
    i--;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  read();
  solve();
  return 0;
}
