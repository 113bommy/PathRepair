#include <bits/stdc++.h>
template <typename Tp>
Tp Max(const Tp &a, const Tp &b) {
  return a > b ? a : b;
}
template <typename Tp>
Tp Min(const Tp &a, const Tp &b) {
  return a < b ? a : b;
}
template <typename Tp>
Tp Abs(const Tp &a) {
  return a > 0 ? a : -a;
}
template <typename Tp>
void Read(Tp &x) {
  Tp in = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    in = in * 10 + ch - '0';
    ch = getchar();
  }
  x = in * f;
}
const int SN = 100000 + 10;
long long a[SN], pos[SN], sta[SN], top, tot, n;
long long left[SN], right[SN], d[SN];
int L, R;
void Answer() {
  top = 0;
  right[pos[1]] = pos[tot];
  sta[++top] = pos[1];
  for (int i = 2; i <= tot; i++) {
    while (top && d[pos[i]] >= d[sta[top]]) right[sta[top--]] = pos[i] - 1;
    sta[++top] = pos[i], right[pos[i]] = pos[tot];
  }
  top = 0;
  left[pos[tot]] = pos[1];
  sta[++top] = pos[tot];
  for (int i = tot - 1; i >= 1; i--) {
    while (top && d[pos[i]] >= d[sta[top]]) left[sta[top--]] = pos[i] + 1;
    sta[++top] = pos[i], left[pos[i]] = pos[1];
  }
  long long ans = 0;
  for (int i = L; i < R; i++) {
    ans = (ans + d[i] * (i - left[i] + 1) * (right[i] - i + 1));
  }
  printf("%I64d\n", ans);
}
int main() {
  int q;
  Read(n), Read(q);
  for (int i = 1; i <= n; i++) Read(a[i]);
  for (int i = 1; i < n; i++) d[i] = Abs(a[i] - a[i + 1]);
  while (q--) {
    Read(L), Read(R);
    tot = 0;
    for (int i = L; i < R; i++) pos[++tot] = i;
    pos[tot + 1] = 0;
    Answer();
  }
  return 0;
}
