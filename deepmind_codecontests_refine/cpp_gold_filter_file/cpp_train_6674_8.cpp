#include <bits/stdc++.h>
const int maxn = 500010;
int n, a[maxn * 2], stk[maxn * 4], pos[maxn], top, cur;
bool used[maxn], del[maxn];
int d_stk[maxn * 2];
int no() {
  while (used[cur]) cur++;
  used[cur] = 1;
  return cur;
}
bool deal(int l, int r) {
  if (r - l & 1) return 0;
  int *t = d_stk;
  for (int i = l; i <= r; i++) {
    *t++ = stk[i == r ? l : i];
    while (t - d_stk > 2 && a[t[-2]] &&
           ((!a[t[-1]]) != (!a[t[-3]]) || a[t[-1]] && a[t[-1]] == a[t[-3]])) {
      a[t[-1]] = a[t[-3]] |= a[t[-1]];
      del[a[t[-2]]] = 1;
      t -= 2;
    }
  }
  bool ex = 0;
  for (int *i = d_stk; i < t; i++)
    if (!a[*i]) ex = 1;
  if (!ex) return t - d_stk == 1;
  int v[2] = {no(), -1}, c = 0;
  for (int *i = d_stk, *j = i + 1; i < t - 1; j++) {
    for (; !a[*j]; j++)
      ;
    if (j - i++ & 1) {
      a[*i++] = v[c];
      if (v[c ^= 1] < 0)
        v[c] = no();
      else
        v[!c] = -1;
    }
    for (; i < j; i++) a[*i] = j - i & 1 ? v[c] : no();
  }
  for (int *i = d_stk + 1; i < t - 1; i++) del[a[*i]] = 1;
  return 1;
}
bool solve() {
  if (*a && a[n * 2 - 2] && *a != a[n * 2 - 2]) return 0;
  *a = a[n * 2 - 2] |= *a;
  for (int i = 1; i <= n; i++) pos[i] -= 1, used[i] = del[i] = 0;
  for (int i = 0; i < n * 2 - 2; i++) used[a[i]] = 1;
  top = 0;
  cur = 1;
  for (int i = 0; i < n * 2 - 2; i++) {
    if (a[i]) {
      if (del[a[i]]) return 0;
      if (pos[a[i]] > -1) {
        if (!deal(pos[a[i]], top)) return 0;
        top = pos[a[i]] + 1;
      } else
        pos[a[stk[top] = i]] = top, top++;
    } else
      stk[top++] = i;
  }
  int l = 0;
  while (l < top && !a[stk[l]]) stk[l + top] = stk[l], l++;
  if (l == top) l = 0, a[*stk] = no();
  if (!deal(l, l + top)) return 0;
  a[n * 2 - 2] = *a;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n * 2 - 1; i++) scanf("%d", a + i);
  if (solve()) {
    puts("yes");
    for (int i = 0; i < n * 2 - 1; i++)
      printf("%d%c", a[i], " \n"[i == n * 2 - 2]);
  } else
    puts("no");
}
