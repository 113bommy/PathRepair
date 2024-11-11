#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int i = a[0];
    int k = a[n - 1];
    for (int j = 1; j < n - 1; ++j) {
      if (i + a[j] <= k) {
        cout << 1 << " " << j + 1 << " " << n;
        break;
      } else if (i + a[j] > k) {
        cout << -1;
        break;
      }
    }
    cout << endl;
  }
}
