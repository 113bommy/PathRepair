#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, a[100100], x, y, mn = 1e9;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 101; i++) {
    int c = 0;
    for (int j = 1; j <= n; j++) {
      if (abs(a[j] - i) <= 1) continue;
      if (i > a[j]) {
        c += i - a[j] - 1;
      } else {
        c += a[j] - 1 - i;
      }
    }
    if (mn > c) {
      mn = c;
      x = i;
    }
  }
  cout << x << " " << mn;
  return 0;
}
