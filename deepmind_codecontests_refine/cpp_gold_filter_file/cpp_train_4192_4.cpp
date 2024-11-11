#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int b[k];
    vector<long long int> b1;
    long long int l1 = 0;
    for (long long int i = 0; i < k; i++) {
      cin >> b[i];
      b[i]--;
      if (b[i] == 0) l1++;
      if (b[i] > 0) {
        b1.push_back(b[i]);
      }
    }
    sort(b1.begin(), b1.end(), greater<long long int>());
    long long int ans = 0;
    sort(a, a + n, greater<long long int>());
    for (long long int i = 0; i < k; i++) {
      if (i < l1) {
        ans += 2 * a[i];
      } else
        ans += a[i];
    }
    sort(a, a + n);
    long long int ans1 = 0;
    long long int l = 0;
    for (long long int i = 0; i < b1.size(); i++) {
      ans1 += a[l];
      l += b1[i];
    }
    cout << ans + ans1 << endl;
  }
}
