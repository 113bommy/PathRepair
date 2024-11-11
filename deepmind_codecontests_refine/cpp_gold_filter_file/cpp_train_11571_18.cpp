#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v, cost = 0;
  cin >> n >> v;
  int d = n - 1;
  if (d <= v) {
    cout << d << endl;
  } else {
    cost = cost + v;
    for (int i = 2; i <= n; i++) {
      if (i + v == n) {
        cost = cost + i * 1;
        break;
      } else {
        cost = cost + i * 1;
      }
    }
    cout << cost << endl;
  }
}
