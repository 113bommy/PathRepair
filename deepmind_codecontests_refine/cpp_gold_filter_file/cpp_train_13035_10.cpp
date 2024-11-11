#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, s, k;
    cin >> n >> s >> k;
    int arr[k];
    map<int, int> m;
    for (int i = 0; i < k; i++) {
      int a;
      cin >> a;
      m[a]++;
    }
    int ans = INT_MAX;
    int i = s;
    while (i > 0) {
      if (m.find(i) != m.end())
        i--;
      else
        break;
    }
    if (i != 0) ans = s - i;
    i = s;
    while (i <= n) {
      if (m.find(i) != m.end())
        i++;
      else
        break;
    }
    if (i != n + 1) ans = min(ans, (i - s));
    cout << ans << "\n";
  }
}
