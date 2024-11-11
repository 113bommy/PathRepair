#include <bits/stdc++.h>
using namespace std;
template <class T, class T2>
inline int chkmax(T &x, const T2 &y) {
  return x < y ? x = y, 1 : 0;
}
template <class T, class T2>
inline int chkmin(T &x, const T2 &y) {
  return x > y ? x = y, 1 : 0;
}
const int MAXN = (1 << 20);
int n;
int s;
vector<int> adj[MAXN];
void read() {
  cin >> n >> s;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}
void solve() {
  int cnt = 0;
  for (int i = 1; i <= n; i++) cnt += (((int)adj[i].size()) == 1);
  if (cnt == n) cnt--;
  double answer = 2.0 * (s / (double)cnt);
  if (n == 2) answer = s;
  cout << setprecision(9) << fixed << answer << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
