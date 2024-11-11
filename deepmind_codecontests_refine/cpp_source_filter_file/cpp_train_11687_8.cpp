#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << "shit" << endl;
  exit(1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(10);
  int T;
  cin >> T;
  while (T--) {
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ok = 1;
    vector<int> f(n + 2);
    f[0] = -k;
    for (int i = 1; i < n + 1; i++) {
      if (f[i - 1] >= 0 && f[i - 1] < k) {
        if (a[i] + f[i - 1] + 1 > l) {
          ok = 0;
          break;
        }
        f[i] = f[i - 1] + 1;
        if (a[i] + k <= l) {
          f[i] = -k;
        }
      } else {
        if (a[i] > l) {
          ok = 0;
          break;
        }
        f[i] = a[i] - f[i - 1] - 1 <= l ? f[i - 1] + 1 : l - a[i];
        if (a[i] + k <= l) {
          f[i] = -k;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
