#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
long long n, m;
long long a[N], b[N];
pair<long long, long long> p[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> p[i].first >> p[i].second;
  sort(p + 1, p + m + 1);
  for (int i = 1; i <= m; i++) b[i] = b[i - 1] + p[i].second;
  for (int i = 1; i <= n; i++) {
    long long l = 1, r = n;
    long long x = a[i];
    while (l <= r) {
      int mid = (l + r) / 2;
      if (x >= p[mid].first)
        l = mid + 1;
      else {
        r = mid - 1;
      }
    }
    if (l > m || p[l].first > x)
      l--;
    else if (p[l + 1].first <= x && l < m)
      l++;
    cout << b[l] << " ";
  }
}
