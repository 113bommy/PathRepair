#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int N = 200005, M = 2000000;
int n, a[N], b[N], cnt[M + 5];
int mn[M + 5], mx[M + 5], t[M + 5];
void init() {
  for (int i = (int)(0); i <= (int)(M + 2); i++) mn[i] = 233333333;
  for (int i = (int)(2); i <= (int)(M); i++)
    for (int j = (int)(1); j <= (int)(M / i); j++)
      mn[i * j] = min(mn[i * j], i);
}
void insert(int v) {
  b[++*b] = v;
  for (; v != 1;) {
    int p = mn[v], cnt = 0;
    for (; v % p == 0; v /= p, cnt++)
      ;
    if (cnt > mx[p])
      mx[p] = cnt, t[p] = 0;
    else if (cnt == mx[p])
      t[p]++;
  }
}
bool check(int v) {
  for (; v != 1;) {
    int p = mn[v], cnt = 0;
    for (; v % p == 0; v /= p, cnt++)
      ;
    if (cnt == mx[p] && t[p] == 1) return 0;
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  init();
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]), cnt[a[i]]++;
  for (int i = (int)(1); i <= (int)(M); i++)
    if (cnt[i] >= 2) insert(i), insert(i - 1);
  for (int i = (int)(M); i >= (int)(1); i--)
    if (cnt[i] == 1)
      if (mx[i])
        insert(i - 1);
      else
        insert(i);
  int ans = 1, ans2 = 0;
  for (int i = (int)(1); i <= (int)(M); i++)
    for (int j = (int)(1); j <= (int)(mx[i]); j++) ans = 1ll * ans * i % mo;
  for (int i = (int)(1); i <= (int)(M); i++)
    if (cnt[i] >= 3 - (i == 2)) ans2 = 1;
  for (int i = (int)(1); i <= (int)(*b); i++)
    if (check(b[i])) ans2 = 1;
  printf("%d\n", (ans + ans2) % mo);
}
