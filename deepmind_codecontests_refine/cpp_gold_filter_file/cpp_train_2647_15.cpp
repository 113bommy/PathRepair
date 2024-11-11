#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, xc = 1, yc = 1, t;
  vector<int> x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    x.push_back(t);
    cin >> t;
    y.push_back(t);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  for (int i = 0; i < n - 1; i++) {
    if (x[i] != x[i + 1]) xc++;
    if (y[i] != y[i + 1]) yc++;
  }
  cout << (xc < yc ? xc : yc);
}
