#include <bits/stdc++.h>
using namespace std;
vector<long long> a[27];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  if (n == 1) {
    cout << "0";
    return 0;
  } else {
    long long d = min(a, b);
    d = min(a, b) + (n - 2) * min(d, c);
    cout << d;
    return 0;
  }
}
