#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double ERR = 1e-10;
char a[100010];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  int x = 0, y = 0;
  cin >> a;
  int l = strlen(a);
  for (int i = 0; i < l; i++) {
    if (a[i] == 'U') y++;
    if (a[i] == 'R') x++;
    if (x == y && a[i] == a[i + 1]) {
      ans++;
      i++;
      if (a[i] == 'U') y++;
      if (a[i] == 'R') x++;
    }
  }
  cout << ans << endl;
  return 0;
}
