#include <bits/stdc++.h>
using namespace std;
void _print(vector<long long> v) {
  cout << "[ ";
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "]"
       << "\n";
}
void solve() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long> arr(n, 0);
  for (long long i = 0; i < n; i++) {
    if (s[i] == '+') {
      if (i % 2 == 0)
        arr[i] = 1;
      else
        arr[i] = -1;
    } else {
      if (i % 2 == 0)
        arr[i] = -1;
      else
        arr[i] = 1;
    }
  }
  vector<long long> pref(n + 1, 0);
  pref[0] = 0;
  for (long long i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + arr[i];
  }
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    sum += arr[i];
  }
  for (long long i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    long long sm = pref[r] - pref[l - 1];
    if (sm == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (sm % 2 == 1 || r == l) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
