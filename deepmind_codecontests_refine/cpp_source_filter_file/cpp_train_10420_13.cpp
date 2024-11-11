#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const int N = 10e5 + 5;
const int OO = 1e9;
const long long MOD = 1000000007;
using namespace std;
int main() {
  long long n, m, cnt = 0, flag = 0, mx = 0, sum = 0;
  cin >> n >> m;
  long long a[n + 5];
  map<long long, long long> mp;
  set<long long> st;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
    if (mp[a[i]]) {
      flag = 1;
    }
    mp[a[i]] = 1;
  }
  if (flag) {
    cout << 0;
    return 0;
  } else {
    for (long long i = 0; i < n; i++) {
      if (mp[(a[i] & m)] && ((a[i] & m) != a[i])) {
        return cout << "1", 0;
      }
      st.insert((a[i] & m));
    }
    if (st.size() == (n - 1)) return cout << 2, 0;
  }
  cout << -1;
  return 0;
}
