#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, sum = 0, x, ans = 5;
  cin >> n >> d;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
    sum += a[i];
  }
  ans += ((n - 1) * 10);
  if (ans <= d) {
    cout << (d - sum) / 5 << endl;
  } else
    cout << "-1" << endl;
}
