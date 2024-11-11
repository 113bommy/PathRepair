#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
  int i, x, y, j;
  cout << "YES\n";
  cin >> N;
  for (i = 1; i <= N; i++) {
    cin >> x >> y >> j >> j;
    cout << (1 + (x & 2) * 2 + (y & 2)) << "\n";
  }
  return 0;
}
