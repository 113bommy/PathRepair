#include <bits/stdc++.h>
using namespace std;
long long int m, n, a[100006], cur_l = 1, cur_r = 0, ans, freq[100005];
vector<long long> dp_before(1), dp_cur(1);
void remove(int idx) {
  freq[a[idx]]--;
  ans -= freq[a[idx]];
}
void add(int idx) {
  ans += freq[a[idx]];
  freq[a[idx]]++;
}
long long C(int i, int j) {
  while (cur_l > i) {
    cur_l--;
    add(cur_l);
  }
  while (cur_r < j) {
    cur_r++;
    add(cur_r);
  }
  while (cur_l < i) {
    remove(cur_l);
    cur_l++;
  }
  while (cur_r > j) {
    remove(cur_r);
    cur_r--;
  }
  return ans;
}
void compute(int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  pair<long long, int> best = {LLONG_MAX, -1};
  for (int k = optl; k <= min(mid, optr); k++) {
    best = min(best, {dp_before[k - 1] + C(k, mid), k});
  }
  dp_cur[mid] = best.first;
  int opt = best.second;
  compute(l, mid - 1, optl, opt);
  compute(mid + 1, r, opt, optr);
}
long long int solve() {
  dp_before[0] = dp_cur[0] = 0;
  for (int i = 1; i <= m; i++) dp_before[i] = C(1, i);
  for (int i = 2; i <= n; i++) {
    compute(1, m, 1, m);
    dp_before = dp_cur;
  }
  return dp_before[m];
}
int main() {
  long long int i, j, k;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n;
  dp_before.resize(m + 1);
  dp_cur.resize(m + 1);
  for (i = 1; i <= m; i++) cin >> a[i];
  cout << solve() << endl;
}
