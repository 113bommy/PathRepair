#include <bits/stdc++.h>
using namespace std;
const int64_t M = 2e6 + 5;
int64_t n, t, ans, A[M], BIT[M];
vector<int64_t> pre;
void update(int64_t x) {
  x += 10;
  for (; x < M; x += x & -x) BIT[x] += 1;
}
int64_t query(int64_t x) {
  x += 10;
  int64_t sum = 0;
  for (; x > 0; x -= x & -x) sum += BIT[x];
  return sum;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  pre.push_back(A[0]);
  for (int64_t i = 1; i <= n; i++) {
    cin >> A[i];
    A[i] += A[i - 1];
    pre.push_back(A[i]);
  }
  sort(pre.begin(), pre.end());
  for (int64_t i = 0; i <= n; i++) {
    auto idx = lower_bound(pre.begin(), pre.end(), A[i] - t + 1) - pre.begin();
    ans += query(n) - query(idx - 1);
    idx = lower_bound(pre.begin(), pre.end(), A[i]) - pre.begin();
    update(idx);
  }
  cout << ans << endl;
  return 0;
}
