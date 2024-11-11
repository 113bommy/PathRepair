#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  ll res = a[n / 2] - s;
  if (res < 0) res = -res;
  for (int i = 0; i < n / 2 - 1; ++i) {
    if (a[i] > s) res += a[i] - s;
  }
  for (int i = n / 2 + 1; i < n; ++i) {
    if (a[i] < s) res += s - a[i];
  }
  cout << res << '\n';
  return 0;
}
