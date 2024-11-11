#include <bits/stdc++.h>
using namespace std;
void solve(int tc = 0) {
  long long int a, b, c, m;
  cin >> a >> b >> c >> m;
  long long int max_m = (a - 1) + (b - 1) + (c - 1);
  long long int sum = a + b + c;
  long long int min_m = max(a, max(b, c)) - (sum - (max(a, max(b, c))));
  min_m = max(min_m, (long long int)0);
  if (m >= min_m and m <= max_m)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve(t);
  }
  return 0;
}
