#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long MAXP = 2e18;
int n, k;
long long a[N + 5];
vector<long long> v;
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  long long ans = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++)
    if (a[i] != 1) v.push_back(i);
  v.push_back(n + 1);
  for (int i = 1; i <= n; i++) {
    long long p = 1, s = 0;
    int j = i;
    while (j <= n) {
      if (p >= MAXP / a[j]) break;
      p *= a[j];
      s += a[j];
      if (p == s * k) ans++;
      int pt = upper_bound(v.begin(), v.end(), j) - v.begin();
      int nxt = v[pt];
      int cnt_1 = nxt - 1 - j;
      if (cnt_1 > 0 && p % k == 0 && (p / k - s) <= cnt_1 && (p / k - s) > 0)
        ans++;
      s += cnt_1;
      j = nxt;
    }
  }
  cout << ans << '\n';
  return 0;
}
