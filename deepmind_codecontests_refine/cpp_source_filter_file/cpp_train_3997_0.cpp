#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
long long n, m, k, arr[N], l[N], r[N], d[N], mp[N], mp2[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  for (long long i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }
  while (k--) {
    long long x, y;
    cin >> x >> y;
    mp[x]++;
    mp[y + 1]--;
  }
  for (long long i = 1; i <= m; i++) mp[i] += mp[i - 1];
  for (long long i = 1; i <= m; i++) {
    mp2[l[i]] += mp[i] * d[i];
    mp2[r[i] + 1] -= mp[i] * d[i];
  }
  for (long long i = 1; i <= N; i++) {
    mp2[i] += mp2[i - 1];
  }
  for (long long i = 1; i <= n; i++) cout << arr[i] + mp2[arr[i]] << " ";
  return 0;
}
