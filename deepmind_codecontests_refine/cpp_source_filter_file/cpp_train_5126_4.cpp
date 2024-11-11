#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    map<int, int> m;
    for (int i = 0; i < n; i++) m[a[i]] = 1;
    for (int i = 1; i <= 101; i++) {
      if (m[i] == 0 && x > 0) {
        m[i] = 1;
        x--;
      }
    }
    int ans = 1;
    for (int i = 1; i <= 109; i++) {
      if (m[i] == 0) break;
      ans = i;
    }
    cout << ans << endl;
  }
}
