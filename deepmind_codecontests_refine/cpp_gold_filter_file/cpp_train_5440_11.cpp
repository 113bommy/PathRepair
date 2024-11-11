#include <bits/stdc++.h>
using namespace std;
long long n, p;
vector<long long> a, z, w;
bool ok(int j) {
  for (int i = 0; i < n; ++i)
    if (w[i + j] >= p + i) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> p;
  a.resize(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  w.resize(2 * n);
  long long x = a.back() - n;
  for (long long i = 0; i < 2 * n; ++i)
    w[i] = upper_bound(a.begin(), a.end(), x + i) - a.begin();
  int fr = 1;
  for (int i = 1; i < 2 * n; ++i)
    if (w[i] < n) fr = max(fr, i + 1 - (int)w[i]);
  int l = 0;
  int r = n + 1;
  while (r - l > 1) {
    int m = (r + l) / 2;
    (ok(m) ? l : r) = m;
  }
  int to = l;
  cout << max(0, to - fr + 1) << "\n";
  for (long long i = fr; i <= to; ++i) cout << x + i << " ";
  cout << "\n";
  return 0;
}
