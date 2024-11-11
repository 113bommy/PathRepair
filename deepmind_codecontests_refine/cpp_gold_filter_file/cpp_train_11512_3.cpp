#include <bits/stdc++.h>
using namespace std;
int a[200003];
int b[200003];
vector<int> seg;
int main() {
  int n, k;
  cin >> n >> k;
  int cnt = 1;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) b[cnt++] = i;
  }
  cnt--;
  if (cnt > k) {
    cout << -1;
    return 0;
  }
  int ans = 2 * cnt;
  k -= cnt;
  for (i = 1; i < cnt; i++) seg.push_back(b[i + 1] - b[i] - 1);
  sort(seg.begin(), seg.end());
  for (int l : seg) {
    if (l <= k) ans -= 2, k -= l;
  }
  if (n - b[cnt] <= k && cnt) ans--;
  cout << ans << "\n";
  return 0;
}
