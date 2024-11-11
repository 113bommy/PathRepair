#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:267386880")
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> d(n);
  for (int i(0); i <= ((long long)(n)-1); ++i) scanf("%d", &d[i]);
  string ans("");
  int cur(0);
  while (cur != n) {
    while (d[cur] != 0) {
      ans += 'P';
      if (cur != (n - 1))
        ans += "RL";
      else
        ans += "LR";
      d[cur]--;
    }
    if (cur != n - 1) ans += 'R';
    ++cur;
  }
  cout << ans << endl;
}
void bruteforce() {}
int main() {
  solve();
  bruteforce();
  return 0;
}
