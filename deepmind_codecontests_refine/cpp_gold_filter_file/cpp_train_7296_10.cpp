#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> p;
  for (int i = 0; i < n; ++i) {
    cout << 1 << endl;
    fflush(stdout);
    int cur;
    cin >> cur;
    if (cur > 0)
      p.push_back(1);
    else if (cur < 0)
      p.push_back(0);
    else
      return 0;
  }
  int cnt = 0;
  int l = 1, r = m;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    cout << mid << endl;
    fflush(stdout);
    int cur;
    cin >> cur;
    if (!p[cnt]) cur = -cur;
    if (cur == 0) return 0;
    if (cur < 0)
      r = mid - 1;
    else
      l = mid + 1;
    cnt++;
    cnt %= n;
  }
  return 0;
}
