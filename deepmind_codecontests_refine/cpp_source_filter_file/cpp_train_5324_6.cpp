#include <bits/stdc++.h>
using namespace std;
long long cfreq[500100], org[500100];
long long arr[100100];
vector<long long> vec;
int main() {
  long long t, n, i, j, k, l, m;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  t = 1;
  while (t--) {
    long long second;
    cin >> m >> k >> n >> second;
    for (i = 1; i <= m; i++) cin >> arr[i];
    for (i = 1; i <= second; i++) cin >> j, org[j]++;
    i = 1;
    j = 1;
    long long strt = 0, ed = -1;
    long long ans = 1e9, curr_sz = 0;
    while (i <= m) {
      if (curr_sz < second || i - j < k) {
        if (cfreq[arr[i]] < org[arr[i]]) curr_sz++;
        cfreq[arr[i]]++;
        i++;
      }
      if (curr_sz >= second && i - j >= k) {
        long long len = i - j;
        if (ans > (len - k)) {
          ans = len - k;
          strt = j;
          ed = i;
        }
        ans = min(ans, len - k);
        long long tmp = k;
        while (tmp--) {
          cfreq[arr[j]]--;
          if (cfreq[arr[j]] < org[arr[j]]) curr_sz--;
          j++;
        }
      }
    }
    while (j < i) cfreq[arr[j]]--, j++;
    long long extras = m - (n * k);
    if (extras < ans)
      cout << -1 << '\n';
    else {
      cout << ans << '\n';
      for (i = strt; i <= ed; i++) {
        cfreq[arr[i]]++;
        if (cfreq[arr[i]] > org[arr[i]]) vec.push_back(i);
      }
      for (int i = 0; i < ans; i++) cout << vec[i] << ' ';
      cout << '\n';
    }
  }
  return 0;
}
