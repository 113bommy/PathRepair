#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  int mi = 1000000;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    mi = min(mi, (y - x + 1));
  }
  cout << mi + 1 << endl;
  for (int i = 0; i < n; i++) cout << i % mi << " ";
  cout << endl;
  return 0;
}
