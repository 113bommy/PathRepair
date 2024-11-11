#include <bits/stdc++.h>
using namespace std;
namespace io {
const int L = (1 << 20) + 1;
char buf[L], *S, *T, c;
char getchar() {
  if (S == T) {
    T = (S = buf) + fread(buf, 1, L, stdin);
    return (S == T ? EOF : *S++);
  }
  return *S++;
}
int inp() {
  int x = 0, f = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * f;
}
long long inp_ll() {
  long long x = 0;
  int f = 1;
  char ch;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  return x * f;
}
char B[25], *outs = B + 20, *outr = B + 20;
template <class T>
inline void print(register T a, register char x = 0) {
  if (x) *--outs = x, x = 0;
  if (!a)
    *--outs = '0';
  else
    while (a) *--outs = (a % 10) + 48, a /= 10;
  if (x) *--outs = x;
  fwrite(outs, outr - outs, 1, stdout);
  outs = outr;
}
};  // namespace io
using io ::inp;
using io ::inp_ll;
using io ::print;
const int MAXN = 300010;
const long long INF = 1000000000000000000LL;
int f[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292, 341};
int main() {
  long long n;
  cin >> n;
  if (n <= 12)
    cout << f[n] << endl;
  else
    cout << f[12] + 49LL * (n - 12) << endl;
  return 0;
}
