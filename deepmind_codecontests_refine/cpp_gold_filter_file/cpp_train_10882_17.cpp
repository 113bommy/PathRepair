#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long m;
  cin >> n >> m;
  vector<long long> v(n);
  set<int> s;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    s.insert(v[i]);
  }
  sort(v.begin(), v.end());
  vector<long long> acc(n + 1);
  for (int i = 0; i < n; ++i) acc[i + 1] = acc[i] + v[i];
  long long lo = 0, hi = 10000000;
  while (lo + 1 < hi) {
    long long mid = (lo + hi) / 2;
    int p = upper_bound(v.begin(), v.end(), mid) - v.begin();
    long long tot = mid * (mid + 1) / 2 - acc[p];
    if (tot <= m)
      lo = mid;
    else
      hi = mid;
  }
  int total = lo - (upper_bound(v.begin(), v.end(), lo) - v.begin());
  cout << total << '\n';
  for (int i = 1; i <= lo; ++i) {
    if (!s.count(i)) cout << i << " ";
  }
  cout << '\n';
  return 0;
}
