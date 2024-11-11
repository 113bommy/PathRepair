#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int M = 2000005;
int n, x, a[M], b[M];
int mn[M], mx[M], t[M];
void init() {
  for (int i = (int)(2); i <= (int)(M - 1); i++)
    if (!mn[i])
      for (int j = (int)(1); j <= (int)((M - 1) / i); j++)
        if (!mn[i * j]) mn[i * j] = i;
}
void insert(int x) {
  b[++*b] = x;
  for (; x != 1;) {
    int v = mn[x], s = 0;
    for (; x % v == 0; x /= v, ++s)
      ;
    if (s > mx[v])
      mx[v] = s, t[v] = 1;
    else if (s == mx[v])
      t[v]++;
  }
}
bool check(int x) {
  for (; x != 1;) {
    int v = mn[x], s = 0;
    for (; x % v == 0; x /= v, ++s)
      ;
    if (t[v] == 1 && s == mx[v]) return 0;
  }
  return 1;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &x), ++a[x];
  for (int i = (int)(1); i <= (int)(M - 1); i++)
    if (a[i] >= 2) insert(i), insert(i - 1);
  for (int i = (int)(M - 1); i >= (int)(1); i--)
    if (a[i] == 1) insert(i - (mx[i] != 0));
  int ans1 = 1, ans2 = 0;
  for (int i = (int)(1); i <= (int)(M - 1); i++)
    for (int j = (int)(1); j <= (int)(mx[i]); j++) ans1 = 1ll * ans1 * i % mo;
  for (int i = (int)(2); i <= (int)(M - 1); i++)
    if (a[i] >= 3 - (i == 2)) ans2 = 1;
  for (int i = (int)(1); i <= (int)(*b); i++)
    if (check(b[i])) ans2 = 1;
  printf("%d\n", (ans1 + ans2) % mo);
}
