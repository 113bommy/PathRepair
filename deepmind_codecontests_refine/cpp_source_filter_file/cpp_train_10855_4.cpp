#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, N = 4e5 + 10;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long req;
  if (sum % n != 0) {
    cout << "-1\n";
    return;
  }
  req = sum / n;
  long long op = 0;
  vector<tuple<long long, long long, long long>> save;
  for (long long i = 1; i < n; i++) {
    long long diff = 0;
    if (a[i] % (i + 1) != 0) diff = (i + 1) - (a[i] % (i + 1));
    save.push_back({1, i + 1, diff});
    a[0] = a[0] - diff;
    a[i] = a[i] + diff;
    long long q = a[i] / (i + 1);
    save.push_back({i + 1, 1, q});
    a[0] += a[i];
    a[i] = 0;
    op = op + 2;
  }
  for (long long i = 1; i < n; i++) {
    save.push_back({1, i, req});
    op++;
    a[0] = a[0] - req;
    a[i] = a[i] + req;
  }
  cout << op << "\n";
  for (long long i = 0; i < save.size(); i++) {
    cout << get<0>(save[i]) << " " << get<1>(save[i]) << " " << get<2>(save[i])
         << "\n";
  }
  return;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
}
