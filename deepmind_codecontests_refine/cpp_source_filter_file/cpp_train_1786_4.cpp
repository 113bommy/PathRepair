#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, ta, tb, k;
  cin >> n >> k;
  long long int a[k];
  map<long long int, long long int> cnt;
  long long int f[n + 1], l[n + 1];
  for (int i = 0; i <= n; i++) {
    f[i] = n + 10;
    l[i] = -5;
  }
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) f[a[i]] = i + 1;
    l[a[i]] = i + 1;
  }
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] == 0) ans++;
    if (i < n) {
      long long int t1 = i;
      long long int t2 = i + 1;
      if (l[t1] < f[t2]) ans++;
      if (l[t2] < f[t1]) ans++;
    }
  }
  cout << ans << endl;
}
