#include <bits/stdc++.h>
using namespace std;
vector<int> prime_division(int64_t n, int K) {
  vector<int> ret;
  for (int64_t i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    if (cnt % K) {
      ret.push_back(i);
      ret.push_back(cnt % K);
    }
  }
  if (n > 1) {
    ret.push_back(n);
    ret.push_back(1);
  }
  return ret;
}
int main() {
  int N, K, A[100000];
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i];
  int64_t ans = 0;
  map<vector<int>, int> mp;
  for (int i = 0; i < N; i++) {
    auto v = prime_division(A[i], K);
    int sz = v.size();
    auto v2 = v;
    for (int i = 1; i < sz; i += 2) {
      v2[i] = K - v[i];
    }
    if (mp.count(v2)) ans += mp[v2];
    mp[v]++;
  }
  cout << ans << endl;
  return 0;
}
