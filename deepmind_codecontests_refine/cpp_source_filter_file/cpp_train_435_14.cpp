#include <bits/stdc++.h>
using namespace std;
long long check(string a, string b) {
  for (long long i = 0; i < min(a.size(), b.size()); i++) {
    if (a[i] > b[i])
      return 0;
    else if (a[i] < b[i])
      return 1;
  }
  if (a.size() < b.size())
    return 1;
  else
    return 0;
}
void solve() {
  string a, b;
  cin >> a >> b;
  long long n = a.size(), m = b.size();
  for (long long i = 0; i < n; i++) {
    char mn = a[i];
    long long idx = i;
    for (long long j = i; j < n; j++) {
      if (a[j] < mn) {
        mn = a[j];
        idx = j;
      }
    }
    swap(a[i], a[idx]);
    if (check(a, b)) {
      cout << a << '\n';
      return;
    }
    swap(a[i], a[idx]);
  }
  cout << "---" << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  long long id = 1;
  while (t--) {
    solve();
    id++;
  }
  return 0;
}
