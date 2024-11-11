#include <bits/stdc++.h>
using namespace std;
const long long nax = 1e5 + 5;
vector<long long> adj[nax];
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 7;
long long a[301][301];
signed main() {
  long long n;
  cin >> n;
  long long j = 1;
  long long k = 1;
  long long i = n * n;
  long long f = 0;
  while (i >= 1) {
    long long cnt = 1;
    if (f == 0) {
      k = 1;
      while (cnt <= n) {
        a[j][k] = i;
        i--;
        cnt++;
        k++;
      }
      f = 1;
    } else if (f == 1) {
      k = n;
      while (cnt <= n) {
        a[j][k] = i;
        i--;
        cnt++;
        k--;
      }
      f = 0;
    }
    j++;
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      cout << a[j][i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
