#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int main() {
  string type;
  const int N = 1e9;
  while (cin >> type) {
    if (type == "end") break;
    int d = 1;
    string s;
    while (d <= N) {
      printf("? %d %d\n", d - 1, d * 2 - 1);
      fflush(stdout);
      cin >> s;
      if (s == "x") {
        break;
      } else
        d *= 2;
    }
    int ans = 0;
    while (d) {
      printf("? %d %d\n", ans, ans + d);
      fflush(stdout);
      cin >> s;
      if (s == "y") ans += d;
      d >>= 1;
    }
    printf("! %d\n", ans);
    fflush(stdout);
  }
  return 0;
}
