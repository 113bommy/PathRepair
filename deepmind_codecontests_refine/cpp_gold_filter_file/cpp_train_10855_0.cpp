#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> v;
vector<pair<long long, pair<long long, long long>>> ans;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    v.clear();
    ans.clear();
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
      long long a;
      cin >> a;
      v.push_back(a);
    }
    long long sum = accumulate((v).begin(), (v).end(), 0LL, plus<long long>());
    if (sum % n) {
      cout << -1 << '\n';
      continue;
    }
    sum /= n;
    for (long long i = 2; i <= n; ++i) {
      if (v[i - 1] % i)
        ans.push_back(make_pair(1, make_pair(i, i - v[i - 1] % i)));
      if (v[i - 1] % i) v[i - 1] += i - v[i - 1] % i;
      ans.push_back(make_pair(i, make_pair(1, v[i - 1] / i)));
    }
    for (long long i = 2; i <= n; ++i) {
      ans.push_back(make_pair(1, make_pair(i, sum)));
    }
    cout << (long long)(ans).size() << '\n';
    for (auto i : ans)
      cout << i.first << " " << i.second.first << " " << i.second.second
           << '\n';
  }
}
