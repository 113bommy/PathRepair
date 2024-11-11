#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 1e6 + 6, mod = 998244353, M = 1e7 + 7;
const long long MAX = 5e18;
int a, b, c, d;
deque<int> x[3];
int main() {
  cin >> a >> b >> c >> d;
  while (a && b) {
    x[0].push_back(0);
    x[0].push_back(1);
    a--, b--;
  }
  while (c && d) {
    x[2].push_back(2);
    x[2].push_back(3);
    c--, d--;
  }
  while (b && c) {
    x[1].push_back(2);
    x[1].push_back(1);
    b--, c--;
  }
  if (b) x[0].push_front(1), b--;
  if (c) x[2].push_back(2), c--;
  if (x[1].empty() && x[2].empty() && a) x[0].push_back(0), a--;
  if (x[0].empty() && x[1].empty() && d) x[2].push_front(3), d--;
  if (a || b || c || d)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < 3; i++) {
      for (int j : x[i]) printf("%d ", j);
    }
  }
  return 0;
}
