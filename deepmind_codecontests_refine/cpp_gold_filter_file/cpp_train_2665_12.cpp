#include <bits/stdc++.h>
using namespace std;
const long long inf = 2 * 1e18;
const int mod = 1e9 + 7;
const int maxn = 300005;
int n, k, ans1;
string st;
int getans(int l, int r) {
  while (r > l) {
    int md = (l + r) >> 1;
    cout << 1 << " " << md << " " << md + 1 << endl;
    fflush(stdout);
    cin >> st;
    if (st == "NIE")
      l = md + 1;
    else
      r = md;
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  int ans1 = getans(1, n);
  int ans2 = getans(1, ans1 - 1);
  int ans3 = getans(ans1 + 1, n);
  cout << 1 << " " << ans2 << " " << ans1 << endl;
  fflush(stdout);
  cin >> st;
  if (st != "TAK")
    ans2 = ans3;
  else if (ans1 == ans2)
    ans2 = ans3;
  cout << 2 << " " << ans1 << " " << ans2 << endl;
  fflush(stdout);
  return 0;
}
