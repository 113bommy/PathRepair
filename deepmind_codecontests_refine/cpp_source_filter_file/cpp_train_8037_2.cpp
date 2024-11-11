#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, t, easy, hard;
  cin >> n >> t >> easy >> hard;
  vector<array<long long, 2>> a(n);
  for (auto &x : a) cin >> x[1];
  for (auto &x : a) cin >> x[0];
  sort(a.begin(), a.end());
  long long cnt_hard = 0, cnt_easy = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i][1] == 0)
      cnt_easy++;
    else
      cnt_hard++;
  }
  long long res = 0;
  if (a[0][0]) {
    long long time = a[0][0] - 1;
    res += min(time / easy, cnt_easy);
    time -= res * easy;
    res += min(time / hard, cnt_hard);
  }
  long long cur_time = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i][1] == 0)
      cnt_easy--;
    else
      cnt_hard--;
    cur_time += (a[i][1] == 1 ? hard : easy);
    long long j = i + 1;
    while (j < n && a[j][0] == a[i][0]) {
      cur_time += (a[j][1] == 1 ? hard : easy);
      if (a[j][1] == 0)
        cnt_easy--;
      else
        cnt_hard--;
      j++;
    }
    i = j - 1;
    long long next_time = (i + 1 < n ? a[i + 1][0] : t + 1);
    if (cur_time < next_time) {
      long long time = next_time - a[i][0] - 1, tr = 0;
      tr += min(time / easy, cnt_easy);
      time -= tr * easy;
      tr += min(time / hard, cnt_hard);
      res = max(res, tr + i + 1);
    }
  }
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tests;
  cin >> tests;
  while (tests-- > 0) solve();
  return 0;
}
