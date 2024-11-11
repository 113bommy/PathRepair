#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int numneg = 0, num0 = 0;
    vector<int> a;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        ans += abs(x);
        if (x < 0) numneg++;
        if (x == 0) num0++;
        a.push_back(x);
      }
    if (num0 == 0 && numneg % 2 == 1) {
      sort(a.begin(), a.end());
      ans -= 2 * abs(a[0]);
    }
    cout << ans << endl;
  }
  return 0;
}
