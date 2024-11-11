#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932384626433832795;
double eps = 1e-9;
char ch[2 << 20];
inline string gs() {
  scanf("%s", ch);
  return string(ch);
}
inline string gl() {
  gets(ch);
  return string(ch);
}
inline int gi() {
  int x;
  scanf("%d", &x);
  return x;
}
void error() {
  int ttt = 0;
  cout << 7 / ttt;
}
long long gcd(long long a, long long b) {
  if (!a && !b) return 0;
  if (!b) return a;
  return (!a) ? b : gcd(b % a, a);
}
int mod = 1000 * 1000 * 1000 + 7;
inline int MUL(int a, int b) { return 1ll * a * b % mod; }
inline int ADD(int a, int b) { return (a + b >= mod) ? a + b - mod : a + b; }
inline int SUB(int a, int b) { return (a - b < 0) ? a + mod - b : a - b; }
int main() {
  int a, b, mod;
  a = gi();
  b = gi();
  mod = gi();
  int m = 1;
  for (int i = (0), _b(9); i < _b; ++i) {
    m = 1ll * m * 10ll % (long long)mod;
  }
  int l = 100000000;
  int g = 0;
  for (int x = (0), _b(a + 1); x < _b; ++x) {
    if (g == 0) {
      if (x != 0) break;
    } else {
      if (mod - g > b) {
        printf("1 %09d\n", x);
        return 0;
      }
    }
    g += m;
    if (g >= mod) g -= mod;
  }
  printf("2\n");
  return 0;
}
