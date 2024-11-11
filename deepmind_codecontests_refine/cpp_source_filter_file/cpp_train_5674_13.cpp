#include <bits/stdc++.h>
using namespace std;
int d[100], y;
int main() {
  int n, m, x;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a = 0, b = 0;
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x > a) {
        a = x;
        b = j;
      }
    }
    d[b]++;
  }
  for (int i = 0; i < m; i++) {
    if (d[i] > d[y]) {
      y = i;
    }
  }
  cout << y + 1 << endl;
}
