#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int a[411100], cnt[411100];
int sum[411100];
int idx[411100];
int freq_cnt[411100];
int main() {
  int n;
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int max_idx = max_element(cnt, cnt + n) - cnt;
  int ans = 0;
  int lim = 512;
  for (int i = 1; i <= n; ++i) {
    if (max_idx == i) continue;
    if (cnt[i] < lim) {
      continue;
    }
    memset(idx, -1, sizeof(idx));
    idx[n] = 0;
    for (int j = 1; j <= n; ++j) {
      int s = 0;
      if (a[j] == max_idx)
        s = 1;
      else if (a[j] == i)
        s = -1;
      sum[j] = sum[j - 1] + s;
      if (idx[sum[j] + n] == -1)
        idx[sum[j] + n] = j;
      else {
        ans = max(ans, j - idx[sum[j] + n]);
      }
    }
  }
  for (int freq = 1; freq <= lim; ++freq) {
    int l = 1, r = 1;
    for (int i = 0; i <= n; ++i) freq_cnt[i] = 0, cnt[i] = 0;
    while (r <= n) {
      while (r <= n && cnt[a[r]] < freq) {
        --freq_cnt[cnt[a[r]]];
        ++cnt[a[r]];
        ++freq_cnt[cnt[a[r]]];
        r++;
      }
      if (freq_cnt[freq] >= 2) {
        ans = max(ans, r - l);
      }
      while (l < r && cnt[a[r]] >= freq) {
        --freq_cnt[cnt[a[l]]];
        --cnt[a[l]];
        ++freq_cnt[cnt[a[l]]];
        l++;
      }
    }
  }
  cout << ans << endl;
}
