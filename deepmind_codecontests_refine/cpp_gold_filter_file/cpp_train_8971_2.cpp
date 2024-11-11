#include <bits/stdc++.h>
using namespace std;
const int maxn = 200007;
int a[maxn];
int R[maxn];
int L[maxn];
int n, m;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (m); ++i) cin >> a[i];
  if (n == 1) return cout << 0 << endl, 0;
  map<int, int> stop;
  for (int i = (m); i >= (1); --i) {
    if (stop.count(a[i] - 1 - i) == 0)
      R[i] = min(a[i] - 1 + (m - i + 1), n);
    else
      R[i] = R[stop[a[i] - 1 - i]];
    stop[a[i] - i] = i;
  }
  stop.clear();
  for (int i = (m); i >= (1); --i) {
    if (stop.count(a[i] + 1 + i) == 0)
      L[i] = max(a[i] + 1 - (m - i + 1), 1);
    else
      L[i] = L[stop[a[i] + 1 + i]];
    stop[a[i] + i] = i;
  }
  long long ans = 0;
  map<int, int> Laid;
  map<int, int> Raid;
  for (int i = (m); i >= (1); --i) Raid[a[i] - i] = i;
  for (int i = (m); i >= (1); --i) Laid[a[i] + i] = i;
  for (int i = (1); i <= (n); ++i) {
    long long nowl, nowr;
    nowl = nowr = 0;
    if (Raid.count(i) == 0)
      nowr += min(n, i + m + 1) - i;
    else
      nowr = R[Raid[i]] - i;
    if (Laid.count(i) == 0)
      nowl += i - max(1, i - m - 1);
    else
      nowl = i - L[Laid[i]];
    ans += nowr + nowl + 1;
  }
  cout << ans << endl;
  return 0;
}
