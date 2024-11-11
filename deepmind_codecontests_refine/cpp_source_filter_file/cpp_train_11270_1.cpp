#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<int> yes(1);
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int greatest = 0;
    int smallest = 0;
    for (int i = 1; i < n; ++i) {
      b[i - 1] = a[i] - a[i - 1];
    }
    if (b[0] > 0 && b[1] < 0) {
      cout << "YES" << '\n' << 1 << ' ' << 2 << ' ' << 3 << '\n';
    } else {
      bool yes = 0;
      int q = n - 2;
      if (b[n - 2] < 0) {
        q = n - 1;
      }
      for (int i = 1; i < q; ++i) {
        if (b[i] > b[i - 1] && b[i + 1] < 0) {
          cout << "YES" << '\n'
               << i + 1 << ' ' << i + 2 << ' ' << i + 3 << '\n';
          yes = 1;
          break;
        }
      }
      if (yes == 0) {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
