#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    int j = 0, part = 0;
    for (j = 1; j < n; j++) {
      if (a[j - 1].second + 1 != a[j].second) {
        part++;
      }
    }
    if (part <= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
