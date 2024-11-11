#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, k;
struct st {
  int v, p;
};
bool cmp(st a, st b) { return a.v < b.v; }
st a[MAX];
void solve() {
  sort(a + 1, a + n + 1, cmp);
  int t = 0;
  for (int i = 2; i <= n; ++i) {
    if (a[i].p == a[i - 1].p + 1) {
      while (1) {
        if (a[i].p != a[i - 1].p + 1)
          break;
        else {
          ++i;
        }
      }
      --i;
    } else {
      ++t;
    }
  }
  if (t + 1 == k)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].v;
      a[i].p = i;
    }
    solve();
  }
  return 0;
}
