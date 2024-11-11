#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("02")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
using namespace std;
class complex {
 public:
  inline char gc() {
    static const int IN_LEN = 1 << 18 | 1;
    static char buf[IN_LEN], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, IN_LEN, stdin)),
           s == t ? -1 : *s++;
  }
  template <typename _Tp>
  __inline__ __attribute__((always_inline)) complex &operator>>(_Tp &x) {
    static char ch, sgn;
    ch = gc(), sgn = 0;
    for (; !isdigit(ch); ch = gc()) {
      if (ch == -1) return *this;
      sgn |= ch == '-';
    }
    for (x = 0; isdigit(ch); ch = gc()) x = x * 10 + (ch ^ '0');
    sgn && (x = -x);
    return *this;
  }
} inc;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  switch (n) {
    case 2:
      printf("1\n");
      break;
    case 3:
      printf("1  2\n2 11\n");
      break;
    case 4:
      printf("1  2  3\n2 10 12\3 12 21\n");
      break;
    case 5:
      printf("1  2  3  4\n2  4 11 13\n3 11 14 22\n4 13 22 31\n");
      break;
    case 6:
      printf(
          "1  2  3  4  5\n2  4 10 12 14\n3 10 13 20 23\n4 12 20 24 32\n5 14 23 "
          "32 41\n");
      break;
    case 7:
      printf(
          "1  2  3  4  5  6\n2  4  6 11 13 15\n3  6 12 15 21 24\n4 11 15 22 26 "
          "33\n5 13 21 26 34 42\n6 15 24 33 42 51\n");
      break;
    case 8:
      printf(
          "1  2  3  4  5  6  7\n2  4  6 10 12 14 16\n3  6 11 14 17 22 25\n4 10 "
          "14 20 24 30 34\n5 12 17 24 31 36 43\n6 14 22 30 36 44 52\n7 16 25 "
          "34 43 52 61\n");
      break;
    case 9:
      printf(
          "1  2   3  4  5  6  7  8\n2  4   6  8 11 13 15 17\n3  6  10 13 16 20 "
          "23 26\n4  8  13 17 22 26 31 35\n5  11 16 22 27 33 38 44\n6  13 20 "
          "26 33 40 46 53\n7  15 23 31 38 46 54 62\n8 17 26 35 44 53 62 71\n");
      break;
    case 10:
      printf(
          "1  2  3  4  5  6  7  8  9\n2  4  6  8 10 12 14 16 18\n3  6  9 12 15 "
          "18 21 24 27\n4  8 12 16 20 24 28 32 36\n5 10 15 20 25 30 35 40 "
          "45\n6 12 18 24 30 36 42 48 54\n7 14 21 28 35 42 49 56 63\n8 16 24 "
          "32 40 48 56 64 72\n9 18 27 36 45 54 63 72 81\n");
      break;
  }
  return 0;
}
