#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000, Ha = 1e9 + 7;
int n, a[maxn + 5];
unsigned long long px[maxn * 4 + 5], A[maxn * 4 + 5], B[maxn * 4 + 5];
inline char readc() {
  static char buf[100000], *l = buf, *r = buf;
  if (l == r) r = (l = buf) + fread(buf, 1, 100000, stdin);
  if (l == r) return EOF;
  return *l++;
}
inline int readi(int &x) {
  int tot = 0, f = 1;
  char ch = readc(), lst = '+';
  while ('9' < ch || ch < '0') {
    if (ch == EOF) return EOF;
    lst = ch;
    ch = readc();
  }
  if (lst == '-') f = -f;
  while ('0' <= ch && ch <= '9')
    tot = (tot << 3) + (tot << 1) + ch - 48, ch = readc();
  return x = tot * f, ((ch) == 10 || (ch) == 13 || (ch) == EOF);
}
inline void Pushup(int p, int l, int r) {
  A[p] = A[p << 1] * px[r] + A[p << 1 | 1];
  B[p] = B[p << 1] + B[p << 1 | 1] * px[l];
}
void Update(int pos, int l = 1, int r = n, int p = 1) {
  if (pos < l || r < pos) return;
  if (l == r) {
    A[p] = B[p] = 1;
    return;
  }
  int mid = l + (r - l >> 1);
  Update(pos, l, mid, p << 1);
  Update(pos, mid + 1, r, p << 1 | 1);
  Pushup(p, mid - l + 1, r - mid);
}
pair<unsigned long long, int> Ask_A(int L, int R, int l = 1, int r = n,
                                    int p = 1) {
  if (R < l || r < L) return make_pair(0, 0);
  if (L <= l && r <= R) return make_pair(A[p], r - l + 1);
  int mid = l + (r - l >> 1);
  pair<unsigned long long, int> a = Ask_A(L, R, l, mid, p << 1),
                                b = Ask_A(L, R, mid + 1, r, p << 1 | 1);
  return make_pair(a.first * px[b.second] + b.first, a.second + b.second);
}
pair<unsigned long long, int> Ask_B(int L, int R, int l = 1, int r = n,
                                    int p = 1) {
  if (R < l || r < L) return make_pair(0, 0);
  if (L <= l && r <= R) return make_pair(B[p], r - l + 1);
  int mid = l + (r - l >> 1);
  pair<unsigned long long, int> a = Ask_B(L, R, l, mid, p << 1),
                                b = Ask_B(L, R, mid + 1, r, p << 1 | 1);
  return make_pair(a.first + b.first * px[a.second], a.second + b.second);
}
int main() {
  readi(n);
  for (int i = 1; i <= n; i++) readi(a[i]);
  px[0] = 1;
  for (int i = 1; i <= n; i++) px[i] = px[i - 1] * 2;
  for (int i = 1; i <= n; i++) {
    int k = min(a[i] - 1, n - a[i]);
    if (Ask_A(a[i] - k, a[i]).first != Ask_B(a[i], a[i] + k).first)
      return printf("NO\n"), 0;
    Update(a[i]);
  }
  return printf("YES\n"), 0;
}
