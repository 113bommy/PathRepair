#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  long long n;
  cin >> n;
  long long t;
  cin >> t;
  vector<int> v(n);
  int ans = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    ans += ceil(1.0 * v[i] / t * 1.0);
  }
  cout << ceil(ans / 2.0);
  return 0;
}
