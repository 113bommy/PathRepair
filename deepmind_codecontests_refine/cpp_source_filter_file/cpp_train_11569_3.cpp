#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void chkmin(T &a, T b) {
  if (a > b) a = b;
}
const double pi = 3.1415926535897932384626433832795028841971l;
int t, n, m;
bitset<2020> a[2020];
bitset<2020> c;
int id[2020];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) {
      scanf("%d%d", &u, &v);
      u--, v--;
      a[u][v] = a[v][u] = 1;
      c[u] = !c[u];
      c[v] = !c[v];
    }
    for (int i = 0; i < n; i++)
      if (c[i]) a[i][i] = 1;
    int j = 0;
    for (int i = 0; i < n; i++) {
      for (int k = j; k < n; k++)
        if (a[k][i]) {
          if (k != j) {
            swap(a[j], a[k]);
            bool x = c[j];
            c[j] = c[k];
            c[k] = x;
          }
          break;
        }
      if (!a[j][i]) continue;
      for (int k = 0; k < n; k++) {
        if (k == j || !a[k][i]) continue;
        a[k] ^= a[j];
        c[k] = c[k] ^ c[j];
      }
      id[j] = i;
      j++;
    }
    bitset<2000> ans;
    for (int k = 0; k < j; k++) ans[id[k]] = c[k];
    if (ans.any()) {
      cout << 2 << endl;
      for (int i = 0; i < n; i++) printf("%d ", ans[i] + 1);
      puts("");
    } else {
      cout << 1 << endl;
      for (int i = 0; i < n; i++) printf("%d ", 1);
      puts("");
    }
    c.reset();
    for (int i = 1; i <= n; i++) a[i].reset();
  }
  return 0;
}
