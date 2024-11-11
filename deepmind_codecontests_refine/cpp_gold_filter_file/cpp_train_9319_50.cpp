#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[1001], b[1001];
int main() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) cin >> a[i];
  for (int i = (0); i < (n); i++) cin >> b[i];
  long long c, d, mx = 0;
  for (int i = (0); i < (n); i++) {
    c = a[i], d = b[i];
    mx = max(mx, c + d);
    for (int j = (i + 1); j < (n); j++) {
      c |= a[j];
      d |= b[j];
      mx = max(mx, c + d);
    }
  }
  cout << mx;
  return 0;
}
