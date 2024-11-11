#include <bits/stdc++.h>
using namespace std;
long long dp[300005];
int main() {
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    for (int j = i + i; j <= n; j += i) dp[j]++;
  long long sum = 0, m = 0;
  for (int i = 1; i <= n; i++) {
    sum += dp[i];
    if (sum >= k) {
      m = i;
      break;
    }
  }
  vector<pair<long long, long long> > vec;
  for (int i = m / 2 + 1; i <= m; i++) vec.emplace_back(dp[i], i);
  sort(vec.rbegin(), vec.rend());
  set<int> st;
  for (int i = 1; i <= m; i++) st.insert(i);
  k = sum - k;
  for (int i = 0; i < vec.size() and k > 0; i++) {
    if (vec[i].first <= k) {
      k -= vec[i].first;
      st.erase(vec[i].second);
    }
  }
  if (k != 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << st.size() << endl;
    for (int val : st) cout << val << " ";
    cout << endl;
  }
  return 0;
}
