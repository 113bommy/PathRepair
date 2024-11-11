#include <bits/stdc++.h>
using namespace std;
long long int i, j, n, m, k, l, q, t, a, b, sum[3], tot[3], cnt[3];
long long int powom(long long int a, long long int b) {
  long long int result = 1;
  while (b > 0) {
    if (b & 1) result = result * a;
    a = a * a;
    b >>= 1;
  }
  return result;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  vector<long long int> fact;
  for (long long int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      fact.push_back(i);
      if (n / i != i) {
        fact.push_back(n / i);
      }
    }
  }
  map<long long int, long long int> mp;
  for (long long int i = 0; i < m; i++) {
    cin >> a >> b;
    mp[a] = b;
  }
  set<long long int> ans;
  bool flag1 = 0;
  for (long long int y = 1; y <= n; y++) {
    bool flag = 0;
    for (auto x : mp) {
      if (x.second != ceil(x.first / (double)y)) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      ans.insert(ceil(n / (double)y));
      flag1 = 1;
    }
  }
  if (ans.size() != 1) {
    cout << -1;
    return 0;
  }
  cout << (*ans.begin());
  return 0;
}
