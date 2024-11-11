#include <bits/stdc++.h>
using namespace std;
typedef int arr[110];
int pp = 10000;
int N, x, y, l, r, pt, fa[710], q[710], Max[710];
arr ans, t;
arr ff[710];
arr f[710][710];
int ne[1500], st[710], go[1500];
void Multi(arr a, arr b, arr &c) {
  memset(c, 0, sizeof(c));
  for (int i = 1; i <= a[0]; i++)
    for (int j = 1; j <= b[0]; j++) {
      c[i + j - 1] += a[i] * b[j];
      if (c[i + j - 1] >= pp) {
        c[i + j] += c[i + j - 1] / pp;
        c[i + j - 1] = c[i + j - 1] % pp;
      }
    }
  c[0] = a[0] + b[0] - 1;
  if (c[c[0] + 1]) c[0]++;
}
void Multi2(arr &a, int u) {
  int x = 0;
  for (int i = 1; i <= a[0]; i++) {
    x = x + a[i] * u;
    a[i] = x % pp;
    x = x / pp;
  }
  if (x) a[++a[0]] = x;
}
bool big(arr a, arr b) {
  if (a[0] > b[0]) return true;
  if (a[0] < b[0]) return false;
  for (int i = a[0]; i; i--) {
    if (a[i] > b[i]) return true;
    if (a[i] < b[i]) return false;
  }
  return false;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    scanf("%d%d", &x, &y);
    ne[++pt] = st[x];
    st[x] = pt;
    go[pt] = y;
    ne[++pt] = st[y];
    st[y] = pt;
    go[pt] = x;
  }
  q[l = r = 0] = 1;
  for (; l <= r; l++) {
    int x = q[l];
    for (int i = st[x]; i; i = ne[i])
      if (fa[x] != go[i]) {
        q[++r] = go[i];
        fa[go[i]] = x;
      }
  }
  for (int i = 1; i <= N; i++) Max[i] = 1;
  for (int i = 1; i <= N; i++) {
    f[i][1][0] = 1;
    f[i][1][1] = 1;
  }
  for (int i = r; i; i--) {
    int x = q[i];
    memcpy(ff, f[fa[x]], sizeof(ff));
    for (int j = 1; j <= Max[fa[x]]; j++)
      for (int i = 1; i <= Max[x]; i++) {
        Multi(ff[j], f[x][i], t);
        if (big(t, f[fa[x]][j + i]))
          memcpy(f[fa[x]][j + i], t, sizeof(f[fa[x]][j + i]));
        Multi2(t, i);
        if (big(t, f[fa[x]][j])) memcpy(f[fa[x]][j], t, sizeof(f[fa[x]][j]));
      }
    Max[fa[x]] += Max[x];
  }
  ans[0] = 0;
  for (int i = 1; i <= Max[1]; i++) {
    memcpy(t, f[1][i], sizeof(t));
    Multi2(t, i);
    if (big(t, ans)) memcpy(ans, t, sizeof(ans));
  }
  printf("%d", ans[ans[0]]);
  for (int i = ans[0] - 1; i > 0; i--) printf("%04d", ans[i]);
}
