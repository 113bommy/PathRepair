#include <bits/stdc++.h>
using namespace std;
long long sum_mod(long long a, long long b, long long m) { return (a + b) % m; }
bool check(int n, vector<long long>& a, vector<long long>& b) {
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ans = 1e18;
  long long curx = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    if ((*b.rbegin()) >= (*a.rbegin())) {
      x = (*b.rbegin()) - (*a.rbegin());
      for (int j = 0; j < n; j++) {
        a[j] += x;
      }
      if (check(n, a, b)) {
        if (curx + x < ans) ans = curx + x;
      }
    } else {
      x = 0;
    }
    long long y = m - (*a.rbegin());
    for (int j = 0; j < n; j++) {
      a[j] = sum_mod(a[j], y, m);
    }
    curx += x + y;
    sort(a.begin(), a.end());
  }
  cout << ans << '\n';
}
int main() {
  string file("product");
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 1;
  for (int t = 0; t < n; t++) {
    solve();
  }
}
