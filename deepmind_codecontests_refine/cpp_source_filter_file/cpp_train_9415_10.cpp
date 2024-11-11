#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n, d;
  int a[n];
  int p = 0, q = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[n];
    p += a[n] + 10;
    q = q + 10;
  }
  p = p - 10;
  q = q - 10;
  if (p == d)
    cout << q / 5;
  else if (p < d) {
    q = q / 5 + (d - p) % 5;
    cout << q;
  } else
    cout << "-1";
  return 0;
}
