#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
namespace FastIO {
char print_f[105];
void read() {}
void print() { putchar('\n'); }
template <typename T, typename... T2>
inline void read(T &x, T2 &...oth) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
  read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth) {
  long long p3 = -1;
  if (x < 0) putchar('-'), x = -x;
  do {
    print_f[++p3] = x % 10 + 48;
  } while (x /= 10);
  while (p3 >= 0) putchar(print_f[p3--]);
  putchar(' ');
  print(oth...);
}
}  // namespace FastIO
using FastIO::print;
using FastIO::read;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int main() {
  int n, s;
  read(n, s);
  if (n - 1 < s - (n - 1) - 1) {
    puts("YES");
    for (int i = 1; i <= n - 1; i++) cout << "1 ";
    cout << s - (n - 1) << "\n";
    cout << n << "\n";
  } else
    puts("NO");
  return 0;
}
