#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int n_ = 1e5 + 5;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    if (x < 3 || y < 3 || x > n - 2 || y > m - 2) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
