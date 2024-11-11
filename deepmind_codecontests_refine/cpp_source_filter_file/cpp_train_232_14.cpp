#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    cout << -a[0] << endl;
    int k = 2;
    while (k--) {
      cout << 1 << " " << 1 << endl;
      cout << 0 << endl;
    }
  } else {
    cout << 1 << " " << 1 << endl;
    cout << (n - 1) * a[0] << endl;
    a[0] = n * a[0];
    cout << 2 << " " << n << endl;
    for (int i = 1; i < n; i++) {
      cout << a[i] * (n - 1) << " ";
      a[i] += a[i] * (n - 1);
    }
    cout << endl;
    cout << 1 << " " << 4 << endl;
    for (int i = 0; i < n; i++) {
      cout << -a[i] << " ";
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
