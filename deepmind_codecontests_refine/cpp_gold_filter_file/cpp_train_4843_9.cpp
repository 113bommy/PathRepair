#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> ar[100005];
long long suf[100007] = {0}, pre[100007] = {0}, sbkoya[100007] = {0},
          arr[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  long long n, a, cf, cm, m, temp, revi, cnt = 0;
  cin >> n >> a >> cf >> cm >> m;
  for (long long i = 0; i < n; ++i) {
    cin >> temp;
    if (temp == a) cnt++;
    ar[i] = make_pair(temp, i);
  }
  if (cf == 0 && cm == 0) {
    cout << "0" << endl;
    for (long long i = 0; i < n; ++i) cout << ar[i].first << " ";
    return 0;
  }
  sort(ar, ar + n);
  long long i;
  for (i = n - 1; i >= 0; i--) {
    long long tmp = suf[i + 1] + a - ar[i].first;
    if (tmp > m) break;
    suf[i] = tmp;
  }
  revi = i + 1;
  for (long long i = 0; i < n; ++i) {
    if (i == 0)
      pre[i] = ar[i].first;
    else
      pre[i] = pre[i - 1] + ar[i].first;
  }
  for (long long i = 1; i < n; ++i) {
    sbkoya[i] = (ar[i].first) * (i + 1) - pre[i];
  }
  if (sbkoya[n - 1] + n * (a - ar[n - 1].first) <= m) {
    cout << n * cf + a * cm << endl;
    for (long long i = 0; i < n; ++i) cout << a << " ";
    return 0;
  }
  long long j, ans = 0, indj, indk, remain, mini, k, rem, mi, tmp;
  rem = m;
  k = upper_bound(sbkoya, sbkoya + n, rem) - sbkoya;
  k--;
  rem -= sbkoya[k];
  mi = (ar[k].first) + rem / (k + 1);
  tmp = mi * cm + cf * cnt;
  ans = tmp;
  indk = k;
  indj = n;
  remain = rem;
  mini = mi;
  for (j = n - 1; j >= revi; j--) {
    tmp = cf * max(n - j, cnt);
    rem = m - suf[j];
    k = upper_bound(sbkoya, sbkoya + n, rem) - sbkoya;
    k--;
    if (k >= j) k = j - 1;
    rem -= sbkoya[k];
    mi = (ar[k].first) + rem / (k + 1);
    tmp += mi * cm;
    if (tmp >= ans) {
      ans = tmp;
      indk = k;
      indj = j;
      remain = rem;
      mini = mi;
    }
  }
  cout << ans << endl;
  long long du;
  for (du = n - 1; du >= indj; du--) ar[du].first = a;
  long long ka = remain % (k + 1);
  for (du = indk; du >= 0; du--) {
    ar[du].first = mini;
  }
  for (long long i = 0; i < n; ++i) {
    arr[ar[i].second] = ar[i].first;
  }
  for (long long i = 0; i < n; ++i) cout << arr[i] << " ";
  return 0;
}
