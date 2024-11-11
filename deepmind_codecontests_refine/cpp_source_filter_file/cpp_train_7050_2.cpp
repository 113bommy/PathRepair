#include <bits/stdc++.h>
using namespace std;
long double maxval = 2000000000000000000.0;
int ans = 0;
bool check(long double p, long double x) {
  return (p > (long double)maxval / x);
}
void valid(long long int p, long long int s, int k) {
  if (p == s * k) ans++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, j;
  cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i < n + 1; i += 1) cin >> a[i];
  vector<int> streak(n + 1, 0);
  if (a[n] == 1) streak[n] = 1;
  for (int i = n - 1; i > 0; i--)
    if (a[i] == 1) streak[i] = streak[i + 1] + 1;
  long long int p, s;
  for (int i = 1; i < n + 1; i += 1) {
    p = 1, s = 0, j = i;
    while (j < n + 1) {
      if (a[j] != 1) {
        if (!check((long double)p, (long double)a[i])) {
          p *= a[j], s += a[j], j++;
          valid(p, s, k);
        } else
          break;
      } else {
        if (p % k == 0 && s < p / k && s + streak[j] >= p / k) ans++;
        s += streak[j];
        j += streak[j];
      }
    }
  }
  cout << ans << '\n';
}
