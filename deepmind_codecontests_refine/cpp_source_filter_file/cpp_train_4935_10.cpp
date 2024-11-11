#include <bits/stdc++.h>
using namespace std;
struct ii {
  int x, y;
  ii(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator<(const ii &a) const {
    if (x != a.x) return x < a.x;
    return y < a.y;
  }
  bool operator==(const ii &a) const { return x == a.x && y == a.y; }
  ii friend operator+(ii a, ii b) { return ii(a.x + b.x, a.y + b.y); }
  ii friend operator-(ii a, ii b) { return ii(a.x - b.x, a.y - b.y); }
};
template <class T>
void sc(T &x) {
  x = 0;
  char c;
  int f = 1;
  while (c = getchar(), c < 48)
    if (c == '-') f = -1;
  do x = x * 10 + (c ^ 48);
  while (c = getchar(), c > 47);
  x *= f;
}
template <class T>
void nt(T x) {
  if (!x) return;
  nt(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
void pt(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x)
    putchar('0');
  else
    nt(x);
}
template <class T>
void pts(T x) {
  pt(x);
  putchar(' ');
}
template <class T>
void ptn(T x) {
  pt(x);
  putchar('\n');
}
template <class v>
void pp(v x, int y) {
  static char ch[] = {" \n"};
  pt(x);
  putchar(ch[y]);
}
template <class T>
void PP(T *x, int y) {
  for (int i = 0, i_ = (y)-1; i <= i_; ++i) pp(x[i], i == y - 1);
}
template <class T>
void Max(T &x, T y) {
  if (x < y) x = y;
}
template <class T>
void Min(T &x, T y) {
  if (x > y) x = y;
}
int n, m, K;
char A[1000005], B[205];
unsigned long long S[205], T[1000005];
const unsigned long long H = 137;
int flag, Ans[2005], Tmp[2005];
void solve(int L) {
  for (int i = (n)-1, i_ = 0; i >= i_; --i) {
    T[i] = A[i];
    if (i + K < n) T[i] += H * T[i + K];
  }
  for (int i = (m)-1, i_ = 0; i >= i_; --i) {
    S[i] = B[i];
    if (i + L < m) S[i] += H * S[i + L];
  }
  int top = L;
  for (int i = (K)-1, i_ = 0; i >= i_; --i) {
    if (top && T[i] == S[top - 1]) {
      Tmp[i] = 1;
      top--;
    } else
      Tmp[i] = 0;
  }
  if (!top) {
    if (!flag) {
      flag = 1;
      memcpy(Ans, Tmp, K << 2);
    } else {
      bool ok = 0;
      for (int i = 0, i_ = (K)-1; i <= i_; ++i) {
        if (Ans[i] != Tmp[i]) {
          ok = Tmp[i] < Ans[i];
          break;
        }
      }
      if (ok) memcpy(Ans, Tmp, K << 2);
    }
  }
}
int main() {
  while (A[n] = getchar(), A[n] != '\n') n++;
  A[n] = 0;
  while (B[m] = getchar(), B[m] != '\n') m++;
  B[m] = 0;
  sc(K);
  n = strlen(A);
  m = strlen(B);
  int T = (n + K - 1) / K;
  if (n % K == 0) {
    if (m % T || K < m / T) return puts("0"), 0;
    solve(m / T);
  } else {
    for (int i = 1, i_ = (K + 1) - 1; i <= i_; ++i) {
      if ((T - 1) * i < m && m <= T * i) solve(i);
    }
  }
  if (!flag) return puts("0"), 0;
  for (int i = 0, i_ = (K)-1; i <= i_; ++i) pt(Ans[i]);
  puts("");
  return 0;
}
