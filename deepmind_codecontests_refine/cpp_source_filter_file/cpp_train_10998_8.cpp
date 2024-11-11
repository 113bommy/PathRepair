#include <bits/stdc++.h>
using namespace std;
long long i;
vector<long long> tab, a, pref, ans, sisa;
long long n;
int main() {
  cin >> n;
  tab.assign(n + 10, 0);
  a.assign(n + 10, 0);
  pref.assign(n + 10, 0);
  ans.assign(n + 10, 0);
  sisa.assign(n + 10, 0);
  for (long long i = 0; i < n; i++) cin >> tab[i];
  for (long long i = 0; i < n; i++) cin >> a[i];
  pref[0] = a[0];
  for (long long i = 1; i < n + 10; i++) pref[i] = pref[i - 1] + a[i];
  for (long long i = 0; i < n; i++) {
    long long atas = floor(log2(n - i));
    long long now = i;
    for (long long j = atas; j > -1; j--) {
      if (now + (1LL << j) > n) continue;
      if (tab[i] > pref[now + (1LL << j) - 1] - (i > 0 ? pref[i - 1] : 0)) {
        now += (1LL << j);
      }
    }
    ans[i]++;
    ans[now]--;
    sisa[now] +=
        tab[i] - ((i > 0 ? pref[now - 1] : 0) - (i > 0 ? pref[i - 1] : 0));
  }
  for (long long i = 1; i < n + 10; i++) ans[i] += ans[i - 1];
  for (long long i = 0; i < n - 1; i++) cout << ans[i] * a[i] + sisa[i] << " ";
  cout << ans[n - 1] * a[n - 1] + sisa[n - 1] << endl;
  return 0;
}
