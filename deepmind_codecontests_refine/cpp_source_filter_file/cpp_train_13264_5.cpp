#include <bits/stdc++.h>
using namespace std;
int cnt[42][42][42][42];
int aux[42][42][42][42];
int aux2[42][42];
int n, m, q;
string s[50];
map<long long, int> mapka;
int ans(int x, int y, int w, int h, int W, int H) {
  return cnt[x + w - 1][y + h - 1][W - w + 1][H - h + 1] -
         cnt[x + w - 1][y - 1][W - w + 1][H - h + 1] -
         cnt[x - 1][y + h - 1][W - w + 1][H - h + 1] +
         cnt[x - 1][y - 1][W - w + 1][H - h + 1];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      aux2[i][j] = aux2[i - 1][j] + aux2[i][j - 1] - aux2[i - 1][j - 1] +
                   (s[i - 1][j - 1] - '0');
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int w = i; w < n; ++w)
        for (int h = j; h < m; ++h) {
          if ((aux2[w + 1][h + 1] - aux2[w + 1][j] - aux2[i][h + 1] +
               aux2[i][j]) == 0)
            aux[i + 1][j + 1][w - i + 1][h - j + 1]++;
        }
  for (int w = 1; w <= n; ++w)
    for (int h = 1; h <= m; ++h) {
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
          cnt[i][j][w][h] = cnt[i - 1][j][w][h] + cnt[i][j - 1][w][h] -
                            cnt[i - 1][j - 1][w][h] + aux[i][j][w][h];
    }
  while (q--) {
    int x, y, z, t;
    cin >> x >> y >> z >> t;
    int nn = z - x + 1;
    int mm = t - y + 1;
    long long k = x * 1000000000000000l + y * 1000000000l + z * 100000l * t;
    if (mapka.find(k) == mapka.end()) {
      int res = 0;
      for (int i = 1; i <= nn; ++i)
        for (int j = 1; j <= mm; ++j) res += ans(x, y, i, j, nn, mm);
      cout << res << "\n";
      mapka[k] = res;
    } else
      cout << mapka[k] << "\n";
  }
  return 0;
}
