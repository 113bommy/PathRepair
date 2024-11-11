#include <bits/stdc++.h>
using namespace std;
const int iinf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
int h, m;
unordered_map<int, int> sm;
long long solve(int u = 0, int mx = 0, int d = 0) {
  if (!sm[u]) return (1 << (h - d)) * mx;
  if (d == h) return max(sm[u], mx);
  long long res = 0;
  int mxl = max(mx, sm[u] - sm[u * 2 + 1]);
  int mxr = max(mx, sm[u] - sm[u * 2 + 2]);
  if (sm[u * 2 + 1] <= mxl)
    res += (1ll << (h - d - 1)) * mxl;
  else
    res += solve(u * 2 + 1, mxl, d + 1);
  if (sm[u * 2 + 2] <= mxr)
    res += (1ll << (h - d - 1)) * mxr;
  else
    res += solve(u * 2 + 2, mxr, d + 1);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout.precision(12), cout << fixed;
  cin >> h >> m;
  while (m--) {
    string s;
    cin >> s;
    if (s == "add") {
      int i, first;
      cin >> i >> first, --i;
      for (sm[0] += first; i; --i >>= 1) sm[i] += first;
    } else
      cout << 1. * solve() / (1 << h) << '\n';
  }
  return 0;
}
