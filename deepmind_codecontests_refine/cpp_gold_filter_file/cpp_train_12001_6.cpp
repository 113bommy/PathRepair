#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < (n); ++i) {
      cin >> a[i];
    }
    if (*max_element((a).begin(), (a).end()) > k) {
      cout << "0"
           << "\n";
      continue;
    }
    int mini = *min_element((a).begin(), (a).end());
    for (int i = 0; i < (n); ++i) {
      a[i] = k - a[i];
    }
    int res = 0;
    for (int i = 0; i < (n); ++i) {
      res += (a[i] / mini);
    }
    res -= (k - mini) / mini;
    cout << res << "\n";
  }
  return 0;
}
