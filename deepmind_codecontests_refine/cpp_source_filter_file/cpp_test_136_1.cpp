#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void Solve() {
  i64 n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  i64 sum = accumulate(b.begin(), b.end(), 0ll);
  if (sum % (n * (n + 1) / 2) != 0) {
    cout << "NO\n";
    return;
  }
  i64 c = sum / (n * (n + 1) / 2);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    i64 x = c - b[i] + b[(i - 1 + n) % n];
    if (x == 0 || x % n != 0) {
      cout << "NO\n";
      return;
    }
    a[i] = x / n;
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
}
