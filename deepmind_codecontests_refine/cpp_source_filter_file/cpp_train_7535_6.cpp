#include <bits/stdc++.h>
inline int random(int x) {
  if (RAND_MAX == 32767)
    return (rand() << 15 ^ rand()) % x;
  else
    return rand() % x;
}
using namespace std;
const int N = 2002;
const char lc = 'a', hc = 'z';
int ggwp[N * 2], len[N * 2], to[N * 2][hc - lc + 1];
int cnt[N * 2];
void sufau(char *s, int n, int &m) {
  m = 1;
  int i, l = 0;
  memset(ggwp, 0, sizeof(ggwp[0]) * n * 2);
  memset(to, 0, sizeof(to[0]) * n * 2);
  memset(cnt, 0, sizeof(cnt[0]) * n * 2);
  ggwp[0] = -1;
  for (i = 0; i < n; ++i) {
    char c = s[i] - lc;
    int x = m++;
    len[x] = i + 1;
    cnt[x] = 1;
    for (; l >= 0 && !to[l][c]; l = ggwp[l]) to[l][c] = x;
    if (l >= 0) {
      int p = to[l][c];
      if (len[p] == len[l] + 1)
        ggwp[x] = p;
      else {
        int q = m++;
        len[q] = len[l] + 1;
        ggwp[q] = ggwp[p];
        memcpy(to[q], to[p], sizeof(to[q]));
        for (; l >= 0 && to[l][c] == p; l = ggwp[l]) to[l][c] = q;
        ggwp[x] = ggwp[p] = q;
      }
    }
    l = x;
  }
}
bool v[N][N];
char s[N];
char p[11][N];
int pl[11], pr[11];
int n, m;
int i, j, k;
int pi[N];
bool cmp(int i, int j) { return len[i] < len[j]; }
int mxz[N];
int z[N];
void zf(char s[], int n, int z[]) {
  int i, j;
  z[0] = j = 0;
  for (i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i - j], j + z[j] - i));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] > j + z[j]) j = i;
  }
}
int main() {
  cin >> s;
  n = strlen(s);
  cin >> m;
  for (i = 0; i < m; ++i) cin >> p[i] >> pl[i] >> pr[i];
  memset(v, 1, sizeof(v));
  for (i = 0; i < n; ++i) {
    zf(s + i, n - i, z);
    for (j = i; j < n; ++j) mxz[j] = max(mxz[j], z[j - i]);
  }
  for (k = 0; k < m; ++k) {
    int d = 0;
    sufau(p[k], strlen(p[k]), d);
    for (i = 0; i < d; ++i) pi[i] = i;
    sort(pi, pi + d);
    for (i = d - 1; i > 0; --i) cnt[ggwp[pi[i]]] += cnt[pi[i]];
    for (i = 0; i < n; ++i) {
      int t = 0;
      bool in = true;
      for (j = i; j < n; ++j) {
        if (in) {
          if (to[t][s[j] - lc] == 0)
            in = false;
          else
            t = to[t][s[j] - lc];
        }
        int incnt = in ? cnt[t] : 0;
        if (v[i][j] && pl[k] <= incnt && incnt <= pr[k]) {
        } else
          v[i][j] = 0;
      }
    }
  }
  int ans = 0;
  for (i = 0; i < n; ++i)
    for (j = i; j < n; ++j) ans += (mxz[i] < j - i + 1) * v[i][j];
  cout << ans << endl;
  return 0;
}
