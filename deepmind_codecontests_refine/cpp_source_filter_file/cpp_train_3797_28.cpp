#include <bits/stdc++.h>
using namespace std;
const size_t maxn = 51;
struct cnode {
  long a, b, c;
};
int lena, lenb, n;
int a[maxn], b[maxn];
long long markA[maxn][maxn], markB[maxn][maxn];
cnode g[maxn];
int f[maxn][maxn];
int init() {
  string sta, stb;
  cin >> sta >> stb;
  lena = sta.length();
  lenb = stb.length();
  for (int i = 0; i != lena; i++) a[i + 1] = sta[i] - 'a';
  for (int i = 0; i != lenb; i++) b[i + 1] = stb[i] - 'a';
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> sta;
    g[i].a = 1LL << (sta[0] - 'a');
    g[i].b = 1LL << (sta[3] - 'a');
    g[i].c = 1LL << (sta[4] - 'a');
  }
  return 0;
}
int prework() {
  memset(markA, 0, sizeof(markA));
  memset(markB, 0, sizeof(markB));
  for (int i = 1; i <= lena; i++) markA[i][i] |= 1LL << a[i];
  for (int c = 1; c != lena; c++)
    for (int i = 1; i + c <= lena; i++) {
      int j = i + c;
      for (int k = i; k != j; k++)
        for (int w = 1; w <= n; w++)
          if ((markA[i][k] & g[w].b) && (markA[k + 1][j] & g[w].c))
            markA[i][j] |= g[w].a;
    }
  for (int i = 1; i <= lenb; i++) markB[i][i] |= 1LL << a[i];
  for (int c = 1; c != lenb; c++)
    for (int i = 1; i + c <= lenb; i++) {
      int j = i + c;
      for (int k = i; k != j; k++)
        for (int w = 1; w <= n; w++)
          if ((markB[i][k] & g[w].b) && (markB[k + 1][j] & g[w].c))
            markB[i][j] |= g[w].a;
    }
  return 0;
}
int work() {
  memset(f, maxn, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= lena; i++)
    for (int j = 1; j <= lenb; j++)
      for (int a = 1; a <= i; a++)
        for (int b = 1; b <= j; b++)
          if (markA[a][i] & markB[b][j])
            f[i][j] = min(f[i][j], f[a - 1][b - 1] + 1);
  if (f[lena][lenb] >= maxn)
    cout << "-1" << endl;
  else
    cout << f[lena][lenb] << endl;
  cin >> f[0][0];
  return 0;
}
int main() {
  init();
  prework();
  work();
  return 0;
}
