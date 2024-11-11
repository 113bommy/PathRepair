#include <bits/stdc++.h>
using namespace std;
const long long N = 100100;
const long long Mod = 1e9 + 9;
char s[N];
long long add(long long x, long long y) { return (x + y + 10 * Mod) % Mod; }
void add_self(long long& x, long long y) { x = add(x, y); }
long long sub(long long x, long long y) { return (x - y + 10 * Mod) % Mod; }
void sub_self(long long& x, long long y) { x = sub(x, y); }
long long mul(long long x, long long y) { return x * y % Mod; }
void mul_self(long long& x, long long y) { x = mul(x, y); }
long long fp(long long x, long long y) {
  if (!y) return 1;
  long long Res = fp(x, y >> 1);
  mul_self(Res, Res);
  if (y & 1) mul_self(Res, x);
  return Res;
}
long long inv(long long y) { return fp(y, Mod - 2); }
long long inv(long long x, long long y) { return mul(x, inv(y)); }
long long Sum(long long q, long long m) {
  if (q == 1) return m;
  return inv(sub(fp(q, m + 1), 1), sub(q, 1));
}
int main() {
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  scanf("%s", s);
  long long A = fp(a, n);
  long long q = inv(b, a);
  long long base = fp(q, k);
  long long m = (n + 1) / k;
  long long Ans = 0;
  for (long long i = 0; i < k; i++) {
    long long staff = fp(q, i);
    long long whatever = mul(staff, Sum(base, m - 1));
    s[i] == '+' ? add_self(Ans, whatever) : sub_self(Ans, whatever);
  }
  mul_self(Ans, A);
  cout << Ans;
}
