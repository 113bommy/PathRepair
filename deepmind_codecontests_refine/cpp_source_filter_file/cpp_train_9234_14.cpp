#include <bits/stdc++.h>
using namespace std;
int main() {
  float vb, vs, x, y, time = 1000000.0, t;
  int n;
  cin >> n >> vb >> vs;
  int i, ans;
  float arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  cin >> x >> y;
  for (i = 1; i < n; i++) {
    t = ((arr[i] - arr[0]) / vb) +
        (sqrt(pow((x - arr[i]), 2) + pow(y, 2)) / vs);
    if (t < time) {
      time = t;
      ans = i + 1;
    }
  }
  cout << ans;
  return 0;
}
