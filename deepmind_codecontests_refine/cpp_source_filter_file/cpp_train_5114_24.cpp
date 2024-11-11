#include <bits/stdc++.h>
using namespace std;
long long a[150];
void solve() {
  long long n, ans = 0;
  cin >> n;
  for (long long i = 0; i <= n - 1; ++i) cin >> a[i];
  long long i = 1;
  while (i < n - 2) {
    if ((a[i - 1] == a[i + 1]) && (a[i - 1] == 1) && (a[i] == 0)) {
      ans++;
      i = i + 3;
    } else
      i++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
