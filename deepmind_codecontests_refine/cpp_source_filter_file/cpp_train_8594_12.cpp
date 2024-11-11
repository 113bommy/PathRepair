#include <bits/stdc++.h>
using namespace std;
long long ans[1000010];
long long rs_before[1000010], ls_after[1000010], rs_cnt[1000010],
    ls_cnt[1000010], first_ls[1000010], first_rs[1000010];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  s = "#" + s;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'U')
      s[i] = 'R';
    else
      s[i] = 'L';
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'R') {
      rs_before[i] = rs_before[i - 1] + i;
      rs_cnt[i] = rs_cnt[i - 1] + 1;
      first_rs[rs_cnt[i]] = first_rs[rs_cnt[i] - 1] + i;
    } else {
      rs_before[i] = rs_before[i - 1];
      rs_cnt[i] = rs_cnt[i - 1];
    }
  }
  for (int i = n; i >= 1; --i) {
    if (s[i] == 'L') {
      ls_after[i] = ls_after[i + 1] + i;
      ls_cnt[i] = ls_cnt[i + 1] + 1;
      first_ls[ls_cnt[i]] = first_ls[ls_cnt[i] - 1] + i;
    } else {
      ls_cnt[i] = ls_cnt[i + 1];
      ls_after[i] = ls_after[i + 1];
    }
  }
  long long rs_cnt_now = 0;
  long long ls_cnt_now = ls_cnt[2];
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'L') {
      --ls_cnt_now;
      if (rs_cnt_now <= ls_cnt_now) {
        ans[i] =
            2 * (i * rs_cnt_now - first_rs[rs_cnt_now]) +
            2 * ((first_ls[ls_cnt_now] - first_ls[ls_cnt_now - rs_cnt_now]) -
                 i * rs_cnt_now) +
            i;
      } else {
        ans[i] = 2 * (i * (ls_cnt_now + 1) -
                      (first_rs[rs_cnt_now] -
                       first_rs[rs_cnt_now - ls_cnt_now - 1])) +
                 2 * (first_ls[ls_cnt_now] - i * ls_cnt_now) + (n + 1 - i);
      }
    } else {
      if (ls_cnt_now <= rs_cnt_now) {
        ans[i] = 2 * (i * ls_cnt_now - (first_rs[rs_cnt_now] -
                                        first_rs[rs_cnt_now - ls_cnt_now])) +
                 2 * (first_ls[ls_cnt_now] - i * ls_cnt_now) + (n + 1 - i);
      } else {
        ans[i] = 2 * (i * (rs_cnt_now)-first_rs[rs_cnt_now]) +
                 2 * ((first_ls[ls_cnt_now] -
                       first_ls[ls_cnt_now - rs_cnt_now - 1]) -
                      i * (rs_cnt_now + 1)) +
                 i;
      }
      ++rs_cnt_now;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
}
