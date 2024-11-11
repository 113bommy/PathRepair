#include <bits/stdc++.h>
using namespace std;
inline long long Readint() {
  long long ret = 0;
  int f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f *= -1;
  } while (ch >= 0 && (ch < '0' || ch > '9'));
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * f;
}
void open() {
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
}
void close() {
  fclose(stdin);
  fclose(stdout);
}
const int MAXN = 101010;
int n, m, q;
long long sb[MAXN];
int a[MAXN];
int b[MAXN];
long long A;
int t;
void init() {
  scanf("%d", &n), scanf("%d", &m), scanf("%d", &q);
  for (int i = (1), i_END_ = (n); i <= i_END_; i++) scanf("%d", &a[i]);
  for (int i = (1), i_END_ = (m); i <= i_END_; i++) scanf("%d", &b[i]);
  for (int i = (1), i_END_ = (n); i <= i_END_; i++)
    if (i & 1)
      sb[0] += b[i];
    else
      sb[0] -= b[i];
  for (int i = (n + 1), i_END_ = (m); i <= i_END_; i++) {
    sb[i - n] = sb[i - n - 1] - b[i - n];
    sb[i - n] = -sb[i - n];
    if (n & 1)
      sb[i - n] += b[i];
    else
      sb[i - n] -= b[i];
  }
  t = m - n;
  sort(sb, sb + 1 + t);
  t = unique(sb, sb + 1 + t) - sb - 1;
  for (int i = (1), i_END_ = (n); i <= i_END_; i++)
    if (i & 1)
      A += a[i];
    else
      A -= a[i];
}
long long check(int l, int r, long long num) {
  if (l == r) return labs(sb[l] - num);
  if (l + 1 == r) return min(labs(sb[l] - num), labs(sb[r] - num));
  int mid = (l + r) / 2;
  if (sb[mid] < num)
    return check(mid, r, num);
  else if (num < sb[mid])
    return check(l, mid, num);
  else
    return 0;
}
void work() {
  int x, y, d;
  long long T;
  cout << check(0, t, A) << endl;
  for (int i = (1), i_END_ = (q); i <= i_END_; i++) {
    scanf("%d", &x), scanf("%d", &y), scanf("%d", &d);
    if ((y - x + 1) % 2 == 0)
      T = A;
    else if (x & 1)
      T = A + d;
    else
      T = A - d;
    cout << check(0, t, T) << endl;
    A = T;
  }
}
int main() {
  int _ = 0;
  init();
  work();
  close();
  return 0;
}
