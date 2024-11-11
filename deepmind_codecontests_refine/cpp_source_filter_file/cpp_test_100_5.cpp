#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int p[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    sort(p, p + n);
    int ans = p[1];
    for (int i = 2; i <= n; i++) ans = max(p[i] - p[i - 1], ans);
    cout << ans << endl;
  }
  return 0;
}
