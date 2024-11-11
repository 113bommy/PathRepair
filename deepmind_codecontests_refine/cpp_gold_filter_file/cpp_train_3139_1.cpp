#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long h, n;
  cin >> h >> n;
  long long arr[n];
  int i;
  for (i = 0; i < n; i++) cin >> arr[i];
  long long pref[n + 1];
  pref[0] = 0;
  for (i = 0; i < n; i++) pref[i + 1] = pref[i] + arr[i];
  long long delta = pref[n];
  int mini = 0;
  int idx;
  for (i = 1; i <= n; i++)
    if (pref[i] < mini) {
      mini = pref[i];
      idx = i;
    }
  if (h - abs(mini) > 0 && delta >= 0) {
    cout << -1 << '\n';
    return 0;
  }
  if (delta == 0 || h - abs(mini) <= 0) {
    int ans = 0;
    int pos = 0;
    while (h > 0) {
      h += arr[pos];
      pos++;
      pos %= n;
      ans++;
    }
    cout << ans << '\n';
    return 0;
  }
  long long beg = h;
  h -= abs(mini);
  long long dmg = abs(delta);
  long long times = h / dmg;
  long long ans = times * n;
  long long curr = beg - times * dmg;
  int pos = 0;
  while (curr > 0) {
    curr += arr[pos];
    pos++;
    pos %= n;
    ans++;
  }
  cout << ans;
}
