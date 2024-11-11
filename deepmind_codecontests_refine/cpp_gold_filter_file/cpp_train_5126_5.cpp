#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 922337203685477;
const long long mininf = -922337203685477;
const long long nax = 0;
long long t, n, x, a[1000], cnt, bl[1000];
void solve() {
  memset(bl, 0, sizeof(bl));
  cin >> n >> x;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    bl[a[i]]++;
  }
  long long temp = 0;
  cnt = 0;
  for (long long i = 1; i <= 900; i++) {
    if (bl[i] == 0) {
      cnt++;
    }
    if (cnt > x) {
      temp = i - 1;
      break;
    }
  }
  cout << temp << '\n';
}
int main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
