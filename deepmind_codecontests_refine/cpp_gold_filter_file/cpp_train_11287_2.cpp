#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long int> a(n), d(n);
  for (int i = (0); i <= (n - 1); i++) cin >> a[i];
  sort(a.begin(), a.end());
  if (n == 1) {
    cout << "-1";
    return;
  }
  set<int> ss;
  if (n == 2) {
    ss.insert(2 * a[0] - a[1]);
    ss.insert(2 * a[1] - a[0]);
    if ((a[0] + a[1]) % 2 == 0) ss.insert((a[0] + a[1]) / 2);
  } else {
    for (int i = (1); i <= (n - 1); i++) d[i] = a[i] - a[i - 1];
    sort(d.begin() + 1, d.end());
    if (d[1] == d[n - 1]) {
      ss.insert(2 * a[0] - a[1]);
      ss.insert(2 * a[n - 1] - a[n - 2]);
    } else {
      long long int cd = 0;
      bool ok = false;
      if (d[1] == d[n - 2] && 2 * d[n - 2] == d[n - 1]) {
        ok = true;
        cd = d[1];
      }
      if (ok) {
        for (int i = (1); i <= (n - 1); i++) {
          if (a[i] - a[i - 1] == 2 * cd) ss.insert(a[i - 1] + cd);
        }
      }
    }
  }
  cout << ((int)ss.size()) << '\n';
  for (auto v : ss) cout << v << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(8);
  clock_t b = clock();
  solve();
  clock_t e = clock();
  cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
  return 0;
}
