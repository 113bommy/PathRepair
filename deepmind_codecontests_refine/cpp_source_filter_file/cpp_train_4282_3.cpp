#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, s;
  cin >> n >> s;
  vector<long long> v(n);
  long long sum = 0;
  long long mn = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
    mn = min(mn, v[i]);
  }
  if (sum < s) {
    cout << -1 << '\n';
    return 0;
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; ++i) {
    long long p = min(s, v[i] - mn);
    v[i] -= min(s, v[i] - mn);
    s -= p;
  }
  cout << mn - s / n - s % n << '\n';
  return 0;
}
