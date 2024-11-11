#include <bits/stdc++.h>
using namespace std;
int palindrome(string v, int s, int e) {
  if (s >= e) return 1;
  if (v[s] == v[e])
    return palindrome(v, s + 1, e - 1);
  else
    return 0;
}
long long int mn = LLONG_MAX, mx = LLONG_MIN;
long long int i, j, k, f, t, p, prv, d, r, sm;
long long int n, m, pos, cnt, ans, o, z, l, idx, e;
map<long long int, long long int> iim;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long int> v(n);
    for (i = 0; i < n; cin >> v[i++])
      ;
    if (n == 1 && v[0] == k) {
      cout << "yes" << endl;
      continue;
    }
    for (i = 0; i < n; i++) {
      if (v[i] == k) break;
    }
    if (i == n) {
      cout << "no" << endl;
      continue;
    }
    for (i = 0; i < n; i++) {
      if (v[i] >= k && (v[i + 1] >= k || v[i + 2] >= k)) break;
    }
    if (i == n)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }
  return 0;
}
