#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const char nl = '\n';
const int MAX_N = 1000 * 100 + 5;
int a[MAX_N];
int cnt[2];
int n;
void solve() {
  cnt[0] = cnt[1] = 0;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    if (a[i] == 25) {
      ++cnt[0];
    } else if (a[i] == 50) {
      if (cnt[0] == 0) {
        cout << "NO" << nl;
        return;
      } else {
        --cnt[0];
        ++cnt[1];
      }
    } else {
      if (cnt[1] >= 1 and cnt[0] >= 1) {
        --cnt[1];
        --cnt[0];
      } else if (cnt[0] >= 3) {
        cnt[0] -= 3;
      } else {
        cout << "NO" << nl;
        return;
      }
    }
  }
  cout << "YES" << nl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
