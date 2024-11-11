#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int skill[maxn];
bool cmp(int a, int b) { return a % 10 > b % 10; }
int main(void) {
  int n, k, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> skill[i];
  sort(skill, skill + n, cmp);
  for (int i = 0; i < n; i++)
    if (k <= 0 || skill[i] >= 100) {
      continue;
    } else if (10 - skill[i] % 10 > k) {
      k = 0;
      skill[i] += k;
    } else {
      k -= (10 - skill[i] % 10);
      skill[i] = (skill[i] / 10 + 1) * 10;
    }
  int t = 0;
  for (int i = 0; i < n; ++i) {
    t += (10 - skill[i] / 10);
    ans += skill[i] / 10;
  }
  if (k != 0) ans += min(k / 10, t);
  cout << ans << endl;
  return 0;
}
