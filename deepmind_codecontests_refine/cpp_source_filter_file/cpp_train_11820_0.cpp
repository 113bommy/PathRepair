#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  long long n;
  cin >> n;
  set<long long> st;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    st.insert(x);
  }
  vector<long long> v(st.begin(), st.end());
  bool ans = false;
  for (long long i = 0; i < v.size(); ++i)
    if (i + 2 < n and v[i + 2] - v[i] <= 2) ans = true;
  cout << (ans ? "yes" : "no");
}
