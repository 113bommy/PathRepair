#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> leg(n);
  for (int i = 0; i < n; i++) cin >> leg[i].first;
  for (int i = 0; i < n; i++) cin >> leg[i].second;
  sort(leg.begin(), leg.end());
  vector<int> sum(n);
  sum[0] = leg[0].second;
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + leg[i].second;
  vector<int> xd(205);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n;) {
    int x = i;
    while (++i < n && leg[i].first == leg[x].first)
      ;
    int okl = (i - x) / 2;
    int ddd = sum[n - 1] - sum[i - 1];
    if (x) ddd += sum[x - 1];
    for (int j = 200; j; j--)
      if (xd[j]) {
        int xxx = min(xd[j], okl);
        ddd -= j * xxx;
        if (!(okl -= xxx)) break;
      }
    for (int j = x; j < i; j++) xd[leg[j].second]++;
    ans = min(ans, ddd);
  }
  cout << ans << endl;
  return 0;
}
