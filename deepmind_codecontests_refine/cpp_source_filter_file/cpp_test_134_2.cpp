#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
template <class T>
long long upmax(T &a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
template <class T>
long long upmin(T &a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
void solve() {
  int n;
  cin >> n;
  vector<long long> arr(n);
  for (auto &i : arr) cin >> i;
  long long g[2];
  memset(g, -1, sizeof(g));
  for (int i = 0; i < n; i++) {
    if (g[i % 2] == -1)
      g[i % 2] = arr[i];
    else
      g[i % 2] = gcd(g[i % 2], arr[i]);
  }
  auto ok = [&](int d) {
    int color = -1;
    for (int i = 0; i < n; i++) {
      if (arr[i] % d == 0) {
        if (color == 0) {
          return 0;
        }
        color = 0;
      } else {
        if (color == 1) {
          return 0;
        }
        color = 1;
      }
    }
    return 1;
  };
  if (ok(g[0])) {
    cout << g[0] << '\n';
  } else if (ok(g[1])) {
    cout << g[1] << '\n';
  } else {
    cout << 0 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
