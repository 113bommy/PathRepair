#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n % 2 == 0)
      cout << "YES" << '\n';
    else {
      int cnt = 0;
      for (int i = 1; i <= n - 1; i++) {
        if (a[i] > a[i + 1]) cnt = 1;
      }
      if (cnt)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
}
