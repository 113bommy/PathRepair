#include <bits/stdc++.h>
using namespace std;
void shikhar7s(long long int cas) {
  long long int n, i;
  cin >> n;
  long long int a;
  vector<long long int> v;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  long long int st = 0, end = 1000000000, mid, ans, j, d, c = 0;
  while (st <= end) {
    j = 0;
    c = 0;
    mid = (st + end) / 2;
    while (j < n && c < 3) {
      d = v[j] + (2 * mid);
      j = upper_bound(v.begin(), v.end(), d) - v.begin();
      c++;
    }
    if (d < v[n - 1])
      st = mid + 1;
    else {
      ans = mid;
      end = mid - 1;
    }
  }
  float an = ans - 0.5;
  j = 0;
  c = 0;
  while (j < n && c < 3) {
    d = v[j] + (2 * an);
    j = upper_bound(v.begin(), v.end(), d) - v.begin();
    c++;
  }
  if (d < v[n - 1]) an += 0.5;
  cout << setprecision(12) << an << "\n";
  j = 0;
  c = 0;
  long long int l;
  while (j < n && c < 3) {
    d = v[j] + (2 * an);
    cout << setprecision(12) << v[j] + an << " ";
    l = j;
    j = upper_bound(v.begin(), v.end(), d) - v.begin();
    c++;
  }
  while (c < 3) {
    cout << setprecision(12) << v[l] + an << " ";
    c++;
  }
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  long long int t = 1;
  long long int cas = 1;
  while (cas <= t) {
    shikhar7s(cas);
    cas++;
  }
  return 0;
}
