#include <bits/stdc++.h>
using namespace std;
bool g[100000000];
int main() {
  long long n;
  cin >> n;
  long long m, k;
  cin >> m >> k;
  long long u[m + 1];
  long long v[m + 1];
  long long l[m + 1];
  for (long long i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> l[i];
  }
  long long a[k + 1];
  for (long long i = 1; i <= k; i++) {
    cin >> a[i];
    g[a[i]] = true;
  }
  long long mx = 10000000000;
  for (long long i = 1; i <= m; i++) {
    if ((g[v[i]] || g[u[i]]) && mx > l[i]) {
      if (g[v[i]] && g[u[i]]) {
        continue;
      } else {
        mx = l[i];
      }
    }
  }
  if (mx == 10000000000) {
    cout << -1;
  } else {
    cout << mx;
  }
}
