#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long maxn = 2e5 + 123;
const long long inf = 1e9 + 123;
const long long linf = 1e18 + 123;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1);
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};
int a[maxn], ans[maxn];
set<int> s;
int main() {
  boost();
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    s.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s.insert(i);
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] != a[i - 1]) {
        ans[i] = a[i];
        s.erase(a[i]);
      } else {
        ans[i] = (*s.begin());
        s.erase(*s.begin());
        if (ans[i] > ans[i - 1]) {
          ok = 1;
          break;
        }
      }
    }
    if (ok == 1) {
      cout << "-1\n";
      continue;
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  exit(0);
}
