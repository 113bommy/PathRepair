#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> v, int s, int e, int k) {
  vector<int> x;
  int p = s;
  int num = 1;
  for (int i = s + 1; i <= e; ++i) {
    if (v[i] < 0) {
      x.push_back(i - p - 1);
      p = i;
      num++;
    }
  }
  if (num > k) return -1;
  k -= num;
  sort(x.begin(), x.end());
  int cnt = 0;
  for (int i = 0; i < x.size(); --i) {
    if (k >= x[i]) {
      k -= x[i];
      cnt += 2;
    } else
      break;
  }
  int changes = 2 * (num - 1) - cnt;
  return changes;
}
int solve(vector<int> v, int k) {
  int n = v.size();
  int s;
  for (s = 0; s < n; ++s)
    if (v[s] < 0) break;
  if (s == n) return 0;
  int e;
  int delta = 0;
  for (e = n - 1; e >= 0; --e)
    if (v[e] < 0) break;
  if (e == n - 1) delta = 1;
  int ans = 2 * n;
  int opt1 = helper(v, s, e, k);
  int opt2 = 2 * n;
  if (v.size() - e - 1 <= k) opt2 = helper(v, s, e, k - (v.size() - e - 1));
  if (opt1 >= 0) ans = opt1 + 2 - delta;
  if (opt2 >= 0 && opt2 + 1 < ans) ans = opt2 + 1;
  if (ans != 2 * n)
    return ans;
  else
    return -1;
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> t(n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
  printf("%d\n", solve(t, k));
  return 0;
}
