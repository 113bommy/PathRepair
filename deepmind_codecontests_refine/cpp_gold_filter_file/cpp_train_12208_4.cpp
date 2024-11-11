#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    total += h[i];
  }
  vector<long long> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = i;
  }
  long long s = n * (n - 1) / 2LL;
  total -= s;
  long long v = total / n;
  for (int i = 0; i < n; ++i) {
    res[i] += v;
  }
  long long u = total % n;
  for (int i = 0; i < u; ++i) {
    ++res[i];
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  t = 1;
  for (int tt = 0; tt < t; ++tt) {
    solve();
  }
  return 0;
}
