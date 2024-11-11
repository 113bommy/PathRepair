#include <bits/stdc++.h>
using namespace std;
long long mod(long long a) {
  return ((a % 1000000009LL) + 1000000009LL) % 1000000009LL;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long f = 1;
  for (int i = 0; i < m; ++i) f = (f * m) % 1000000009LL;
  f = mod(f - 1);
  long long rsp = 1LL;
  for (int i = 0; i < n; ++i) rsp = (rsp * f) % 1000000009LL, f = mod(f - 1);
  cout << rsp << endl;
  return 0;
}
