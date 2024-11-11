#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 0; i < n; i++) cin >> a[i];
    int MAXN = *max_element(a.begin(), a.end());
    bool done = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == MAXN &&
          ((a[i + 1] < MAXN && i + 1 < n) || (a[i - 1] < MAXN && i - 1 >= 0))) {
        cout << i + 1 << "\n";
        done = true;
        break;
      }
    }
    if (!done) cout << -1 << "\n";
  }
  return 0;
}
