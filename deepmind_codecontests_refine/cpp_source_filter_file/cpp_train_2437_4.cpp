#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long x = a[0], y = a[n - 1];
  cout << a[n] << " ";
  for (long long i = 1; i < n - 1; ++i) {
    cout << a[i] << " ";
  }
  cout << a[0] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
