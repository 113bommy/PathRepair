#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long x, a = INT_MIN, b = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > a) a = x;
    if (x < b) b = x;
  }
  long ans = a - b + 1 - n;
  cout << ans;
}
