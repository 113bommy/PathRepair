#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  x *= f;
}
int n, a[110], hs[110], ss[110];
set<int> f[10010];
bool pd(int m, int kk) {
  f[0].insert(0);
  for (int i = 1; i <= 100; ++i)
    for (int k = 1; k <= hs[i]; ++k)
      for (int j = m; j >= i; --j) {
        for (set<int>::iterator it = f[j - i].begin(); it != f[j - i].end();
             ++it)
          f[j].insert(1 + (*it));
      }
  int rt = 0;
  if (f[m].find(kk) == f[m].end()) rt = 1;
  for (int i = 0; i <= m; ++i) f[i].clear();
  return rt;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]), ++hs[a[i]];
  int ans = 1, zl = 0;
  for (int i = 1; i <= 100; ++i) {
    if (a[i] > ans) {
      for (int j = ans + 1; j <= hs[i]; ++j) {
        int sv = hs[i];
        hs[i] = j - 1;
        if (pd(j * i, j)) ++ans;
        hs[i] = sv;
      }
    }
    if (a[i]) ++zl;
  }
  if (zl == 2) ans = n;
  cout << ans << endl;
  return 0;
}
