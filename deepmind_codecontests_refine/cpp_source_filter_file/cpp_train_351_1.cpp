#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, y = 0, mx = -2, t;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    y += x;
    mx = max(x, mx);
  }
  n--;
  t = y / n + (y % n != 0);
  t = max(t, mx);
  cout << t << endl;
}
