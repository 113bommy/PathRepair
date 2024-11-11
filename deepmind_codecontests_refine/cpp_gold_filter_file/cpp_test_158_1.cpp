#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 1e6 + 100;
const long long mod = 998244353;
const long long big = 1e17;
long long t, n, m;
string a[N];
pair<long long, long long> c[N];
int x[N], d[N], e[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = -1e10;
    for (int j = 0; j < (1 << n); j++) {
      for (int i = 0; i < m; i++) c[i] = make_pair(0, i), d[i] = 0;
      long long sum = 0;
      for (int i = 0; i < n; i++) {
        if ((1 << i) & j) {
          sum += x[i];
          for (int k = 0; k < m; k++) {
            if (a[i][k] == '1') c[k].first--;
          }
        } else {
          sum -= x[i];
          for (int k = 0; k < m; k++)
            if (a[i][k] == '1') c[k].first++;
        }
      }
      sort(c, c + m);
      for (int i = 0; i < m; i++)
        d[c[i].second] = i + 1, sum = sum + c[i].first * (i + 1);
      bool t = 1;
      for (int i = 0; i < n; i++) {
        long long sum2 = 0;
        for (int k = 0; k < m; k++)
          if (a[i][k] == '1') sum2 += d[k];
        if (((1 << i) & j) && sum2 > x[i]) t = 0;
        if ((!((1 << i) & j)) && sum2 < x[i]) t = 0;
      }
      if (t && (sum > ans)) {
        ans = sum;
        for (int j = 0; j < m; j++) e[j] = d[j];
      }
    }
    for (int i = 0; i < m; i++) cout << e[i] << " ";
    cout << '\n';
  }
}
