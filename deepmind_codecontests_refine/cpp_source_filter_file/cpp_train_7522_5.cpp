#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] < 0)
        ans += -a[i];
      else
        a[i + 1] += a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
