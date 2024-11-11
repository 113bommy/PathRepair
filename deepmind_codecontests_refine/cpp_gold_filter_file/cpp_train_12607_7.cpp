#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, t;
  cin >> n >> t;
  vector<long long> a(n);
  vector<long long> x(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> x[i];
  if (x[0] < 1) {
    cout << "No\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (x[i - 1] > x[i] || x[i] < (i + 1)) {
      cout << "No\n";
      return 0;
    }
  }
  vector<long long> b(n);
  b[n - 1] = a[n - 1] + t + 1000000;
  for (int i = n - 2; i >= 0; i--) b[i] = a[i + 1] + t - ((i + 1) == x[i]);
  for (int i = 0; i < n - 1; i++) {
    if (b[i] == b[i + 1] || (x[i] < x[i + 1] && (x[i] != (i + 1)))) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  for (auto elem : b) cout << elem << ' ';
  cout << '\n';
  return 0;
}
