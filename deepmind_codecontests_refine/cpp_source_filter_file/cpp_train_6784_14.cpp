#include <bits/stdc++.h>
using namespace std;
const long long maxx = 100000 + 7;
const long long maxn = 1e5 + 7;
const long long mod = 998244353;
const long long maxs = 5 * (1E5) + 7;
const long long maxm = 30000 + 7;
const long long maxk = 800 + 7;
const long long maxw = 100 + 7;
const long long maxh = 100 + 7;
const long long inf = 1e5 + 7;
ostream& operator<<(ostream& os, pair<long long, long long>& rhs) {
  os << rhs.first << " " << rhs.second << endl;
  return os;
}
long long qw(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b /= 2;
    a = a * a;
  }
  return ans;
}
long long sum[maxn];
long long oib;
string a, b;
void init() {
  cin >> a >> b;
  for (char ch : b) {
    if (ch == '1') oib++;
  }
  int ii = 0;
  for (char ch : a) {
    if (ii == 0)
      sum[ii] = ch - '0';
    else
      sum[ii] = sum[ii - 1] + ch - '0';
    ii++;
  }
}
void solve() {
  long long ans = (oib % 2 == sum[b.length() - 1] % 2);
  for (int i = b.length() + 1; i < a.length(); i++) {
    long long tmp = sum[i] - sum[i - b.length() - 1];
    if ((tmp % 2) == (oib % 2)) ans++;
  }
  cout << ans << endl;
}
int main(void) {
  init();
  solve();
  return 0;
}
