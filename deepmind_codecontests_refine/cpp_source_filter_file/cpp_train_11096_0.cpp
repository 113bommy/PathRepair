#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &s : a) scanf("%ld", &s);
  vector<long long> b(n - 1);
  for (int i = 0; i < n - 1; i++) {
    b[i] = abs(a[i] - a[i + 1]);
  }
  long long ans = 0, sum = 0;
  for (int i = 0; i < n - 1; i++) {
    if (i % 2 == 0) {
      sum += b[i];
    } else {
      sum -= b[i];
    }
    ans = max(ans, sum);
    if (sum < 0) sum = 0;
  }
  sum = 0;
  for (int i = 1; i < n - 1; i++) {
    if (i % 2 == 0) {
      sum -= b[i];
    } else {
      sum += b[i];
    }
    ans = max(ans, sum);
    if (sum < 0) sum = 0;
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  while (t--) solve();
}
