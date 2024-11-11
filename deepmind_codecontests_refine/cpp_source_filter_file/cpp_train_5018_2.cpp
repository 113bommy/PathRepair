#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long t, a, b;
long long solve(long long a, long long b) {
  long long d = abs(a - b) / 5;
  a += d * 5;
  if (a == b) return d;
  if (abs(a - b) == 1) return d + 1;
  return d + 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << solve(min(a, b), max(a, b)) << endl;
  }
  return 0;
}
