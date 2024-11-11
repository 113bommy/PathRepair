#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long inf = 2e18;
long long a[N], kol[N], n, m, ans;
stack<long long> g[N];
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    cin >> a[i], kol[a[i] % m]++, g[a[i] % m].push(i);
  long long pos = -1;
  for (long long i = 1; i <= m; i++)
    if (kol[i - 1] < n / m) {
      pos = i - 1;
      break;
    }
  if (pos == -1) {
    cout << "0\n";
    for (long long i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
  }
  long long cur = 0;
  stack<long long> q;
  for (long long i = 0; i < m; i++)
    if (kol[i] > n / m) q.push(i);
  long long ans = 0;
  for (long long i = 0; i < m; i++)
    if (kol[i] > n / m)
      q.push(i);
    else {
      while (kol[i] < n / m) {
        long long pos = q.top();
        long long del;
        if (pos > i)
          del = m - i + pos;
        else
          del = i - pos;
        if (g[pos].size() - n / m <= n / m - kol[i]) {
          q.pop();
          while (g[pos].size() != n / m) {
            long long c = g[pos].top();
            g[pos].pop();
            a[c] += del;
            kol[i]++;
            ans += del;
          }
        } else {
          while (kol[i] != n / m) {
            kol[i]++;
            long long c = g[pos].top();
            g[pos].pop();
            a[c] += del;
            ans += del;
          }
        }
      }
    }
  cout << ans << endl;
  for (long long i = 1; i <= n; i++) cout << a[i] << ' ';
  return 0;
}
