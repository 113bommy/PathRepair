#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17 + 10;
const int N = 3e5 + 10;
const long long mod = 1e9 + 7;
map<string, int> ml;
long long c[N], vis[N][10], num[N], t, n, m, x, y, k, a[N];
long long ex, ey, cnt, ans, sum;
long long dist[N];
long long dp[N];
deque<int> q;
vector<pair<int, int> > v[N];
char s[500005], ss[500005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  cin >> s >> ss;
  cnt = 1;
  long long mx = 1e9 + 1;
  for (int i = 0; i < n; i++) {
    cnt = min(cnt * 2, mx);
    if (s[i] == 'b') cnt--;
    if (ss[i] == 'a') cnt--;
    ans += min(cnt, m);
  }
  cout << ans << endl;
}
