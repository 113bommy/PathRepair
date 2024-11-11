#include <bits/stdc++.h>
using namespace std;
string tots;
string bor[14];
pair<int, int> ans;
int cash[14];
int n;
int r = 0;
int l;
void chg(int x, int v, int mode) {
  if (x < 0 or x >= tots.size()) return;
  for (int i = 0; i < n; i++) {
    if (mode == 0) {
      if ((int)bor[i].size() + x - 1 >= r) continue;
      if (tots.substr(x, bor[i].size()) == bor[i]) cash[i] += v;
    } else {
      if (x - (int)bor[i].size() + 1 < l) continue;
      if (tots.substr(x - (int)bor[i].size() + 1, bor[i].size()) == bor[i])
        cash[i] += v;
    }
  }
}
int main() {
  cin >> tots >> n;
  for (int i = 0; i < n; i++) cin >> bor[i];
  int kl = tots.size();
  for (int i = 0; i < kl; i++) {
    chg(i - 1, -1, 0);
    l = i;
    while (r <= kl) {
      int flag = 0;
      for (int k = 0; k < n; k++) flag |= cash[k];
      if (flag)
        break;
      else
        ans = max(ans, make_pair(r - i, i));
      if (r == kl) break;
      chg(r, 1, 1);
      r++;
    }
  }
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}
