#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void prn(Arg1&& arg1) {
  cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void prn(Arg1&& arg1, Args&&... args) {
  cout << arg1 << " ";
  prn(args...);
}
template <typename Arg1>
void prs(Arg1&& arg1) {
  cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void prs(Arg1&& arg1, Args&&... args) {
  cout << arg1 << " ";
  prs(args...);
}
template <typename Arg1>
void read(Arg1&& arg1) {
  cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1&& arg1, Args&&... args) {
  cin >> arg1;
  read(args...);
}
const int mod = 998244353;
int n, k;
void solve() {
  read(n, k);
  vector<int> a(n), b(k), pos(n + 1);
  for (int i = 0; i < n; ++i) {
    read(a[i]);
    pos[a[i]] = i;
  }
  vector<int> later(n, 0);
  for (int i = 0; i < k; ++i) {
    read(b[i]);
    later[b[i]] = 1;
  }
  long long ans = 1;
  for (int i = 0; i < k; ++i) {
    int cur = b[i];
    later[cur] = 0;
    int opts = 0, p = pos[cur];
    if (p && !later[a[p - 1]]) ++opts;
    if (p + 1 < n && !later[a[p + 1]]) ++opts;
    ans = ans * opts % mod;
  }
  prn(ans);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  read(t);
  for (int tc = 1; tc <= t; ++tc) {
    solve();
  }
  return 0;
}
