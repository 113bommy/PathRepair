#include <bits/stdc++.h>
using namespace std;
using LL = long long;
template <typename Container>
inline int ssize(Container& x) {
  return x.size();
}
int read() {
  register char c = '?';
  while (!isdigit(c)) c = getchar();
  register int ans = 0;
  for (; isdigit(c); c = getchar()) ans = ans * 10 + c - '0';
  return ans;
}
vector<int> G[100005];
int ans = 0;
void get_ans(int i) {
  static bool vis[100005];
  if (vis[i]) return;
  vis[i] = true;
  for (auto j : G[i])
    if (!vis[j]) {
      ans++;
      get_ans(j);
    }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  constexpr char endl = '\n';
  int n, m;
  cin >> m >> n;
  for (register int _______ = (n); _______ > 0; --_______) {
    int i, j;
    cin >> i >> j;
    G[i].push_back(j);
    G[j].push_back(i);
  }
  for (register auto i = (1), __r = decltype(i)(n); i <= __r; ++i) get_ans(i);
  cout << n - ans;
}
