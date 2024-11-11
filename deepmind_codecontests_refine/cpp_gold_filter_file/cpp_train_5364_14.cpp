#include <bits/stdc++.h>
using namespace std;
vector<string> v;
long long n, p;
long long cur;
long long ans;
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> p;
  for (long long i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  reverse((v).begin(), (v).end());
  ans = p / 2;
  cur = 1;
  for (long long i = 1; i < (long long)(v).size(); ++i) {
    if (v[i] == "half") {
      ans += cur * p;
      cur *= 2;
    } else {
      ans += cur * p + p / 2;
      cur = cur * 2 + 1;
    }
  }
  cout << ans;
  return 0;
}
