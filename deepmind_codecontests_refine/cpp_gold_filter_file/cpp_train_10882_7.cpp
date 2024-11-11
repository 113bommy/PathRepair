#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long low = 1, high = (long long)1e9, mid = (high + low) / 2;
  vector<long long> A(n), pre(n + 1);
  map<long long, bool> B;
  for (int x = 0; x < n; x++) cin >> A[x], B[A[x]] = true;
  sort(A.begin(), A.end());
  for (int x = 1; x <= n; x++) pre[x] = A[x - 1] + pre[x - 1];
  long long ans = 1;
  while (low <= high) {
    mid = (low + high) / 2;
    long long tmp1 = mid * (mid + 1) / 2;
    long long tmp2 = upper_bound(A.begin(), A.end(), mid) - A.begin();
    long long tmp3 = tmp1 - pre[tmp2];
    if (tmp3 > m) {
      high = mid - 1;
    } else if (tmp3 < m) {
      ans = max(mid, ans);
      low = mid + 1;
    } else {
      ans = max(mid, ans);
      break;
    }
  }
  vector<long long> res;
  for (int x = 1; x <= ans; x++)
    if (!B.count(x)) res.push_back(x);
  cout << res.size() << '\n';
  for (int x = 0; x < res.size(); x++)
    cout << res[x] << " \n"[x + 1 == res.size()];
}
