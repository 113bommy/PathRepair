#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p1, p2, p3, a[n], b[n];
  int t1, t2, ans = 0, key = 0, sum = 0;
  cin >> p1 >> p2 >> p3 >> t1 >> t2;
  for (int i = 0; i < n; i++) {
    cin >> b[i] >> a[i];
    sum += b[i] - a[i];
  }
  for (int i = 1; i < n; i++) {
    key = a[i] - b[i - 1];
    if (key <= t1) {
      ans += p1 * key;
    }
    if (key > t1 && key <= (t2 + t1)) {
      ans += (key - t1) * p2 + p1 * t1;
    }
    if (key > (t2 + t1)) {
      ans += (key - (t1 + t2)) * p3 + p1 * t1 + p2 * t2;
    }
  }
  cout << (sum * p1) + ans;
  return 0;
}
