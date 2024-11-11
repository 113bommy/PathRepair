#include <bits/stdc++.h>
using namespace std;
inline int Gcd(int X, int Y) { return Y ? Gcd(Y, X % Y) : X; }
inline long long Gcd(long long X, long long Y) { return Y ? Gcd(Y, X % Y) : X; }
inline int Pow(int base, long long exp, int _mod) {
  if (!(base %= _mod)) return 0;
  int _ans = 1;
  for (; exp; exp >>= 1, base = (long long)base * base % _mod)
    exp& 1 ? _ans = (long long)_ans * base % _mod : 0;
  return _ans;
}
inline long long Pow(long long base, long long exp, long long _mod) {
  if (!(base %= _mod)) return 0;
  long long _ans = 1;
  for (; exp; exp >>= 1, base = base * base % _mod)
    exp& 1 ? _ans = _ans * base % _mod : 0;
  return _ans;
}
const int INF = 0x3f3f3f3f;
int c[20];
long long f(long long x) {
  if (x <= 0) return 0;
  long long xx = x;
  int len = 0;
  while (xx) c[++len] = xx % 10, xx /= 10;
  long long Ans[5], s;
  Ans[0] = Ans[1] = Ans[2] = Ans[3] = 0;
  s = 0;
  for (int i = len; i >= 1; --i) {
    Ans[3] = Ans[3] + Ans[2] * 9;
    Ans[2] = Ans[2] + Ans[1] * 9;
    Ans[1] = Ans[1] + Ans[0] * 9;
    if (c[i]) {
      if (s <= 3) ++Ans[s], Ans[s + 1] += c[i] - 1;
      ++s;
    }
  }
  return Ans[1] + Ans[2] + Ans[3] + (s <= 3);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int L, R;
    scanf("%lld%lld", &L, &R);
    printf("%lld\n", f(R) - f(L - 1));
  }
  return 0;
}
