#include <bits/stdc++.h>
const int N = 1001000;
int t[N], s[N], n, m;
int cnt[N], co[2 * N];
int ans;
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
void check() {
  int L = 1, R = 1;
  int first = co[L], last = co[R];
  while (L <= n && R < 2 * n) {
    if (first == 0) {
      R = ++L;
      last = first = co[L];
      continue;
    }
    while (L <= n && R < 2 * n) {
      if (R - L + 1 > ans) ans = R - L + 1;
      ++R;
      if (co[R] == 0) {
        L = ++R;
        last = first = co[L];
        break;
      }
      if (first <= last) {
        if (co[R] > last)
          last = co[R];
        else if (co[R] < first)
          last = co[R];
        else {
          while (co[++L] < co[R])
            ;
          first = co[L];
          last = co[R];
        }
      } else {
        if (co[R] > last && co[R] < first)
          last = co[R];
        else if (last > co[R]) {
          while (1) {
            ++L;
            if (co[L] > co[R] && co[L] <= last) break;
          }
          first = co[L];
          last = co[R];
        } else if (co[R] > first) {
          while (1) {
            ++L;
            if (co[L] > co[R] || co[L] <= last) break;
          }
          first = co[L];
          last = co[R];
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    cnt[t[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", &s[i]);
    if (cnt[s[i]] != 0) co[cnt[s[i]] + n] = co[cnt[s[i]]] = i;
  }
  check();
  if (ans >= min(n, m)) ans = min(n, m);
  printf("%d\n", ans);
  scanf(" ");
}
