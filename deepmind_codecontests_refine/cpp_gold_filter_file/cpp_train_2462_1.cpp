#include <bits/stdc++.h>
using namespace std;
long long f[500005];
long long dep[500005];
long long cnt[500005];
int main() {
  long long n, ans = 0;
  cin >> n;
  cnt[1] = 1;
  dep[1] = 1;
  for (long long i = 2; i <= n; i++) {
    cin >> f[i];
    dep[i] = dep[f[i]] + 1;
    cnt[dep[i]]++;
  }
  for (long long i = 1; i <= n; i++)
    if (cnt[i] % 2) ans++;
  cout << ans << endl;
  return 0;
}
