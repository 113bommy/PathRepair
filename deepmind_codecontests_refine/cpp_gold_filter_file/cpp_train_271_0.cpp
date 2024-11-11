#include <bits/stdc++.h>
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
const long double eps = 1e-9;
const double PI = atan(1) * 4;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void in(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
long long twop(int x) { return 1LL << x; }
template <typename A, typename B>
inline void in(A &x, B &y) {
  in(x);
  in(y);
}
template <typename A, typename B, typename C>
inline void in(A &x, B &y, C &z) {
  in(x);
  in(y);
  in(z);
}
template <typename A, typename B, typename C, typename D>
inline void in(A &x, B &y, C &z, D &d) {
  in(x);
  in(y);
  in(z);
  in(d);
}
template <class T>
void upd(T &a, T b) {
  a = max(a, b);
}
const int maxn = 100010;
bitset<maxn> occ[26], ans;
char s[maxn], q[maxn];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  for (long long i = 0; i < len; i++) s[i] -= 'a';
  for (long long i = 0; i < len; i++) occ[s[i]][i] = 1;
  int _;
  in(_);
  while (_--) {
    int op;
    in(op);
    if (op == 1) {
      int pos;
      char c;
      in(pos);
      c = getchar() - 'a';
      pos--;
      occ[s[pos]][pos] = 0;
      s[pos] = c;
      occ[s[pos]][pos] = 1;
    } else {
      int l, r;
      in(l, r);
      scanf("%s", q);
      int qlen = strlen(q);
      if (qlen > r - l + 1) {
        puts("0");
      } else {
        l--;
        r--;
        r -= qlen;
        r++;
        ans.set();
        ans <<= maxn - 1 - r;
        ans >>= maxn - 1 - r + l;
        ans <<= l;
        for (int i = 0; i < qlen; i++) {
          ans &= occ[q[i] - 'a'] >> i;
        }
        printf("%lld\n", (long long)ans.count());
      }
    }
  }
  return 0;
}
