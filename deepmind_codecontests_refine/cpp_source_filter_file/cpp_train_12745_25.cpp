#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, t;
  cin >> n >> c >> t;
  if (c - t >= 1) {
    if (c - t > 1) cout << "<< ";
    for (int i = c - t; i < c; i++) cout << i << " ";
  }
  {
    for (int i = 1; i < c; i++) cout << i << " ";
  }
  cout << "(" << c << ")"
       << " ";
  if (c + t >= n) {
    for (int i = c + 1; i <= n; i++) cout << i << " ";
  } else {
    for (int i = c + 1; i <= c + t; i++) {
      cout << i << " ";
    }
    cout << ">>";
  }
}
