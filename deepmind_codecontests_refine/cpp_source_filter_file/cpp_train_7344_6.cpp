#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b, d, a[100002], m = 0, sum = 0;
  cin >> n >> b >> d;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    if (a[i] < b) {
      sum += a[i];
      if (sum > d) {
        m++;
        sum = 0;
      }
    }
  }
  cout << m;
  return 0;
}
