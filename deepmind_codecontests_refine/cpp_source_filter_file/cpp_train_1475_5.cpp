#include <bits/stdc++.h>
using namespace std;
const long long maxx = 1e6 + 7;
const long long maxn = 1e6 + 7;
const long long mod = 998244353;
const long long maxs = 500000 + 7;
const long long maxm = 400000 + 7;
const long long maxk = 1008 + 7;
const long long maxw = 100 + 7;
const long long maxh = 100 + 7;
const double pi = 3.1415926;
const long long ten = 10;
const long long ooi = 1000000;
const long long ool = 1e18 + 7;
const long double eps = 1e-8;
const int apsz = 26;
int seq[maxn];
int n;
void init() {
  cin >> n;
  for (long long i = (1); i <= (n); i++) {
    cin >> seq[i];
  }
  sort(seq + 1, seq + 1 + n);
}
void solve() {
  int ans = 0;
  int i = 1;
  int nowd = 1;
  while (i <= n) {
    while (i <= n && seq[i] < nowd) i++;
    if (i == n + 1) break;
    ans++;
    nowd++;
  }
  cout << ans << endl;
}
int main(void) {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  init();
  solve();
  return 0;
}
