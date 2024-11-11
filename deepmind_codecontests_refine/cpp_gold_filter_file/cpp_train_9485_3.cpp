#include <bits/stdc++.h>
using namespace std;
namespace IO {
const int N = 2e5 + 10;
const int INF = ~0U >> 1;
template <typename T>
inline void read(T &x) {
  x = 0;
  T flag = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') flag = -1;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
  x *= flag;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
}  // namespace IO
using namespace IO;
int n, k, sum, now1, now2, val;
long long ans;
map<int, int> Map;
int main() {
  read(n, k);
  val = (1 << k) - 1;
  Map[0] = 1;
  for (int i = 1, x; i <= n; i++) {
    read(x);
    now1 = sum ^ x, now2 = now1 ^ val;
    if (Map[now1] < Map[now2])
      sum = now1, ans += Map[now1]++;
    else
      sum = now2, ans += Map[now2]++;
  }
  printf("%lld\n", ((long long)n * (n + 1)) / 2 - ans);
  return 0;
}
