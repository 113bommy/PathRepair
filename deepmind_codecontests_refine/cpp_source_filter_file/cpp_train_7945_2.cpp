#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0, le, lo, u, sum = 0;
  cin >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) {
    r = 0, le = 0, lo = 0, u = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        if (y[j] == y[i] && x[j] > x[i])
          r++;
        else if (y[j] == y[i] && x[j] < x[i])
          le++;
        else if (y[j] < y[i] && x[j] == x[i])
          lo++;
        else if (y[j] > y[i] && x[j] == x[i])
          u++;
      }
    }
    sum += min(min(r, u), min(lo, le));
  }
  cout << sum << endl;
}
