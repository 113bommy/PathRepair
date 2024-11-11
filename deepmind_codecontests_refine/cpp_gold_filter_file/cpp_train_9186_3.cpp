#include <bits/stdc++.h>
const long long int INF = LONG_MAX;
const int N = 2e5 + 5;
const long long int mod = 1000000007;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int tc = 1;
  while (tc--) {
    long long int m;
    long long int i, j;
    long long int n;
    long long int k;
    cin >> n;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long int ans = 0;
    if (n == 1) {
      cout << a[0] << endl;
      return 0;
    }
    if (n == 2) {
      cout << (a[0] | a[1]) << endl;
      return 0;
    }
    for (i = 0; i < n - 2; i++)
      for (j = i + 1; j < n - 1; j++)
        for (k = j + 1; k < n; k++) ans = max(ans, a[i] | a[j] | a[k]);
    cout << ans << endl;
  }
}
