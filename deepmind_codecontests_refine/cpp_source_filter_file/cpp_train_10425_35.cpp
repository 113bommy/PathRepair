#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int i;
  int m = n / 2;
  for (i = 0; i < 4; i++) {
    if (x == m + dx[i] && y == n + dy[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
