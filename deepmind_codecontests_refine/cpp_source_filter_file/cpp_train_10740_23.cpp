#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
constexpr long long MOD = 1000000007LL;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
void solve() {
  int b, w;
  cin >> b >> w;
  if (3 * (b - 1) < w - 4 or 3 * (w - 1) < b - 4) {
    cout << "NO" << '\n';
    return;
  }
  vector<pair<int, int> > ans;
  if (b >= w) {
    for (int i = 0; i < (w); ++i) ans.emplace_back(i * 2 + 2, 2);
    for (int i = 0; i < (w); ++i) ans.emplace_back(i * 2 + 3, 2);
    b -= w;
    if (b) {
      ans.emplace_back(1, 2);
      b--;
    }
    for (int i = 0; i < w and b > 0; i++) {
      ans.emplace_back(i * 2 + 2, 1);
      b--;
    }
    for (int i = 0; i < w and b > 0; i++) {
      ans.emplace_back(i * 2 + 3, 1);
      b--;
    }
  } else {
    for (int i = 0; i < (b); ++i) ans.emplace_back(i * 2 + 2, 3);
    for (int i = 0; i < (b + 1); ++i) ans.emplace_back(i * 2 + 1, 3);
    w -= b + 1;
    for (int i = 0; i < b and w > 0; i++) {
      ans.emplace_back(i * 2 + 2, 2);
      w--;
    }
    for (int i = 0; i < b and w > 0; i++) {
      ans.emplace_back(i * 2 + 2, 4);
      w--;
    }
  }
  cout << "YES" << '\n';
  for (auto i : ans) cout << i.first << " " << i.second << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  while (Q--) {
    solve();
  }
}
