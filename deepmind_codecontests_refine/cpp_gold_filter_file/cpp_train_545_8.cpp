#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
using pii = pair<int, int>;
using vi = vector<int>;
const long int N = 1.1e5;
long long a[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << 1 << " " << max(1, n - 1) << '\n';
  for (int i = 0; i < max(1, n - 1); i++) {
    cout << a[i] * (n - 1) << " ";
  }
  cout << '\n';
  cout << n << " " << n << '\n';
  cout << (n - 1) * a[n - 1];
  cout << "\n";
  cout << 1 << " " << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << -a[i] * n << " ";
  }
}
int main(void) {
  solve();
  return 0;
}
