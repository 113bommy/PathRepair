#include <bits/stdc++.h>
using namespace std;
int tot[15], num[15];
string t, now;
int main() {
  cin >> t >> now;
  int len = t.size();
  for (int i = 0; i < len; i++) num[t[i] - '0']++;
  num[2] += num[5], num[5] = 0;
  num[6] += num[9], num[9] = 0;
  len = now.size();
  for (int i = 0; i < len; i++) tot[now[i] - '0']++;
  tot[2] += tot[5], tot[5] = 0;
  tot[6] += tot[9], tot[9] = 0;
  int ans = INT_MAX;
  for (int i = 1; i < 9; i++) {
    if (num[i] == 0) continue;
    ans = min(ans, tot[i] / num[i]);
  }
  cout << ans;
  return 0;
}
