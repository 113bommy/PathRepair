#include <bits/stdc++.h>
using namespace std;
int n, m, x, sl = -1, dd[1000005], a[1000005];
pair<int, int> d[1000005], p;
string st;
long long ans = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  cin >> st;
  int k = st.size();
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    d[i] = make_pair(a[i], a[i] + k - 1);
    int hi = a[i] - a[i - 1];
    if (hi < k && i > 1 && st[hi] != st[0]) {
      cout << 0;
      return 0;
    }
  }
  d[m + 1].first = 1e18 + 1;
  for (int i = 1; i <= m + 1; i++) {
    if (p.second >= d[i].first)
      p.second = max(p.second, d[i].second);
    else {
      d[++sl] = p;
      p = d[i];
    }
  }
  for (int i = 0; i <= sl; i++)
    for (int j = d[i].first; j <= d[i].second; j++) dd[j] = 1;
  for (int i = 1; i <= n; i++)
    if (dd[i] == 0) ans = ans * 26 % 1000000009;
  cout << ans;
}
