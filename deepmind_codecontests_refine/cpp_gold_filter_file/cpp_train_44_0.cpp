#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long inf = 1e18;
int a[105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i <= a; i += 2) {
    for (int j = 0; j <= b; j++) {
      int left = n - i / 2 - j;
      if (left >= 0 && left % 2 == 0 && 2 * c >= left) ans++;
    }
  }
  cout << ans << endl;
}
