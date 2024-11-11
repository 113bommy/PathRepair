#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, t, c, it;
  cin >> n >> t >> c;
  long long a[n];
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > t) v.push_back(i);
  }
  long long s = 0, f2 = 0;
  if (!v.empty()) {
    f2 = 1;
    if (v[0] >= c + 1) s += (v[0] - c + 1);
    for (it = 1; it < v.size(); it++) {
      if (v[it] - v[it - 1] > c) s += (v[it] - v[it - 1] - c);
    }
    if ((n - v[it - 1] - c) > 0) s += (n - v[it - 1] - c);
  }
  if (f2 == 0)
    cout << n - c + 1 << "\n";
  else
    cout << s << "\n";
}
