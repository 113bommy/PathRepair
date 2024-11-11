#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  long long nows = n * (n + 1) / 2;
  for (long long i = 0; i < n / 2; i++) {
    if (nows - a[i] + a[n - i - 1] < k) {
      nows = nows - a[i] + a[n - i - 1];
      swap(a[i], a[n - i - 1]);
    } else {
      long long id = -1;
      long long maxi = -1;
      for (long long j = i + 1; j <= n - i - 1; j++) {
        if (nows - a[i] + a[j] <= k) {
          if (nows - a[i] + a[j] > maxi) {
            maxi = nows - a[i] + a[j];
            id = j;
          }
        }
      }
      if (id != -1) swap(a[i], a[id]);
      long long anus = 0;
      for (long long i = 0; i < n; i++) {
        anus += max(a[i], i + 1);
      }
      if (maxi == -1) {
        cout << -1;
        return 0;
      }
      cout << maxi << endl;
      for (long long i = 0; i < n; i++) {
        cout << i + 1 << ' ';
      }
      cout << endl;
      for (long long i = 0; i < n; i++) {
        cout << a[i] << ' ';
      }
      cout << endl;
      return 0;
    }
  }
  cout << nows << endl;
  for (long long i = 0; i < n; i++) cout << i + 1 << ' ';
  cout << endl;
  for (long long i = 0; i < n; i++) cout << a[i] << ' ';
  return 0;
}
