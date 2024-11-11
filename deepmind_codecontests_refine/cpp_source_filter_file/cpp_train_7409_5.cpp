#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, a[2004], n;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      int t = (a[i - 1] - a[i]) / d;
      a[i] += (t + 1) * d;
      res += t + 1;
    }
  }
  cout << res;
}
