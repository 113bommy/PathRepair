#include <bits/stdc++.h>
using namespace std;
queue<int> q[1100], an;
long long int m, n, a[1110000];
long long int sum;
int main() {
  cin >> m;
  for (int x = 1; x <= m; x++) {
    cin >> a[x];
    for (int y = 60; y >= 0; y--) {
      if ((a[x] & (1ll << y))) {
        q[y].push(x);
        break;
      }
    }
  }
  for (int x = 1; x <= m; x++) {
    int bj = 0;
    for (int y = 0; y <= 60; y++) {
      if (((sum & (1ll << y)) == 0) && !q[y].empty()) {
        an.push(q[y].front());
        sum ^= a[q[y].front()];
        q[y].pop();
        break;
      }
      if (y == 60) {
        bj = 1;
      }
    }
    if (bj == 1) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  while (!an.empty()) {
    cout << a[an.front()] << " ";
    an.pop();
  }
}
