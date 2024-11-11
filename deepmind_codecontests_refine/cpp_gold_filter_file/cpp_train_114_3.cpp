#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5200 + 15;
const int INF = 0x3f3f3f3f;
inline void rdInt(int &x) { scanf("%d", &x); }
inline void ptInt(int x) { printf("%d", x); }
inline void ptInts(int x, char c) { printf("%d%c", x, c); }
inline void rdStr(char *x) { scanf("%s", x); }
inline void ptStr(char *x) { printf("%s\n", x); }
inline void rdLL(long long &x) { scanf("%lld", &x); }
inline void ptLL(long long x) { printf("%lld", x); }
inline bool strEq(char *x, char *y) { return strcmp(x, y) == 0; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
bool a[MAXN][MAXN];
int stk[MAXN];
char s[MAXN][MAXN >> 1];
int n, m;
void seta(bool *Ary, bool _1, bool _2, bool _3, bool _4) {
  Ary[0] = _1;
  Ary[1] = _2;
  Ary[2] = _3;
  Ary[3] = _4;
}
void conv(bool *Ary, char c) {
  switch (c) {
    case '0':
      seta(Ary, 0, 0, 0, 0);
      break;
    case '1':
      seta(Ary, 0, 0, 0, 1);
      break;
    case '2':
      seta(Ary, 0, 0, 1, 0);
      break;
    case '3':
      seta(Ary, 0, 0, 1, 1);
      break;
    case '4':
      seta(Ary, 0, 1, 0, 0);
      break;
    case '5':
      seta(Ary, 0, 1, 0, 1);
      break;
    case '6':
      seta(Ary, 0, 1, 1, 0);
      break;
    case '7':
      seta(Ary, 0, 1, 1, 1);
      break;
    case '8':
      seta(Ary, 1, 0, 0, 0);
      break;
    case '9':
      seta(Ary, 1, 0, 0, 1);
      break;
    case 'A':
      seta(Ary, 1, 0, 1, 0);
      break;
    case 'B':
      seta(Ary, 1, 0, 1, 1);
      break;
    case 'C':
      seta(Ary, 1, 1, 0, 0);
      break;
    case 'D':
      seta(Ary, 1, 1, 0, 1);
      break;
    case 'E':
      seta(Ary, 1, 1, 1, 0);
      break;
    case 'F':
      seta(Ary, 1, 1, 1, 1);
      break;
    default:
      ptStr("Oops.");
  }
}
void calstk(int &res) {
  int tmp = stk[1];
  for (int i = (1); i <= (*stk); i++) tmp = gcd(tmp, stk[i]);
  res = res ? gcd(res, tmp) : tmp;
}
int main() {
  rdInt(n);
  m = n >> 2;
  for (int i = (0); i < (n); i++) rdStr(s[i]);
  if (n == 1) {
    return puts("1");
  } else if (n == 2) {
    if (s[0][0] == '3' && s[1][0] == '3') return puts("2");
    if (s[0][0] == '0' && s[1][0] == '0') return puts("2");
    return puts("1");
  } else if (n == 3) {
    if (s[0][0] == '8' && s[1][0] == '8' && s[2][0] == '8') return puts("3");
    if (s[0][0] == '0' && s[1][0] == '0' && s[2][0] == '0') return puts("3");
    return puts("1");
  }
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) {
      conv(a[i] + j * 4, s[i][j]);
    }
  int ans = 0;
  for (int i = (0); i < (n); i++) {
    int num = 0;
    stk[0] = 0;
    bool cur = a[i][0];
    for (int j = (0); j <= (n); j++) {
      if (cur == a[i][j] && j < n) {
        num++;
      } else {
        cur ^= 1;
        stk[++*stk] = num;
        num = 1;
      }
    }
    calstk(ans);
  }
  if (ans == 1) {
    ptInt(1);
    return 0;
  }
  for (int i = (0); i < (n); i++) {
    int num = 0;
    stk[0] = 0;
    bool cur = a[0][i];
    for (int j = (0); j <= (n); j++) {
      if (cur == a[j][i] && j < n) {
        num++;
      } else {
        cur ^= 1;
        stk[++*stk] = num;
        num = 1;
      }
    }
    calstk(ans);
  }
  ptInt(ans);
  return 0;
}
