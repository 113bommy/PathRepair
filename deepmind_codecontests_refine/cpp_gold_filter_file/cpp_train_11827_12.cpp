#include <bits/stdc++.h>
using namespace std;
const int PMTH = 1000005;
long long a[PMTH], n, S, cost, ans;
bool check(int mid) {
  vector<long long> v;
  for (long long i = (1); i <= (n); i++) v.push_back(a[i] + i * mid);
  sort(v.begin(), v.end());
  long long sum = 0;
  for (long long i = (0); i <= (mid - 1); i++) sum += v[i];
  if (sum > S) return false;
  cost = sum;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> S;
  for (long long i = (1); i <= (n); i++) cin >> a[i];
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << " " << cost;
  return 0;
}
