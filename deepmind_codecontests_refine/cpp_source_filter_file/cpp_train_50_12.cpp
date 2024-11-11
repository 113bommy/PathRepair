#include <bits/stdc++.h>
using namespace std;
int main() {
  int long n, m, x, y;
  cin >> n >> m;
  map<int, int> a;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    for (int j = 1; j <= x; ++j) {
      cin >> y;
      a[y] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != 1) return cout << "NO", 0;
  }
  cout << "YES";
  return 0;
}
