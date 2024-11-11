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
    if (x < 6 || y < 6 || x > n - 5 || y > m - 5) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
