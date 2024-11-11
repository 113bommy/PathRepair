#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    long long int n, x;
    cin >> n >> x;
    long long int a[n], b[n];
    vector<long long int> v(100005, 0);
    bool ch = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (v[a[i]] > 0) ch = 1;
      v[a[i]]++;
      b[i] = a[i] & x;
    }
    if (ch) {
      cout << 0;
      return 0;
    }
    sort(a, a + n);
    vector<long long int> v2(100005, 0);
    for (long long int i = n - 1; i >= 0; i--) {
      long long int k = a[i] & x;
      v[a[i]]--;
      v2[k]++;
      if (v[k] > 0) {
        cout << 1;
        return 0;
      }
    }
    for (long long int i = 0; i < 100004; i++) {
      if (v2[i] > 1) {
        cout << 2;
        return 0;
      }
    }
    cout << -1;
  }
}
