#include <bits/stdc++.h>
using namespace std;
long long S(long long l, long long k) {
  long long len1 = l / k;
  long long len2 = len1 + 1;
  long long cnt2 = l % k;
  long long cnt1 = k - cnt2;
  return cnt1 * len1 * len1 + cnt2 * len2 * len2;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  long long ans = 0;
  priority_queue<pair<long long, pair<long long, long long>>> q;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    ans += v[i] * v[i];
    q.push({S(v[i], 1) - S(v[i], 2), {v[i], 2}});
  }
  for (int i = 0; i < k - n; i++) {
    auto t = q.top();
    q.pop();
    ans -= t.first;
    int a = t.second.first, b = t.second.second;
    q.push({S(a, b) - S(a, b + 1), {a, b + 1}});
  }
  cout << ans;
  return 0;
}
