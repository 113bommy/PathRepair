#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int i = 1;
    long long s = 0;
    while (i <= n) {
      if (a[i] > 0) {
        s += a[i];
      } else if (a[i] < 0) {
        if (s + a[i] > 0) {
          s = s + a[i];
          a[i] = 0;
        } else {
          a[i] = s + a[i];
          s = 0;
        }
      }
      ++i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] < 0) {
        ans += a[i];
      }
    }
    cout << abs(ans) << "\n";
  }
}
