#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << "1 " << n << '\n';
  for (int i = 0; i < n; ++i) cout << -1ll * n * a[i] << ' ';
  cout << '\n';
  if (n > 1) {
    cout << "1 " << n - 1 << '\n';
    for (int i = 0; i < n - 1; ++i) cout << 1ll * (n - 1) * a[i] << ' ';
  } else {
    cout << "1 1\n0";
  }
  cout << '\n';
  cout << n << ' ' << n << '\n';
  cout << 1ll * (n - 1) * a[n - 1];
  return 0;
}
