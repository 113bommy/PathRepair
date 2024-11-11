#include <bits/stdc++.h>
using namespace std;
struct prefix {
  vector<long long> T;
  prefix(vector<long long> &A) {
    T.resize(A.size());
    T[0] = A[0];
    for (int i = 1; i < A.size(); ++i) T[i] = A[i] + T[i - 1];
  }
  long long query(int i, int len) {
    return T[i + len - 1] - (i == 0 ? 0 : T[i - 1]);
  }
};
int n, len, k;
vector<long long> A;
struct RobinQueue {
  multiset<long long> MS1, MS2;
  long long sum = 0;
  int size() { return MS1.size() + MS2.size(); }
  void insert(long long v) {
    if (MS1.size() < k) {
      MS1.insert(v);
      sum += v;
    } else {
      MS1.insert(v);
      sum += v;
      MS2.insert(*MS1.begin());
      sum -= *MS1.begin();
      MS1.erase(MS1.begin());
    }
  }
  void erase(long long v) {
    auto iter = MS2.find(v);
    if (iter != MS2.end()) {
      MS2.erase(iter);
      return;
    } else {
      MS1.erase(MS1.find(v));
      sum -= v;
      if (!MS2.empty()) {
        iter = --MS2.end();
        sum += *iter;
        MS1.insert(*iter);
        MS2.erase(iter);
      }
    }
  }
};
long long solve() {
  RobinQueue R;
  prefix P(A);
  for (int i = 0; i < len; ++i)
    if (A[i] < 0) R.insert(-A[i]);
  long long ans = P.query(0, len) + 2 * R.sum;
  for (int i = 0; i + len < n; ++i) {
    if (A[i] < 0) R.erase(-A[i]);
    if (A[i + len] < 0) R.insert(-A[i + len]);
    ans = max(P.query(i + 1, len) + 2 * R.sum, ans);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> len;
  A.resize(n);
  for (long long &a : A) cin >> a;
  cin >> k;
  k = min(len, k);
  long long ans = solve();
  for (long long &a : A) a = -a;
  ans = max(ans, solve());
  cout << ans << '\n';
  return 0;
}
