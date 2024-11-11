#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, a[200005], b[200005], j, count = 0;
  cin >> n;
  for (i = 0; i < n - 1; i++) {
    cin >> a[i] >> b[i];
  }
  long long int c[200005];
  for (i = 1; i <= n; i++) {
    cin >> c[i];
  }
  long long int ans = a[0];
  map<long long int, long long int> freq;
  for (i = 0; i < n - 1; i++) {
    if (c[a[i]] != c[b[i]]) {
      count++;
      freq[a[i]]++;
      freq[b[i]]++;
      if (freq[a[i]] != count && freq[b[i]] != count) {
        cout << "NO" << endl;
        return (0);
      }
      if (freq[a[i]] == count) {
        ans = a[i];
      }
      if (freq[b[i]] == count) {
        ans = b[i];
      }
    }
  }
  cout << "YES" << endl;
  cout << ans << endl;
}
