#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, mx;
  mx = INT_MIN;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < 0) {
      mx = max(mx, x);
    } else {
      if ((int)sqrt(x) * (int)sqrt(x) != x) mx = max(mx, x);
    }
  }
  cout << mx << endl;
}
