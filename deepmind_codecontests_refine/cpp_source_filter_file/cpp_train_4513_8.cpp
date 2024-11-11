#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 200 * 1000 + 23;
long long n, x = -1, pos[MAXN];
pair<long long, long long> a[MAXN];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i].first;
  for (long long i = 0; i < n; i++) cin >> a[i].second, pos[a[i].second] = i;
  for (long long i = 0; i < n; i++)
    if (x < pos[a[i].first])
      x = pos[a[i].first];
    else
      return cout << n - i, 0;
  cout << n;
  return 0;
}
