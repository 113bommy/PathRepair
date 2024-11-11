#include <bits/stdc++.h>
using std::make_pair;
template <typename T>
inline T read() {
  T x = 0;
  char ch = std::getchar();
  bool f = 0;
  while (!std::isdigit(ch)) {
    f = (ch == '-');
    ch = std::getchar();
  }
  while (std::isdigit(ch)) {
    x = x * 10 + (ch - '0');
    ch = std::getchar();
  }
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) {
    x = -x;
    std::putchar('-');
  }
  if (x < 10) {
    std::putchar(x + 48);
    return;
  }
  print<T>(x / 10);
  std::putchar(x % 10 + 48);
  return;
}
namespace Solution {
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::map;
using std::pair;
using std::queue;
using std::set;
using std::vector;
const int N = 204001, mod = 1e9 + 7;
int n, a[N], b[N], ans[N];
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
void Fakemain() {
  std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
  srand(time(0));
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = i;
  for (int times = 0; times <= 201; ++times) {
    std::random_shuffle(b + 1, b + 1 + n);
    int g1 = 0, g2 = 0;
    for (int i = 1; i <= n; ++i)
      if (gcd(a[b[i]], g1) ^ g1)
        g1 = gcd(a[b[i]], g1), ans[b[i]] = 1;
      else
        g2 = gcd(a[b[i]], g2), ans[b[i]] = 2;
    if (g1 == 1 && g2 == 1) {
      cout << "YES\n";
      for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
      return;
    }
  }
  cout << "NO\n";
  return;
}
}  // namespace Solution
int main(int argc, char* argv[]) {
  Solution::Fakemain();
  return 0;
}
