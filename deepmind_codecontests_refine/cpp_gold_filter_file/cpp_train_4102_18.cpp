#include <bits/stdc++.h>
class Input {
 private:
  char buf[1000000], *p1, *p2;

 public:
  inline char getc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin);
    return p1 == p2 ? EOF : *(p1++);
  }
  template <typename tp>
  inline Input& operator>>(tp& n) {
    n = 0;
    char c = getc();
    while (!isdigit(c)) c = getc();
    while (isdigit(c)) n = n * 10 + c - 48, c = getc();
    return (*this);
  }
} fin;
const int N = 1e6 + 5, mod = 1e9 + 7;
using namespace std;
int n, m;
int f[N];
int main() {
  fin >> n;
  for (int i = 1, x; i <= n; ++i) fin >> x, m += (x == 1);
  f[0] = f[1] = 1;
  for (int i = 1; i <= m; ++i)
    f[i] = (f[i - 1] + 1ll * f[i - 2] * (i - 1) % mod) % mod;
  long long mul = 1;
  for (int i = 0; i < n - m; ++i) mul = mul * (n - i) % mod;
  cout << mul * f[m] % mod << endl;
  return 0;
}
