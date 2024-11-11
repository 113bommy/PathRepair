#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, f, v[100005], C[100005], s[100005], c, c1, c2, c3;
vector<long long> a[100005];
pair<long long, long long> ans3;
bool dfs(long long x, long long d) {
  if (v[x]) {
    if (C[x] != d) return 1;
    return 0;
  }
  v[x] = 1;
  C[x] = d;
  c++;
  if (d == 1)
    c1++;
  else
    c2++;
  for (auto i : a[x]) {
    if (dfs(i, 3 - d)) return 1;
  }
  return 0;
}
void solve() {
  cin >> n >> m;
  if (m == 0) {
    cout << 3 << " " << n * (n - 1) * (n - 2) / 6 << "\n";
    return;
  };
  while (m--) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) {
    if (!v[i]) {
      c = c1 = c2 = 0;
      if (dfs(i, 1)) {
        cout << 0 << " " << 1 << "\n";
        return;
      };
      ans3.second += c1 * (c1 - 1) / 2 + c2 * (c2 - 1) / 2;
      ans3.first = (c >= 3);
      s[c]++;
    }
  }
  if (ans3.first) {
    cout << 1 << " " << ans3.second << "\n";
    return;
  };
  {
    cout << 2 << " " << 2 * s[2] * (s[2] - 1) + s[2] * s[1] << "\n";
    return;
  };
}
void prep() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  prep();
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
