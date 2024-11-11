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
int n, t, a, b;
char c[N];
void Fakemain() {
  t = read<int>();
  while (t--) {
    a = read<int>(), b = read<int>();
    scanf("%s", c + 1);
    vector<pair<int, int> > s;
    s.clear();
    int lst = 0;
    n = strlen(c + 1);
    for (int i = 1; i <= n; ++i) {
      if (c[i] == '0') {
        if (c[i - 1] == '1') s.push_back(make_pair(lst + 1, i - 1));
        lst = i;
      }
    }
    if (lst != n) s.push_back(make_pair(lst + 1, n));
    lst = 0;
    int ans = 0, now = 0;
    if (s.size() == 0) {
      print<int>(0), putchar('\n');
      continue;
    }
    for (int i = 1; i < (int)s.size(); ++i) {
      if ((s[i].first - s[i - 1].second - 1) * b <= a) {
        now += s[i].first - s[i - 1].second - 1;
      } else {
        ans += a + b * now;
        now = 0;
      }
    }
    ans += a + b * now;
    print<int>(ans), putchar('\n');
  }
  return;
}
}  // namespace Solution
int main(int argc, char* argv[]) {
  Solution::Fakemain();
  return 0;
}
