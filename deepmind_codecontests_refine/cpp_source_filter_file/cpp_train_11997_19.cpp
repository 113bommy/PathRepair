#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 110;
int a[maxn][maxn] = {};
int cl[maxn][maxn], cr[maxn][maxn], cu[maxn][maxn], cd[maxn][maxn];
int main() {
  int n, m, K;
  scanf("%d%d", &n, &K);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    m = s.length();
    for (int j = 0; j < m; ++j) a[i][j] = s[j] - '0';
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != 0) {
        cl[i][j] = j;
        cr[i][j] = j;
        cu[i][j] = i;
        cd[i][j] = i;
        while (cl[i][j] > 0 && a[i][cl[i][j] - 1] == a[i][j]) cl[i][j]--;
        while (cr[i][j] < n - 1 && a[i][cr[i][j] + 1] == a[i][j]) cr[i][j]++;
        while (cu[i][j] > 0 && a[cu[i][j] - 1][j] == a[i][j]) cu[i][j]--;
        while (cd[i][j] < n - 1 && a[cd[i][j] + 1][j] == a[i][j]) cd[i][j]++;
      }
    }
  int bpi = 0, bpj = 0;
  int dp = 0;
  int cp = 1;
  int dx[] = {0, -1, 0, 1};
  int dy[] = {1, 0, -1, 0};
  for (int i = 0; i < K; ++i) {
    int curi = 0, curj = 0;
    if (dp == 0 && cp == 1 || dp == 1 && cp == 0)
      curi = cu[bpi][bpj], curj = cr[bpi][bpj];
    if (dp == 2 && cp == 0 || dp == 1 && cp == 1)
      curi = cu[bpi][bpj], curj = cl[bpi][bpj];
    if (dp == 2 && cp == 1 || dp == 3 && cp == 0)
      curi = cd[bpi][bpj], curj = cl[bpi][bpj];
    if (dp == 0 && cp == 0 || dp == 3 && cp == 1)
      curi = cd[bpi][bpj], curj = cr[bpi][bpj];
    curi += dx[dp];
    curj += dy[dp];
    if (curi >= 0 && curi < n && curj >= 0 && curj < m && a[curi][curj] != 0) {
      bpi = curi;
      bpj = curj;
    } else {
      if (cp == 1)
        cp = 0;
      else {
        cp = 1;
        dp--;
        if (dp == -1) dp = 3;
      }
    }
  }
  int ans = a[bpi][bpj];
  printf("%d", ans);
  return 0;
}
