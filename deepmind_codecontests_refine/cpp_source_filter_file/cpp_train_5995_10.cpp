#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x;
  cin >> n >> k >> x;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (k == 0) {
    cout << a[n - 1] << " " << a[0] << "\n";
    return;
  }
  long long rem = k % 10;
  for (long long i = 0; i < rem; i++) {
    sort(a, a + n);
    for (long long i = 0; i < n; i += 2) {
      a[i] ^= x;
    }
  }
  sort(a, a + n);
  cout << a[n - 1] << " " << a[0] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::ios::sync_with_stdio(false);
  long long te = 1;
  while (te--) {
    solve();
  }
}
