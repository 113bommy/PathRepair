#include <bits/stdc++.h>
using namespace std;
const long long int N = 100005;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, i, z, n, k, j, p;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    long long int arr[n + 1];
    z = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        arr[z] = i;
        z++;
      }
    }
    for (i = 0; i < z; i++) {
      if (k == 0) break;
      p = arr[i];
      arr[i] = max(i, arr[i] - k);
      k = k - (p - arr[i]);
    }
    p = 0;
    for (i = 0; i < n; i++) {
      if (i < z) {
        if (arr[p] == i) {
          p++;
          cout << 0;
        } else
          cout << 1;
      } else
        cout << 1;
    }
    cout << endl;
  }
  return 0;
}
