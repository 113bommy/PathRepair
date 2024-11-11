#include <bits/stdc++.h>
using namespace std;
const int mxn = 2000001;
int n;
long long a[mxn], b[mxn];
void answer() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    b[i + n] = b[i];
  }
  for (long long i = 2, j = 0x3f3f3f3f3f3f3f3f; i <= 2 * n; i++) {
    a[i] += a[i - 1], b[i] += b[i - 1];
    j = min(j, a[i - 1] - b[i - 2]);
    if (a[i] - b[i] > j) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << (a[n] < b[n] ? "YES" : "NO") << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) answer();
  return 0;
}
