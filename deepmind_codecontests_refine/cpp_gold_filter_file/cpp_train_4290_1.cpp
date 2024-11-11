#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
struct Emp {
  int l, r;
} emp[N];
bool search(int m, int n, long long s) {
  long long sum = 0, cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (emp[i].l >= m)
      cnt++;
    else if (emp[i].l <= m && emp[i].r >= m && cnt <= n / 2) {
      sum += m - emp[i].l;
      cnt++;
    }
  }
  return sum <= s && cnt > n / 2;
}
void solve() {
  int n;
  long long s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    emp[i].l = l;
    emp[i].r = r;
    s -= l;
  }
  sort(emp, emp + n, [](const Emp &x, const Emp &y) { return x.l < y.l; });
  int l = 0, r = 1e9 + 1;
  while (l < r - 1) {
    int m = l + (r - l) / 2;
    bool f = search(m, n, s);
    if (f)
      l = m;
    else
      r = m;
  }
  cout << l << "\n";
}
int t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> t;
  while (t--) solve();
  return 0;
}
