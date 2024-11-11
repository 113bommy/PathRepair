#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, *Z;
  string s;
  long long sum = 0, mx = 0, mn = 0, t, x = 0;
  cin >> n;
  Z = new int[n];
  for (int i = 0; i < n; ++i) {
    cin >> Z[i];
    sum += Z[i];
  }
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'A') {
      x -= Z[i];
      if (x < mn) mn = x;
    } else {
      x += Z[i];
      if (x > mx) mx = x;
    }
  }
  if (mx - x > -mn)
    t = mx - x;
  else
    t = -mn;
  cout << (sum + x + 2 * t) / 2 << endl;
  return 0;
}
