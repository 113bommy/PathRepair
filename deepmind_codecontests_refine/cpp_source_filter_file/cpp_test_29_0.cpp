#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a, t;
  cin >> t;
  while (t--) {
    cin >> n;
    map<int, long long> m;
    for (int i = 0; i < n; ++i) cin >> a, m[a]++;
    cout << m[1] * pow(2ll, m[0]) << '\n';
  }
  return 0;
}
