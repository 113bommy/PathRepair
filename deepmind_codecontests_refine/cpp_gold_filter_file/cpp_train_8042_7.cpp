#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 * 9;
const int N = 1e6 + 23;
const int M = 1e5 + 3;
const int mod = 1e9 + 7;
const int p = 998244353;
int n, a[N], x, m, y, k, ans, vis[N];
string s;
char ch;
map<int, int> mp, mp1;
vector<int> ve, ve1;
bool cmp(int a, int b) { return a > b; }
queue<int> Q, q;
void solve() {
  int f = 0, pos = 0, mx = -mod, s1 = 0, s2 = 0, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i < n - (n / 4 + (bool)(n % 4)) + 1)
      cout << 9;
    else
      cout << 8;
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) solve();
}
