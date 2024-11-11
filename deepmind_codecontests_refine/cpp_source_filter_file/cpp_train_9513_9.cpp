#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const int INF = ~(1 << 31);
const double EPS = 1;
const double PI = 3.141592653589793;
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3 && n >= 5) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < m; i++) cout << i << ' ' << i * i + 1000 << '\n';
  for (int i = 0; i < n - m; i++) cout << i << ' ' << -i * i - 1000 << '\n';
  return 0;
}
