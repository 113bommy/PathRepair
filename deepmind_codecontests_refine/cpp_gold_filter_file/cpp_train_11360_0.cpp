#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int MAX = 2e5 + 10;
int n, m;
ll t;
int best, res;
int a[MAX];
int b[MAX];
ll s[MAX];
int simula(int x) {
  ll accum = 0;
  int cnt = 0;
  ll sum = 0;
  int cuenta = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] <= x) cuenta++;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > x) continue;
    if (sum + a[i] > t) break;
    sum += a[i];
    accum += a[i];
    cnt++;
    if (cnt % m == 0) {
      sum += accum;
      accum = 0;
    }
  }
  if (cnt > best) {
    best = cnt;
    res = x;
  }
  if (cuenta == cnt) return 1;
  return 0;
}
void solve() {
  best = 0;
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  s[0] = b[0];
  for (int i = 1; i < n; i++) {
    s[i] = s[i - 1];
    s[i] += b[i];
  }
  if (b[0] > t) {
    cout << "0 1\n";
    return;
  }
  int low = 0;
  int hi = b[n - 1] + 1;
  simula(hi);
  while (simula(low + 1) && best < n) {
    int cen = (low + hi + 1) / 2;
    if (simula(cen))
      low = cen;
    else
      hi = cen;
  }
  if (res > t) res = t;
  cout << best << " " << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c;
  cin >> c;
  while (c--) {
    solve();
  }
}
