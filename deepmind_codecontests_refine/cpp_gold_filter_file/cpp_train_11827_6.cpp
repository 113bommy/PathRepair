#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 1e5 + 5;
long long a[maxn];
long long s[maxn];
long long ts[maxn];
long long m;
int n;
long long check(long long v) {
  for (int i = 1; i <= n; ++i) ts[i] = v * i + a[i];
  sort(ts + 1, ts + n + 1);
  long long sum = 0;
  for (int i = 1; i <= v; ++i) sum += ts[i];
  if (sum <= m)
    return sum;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int i, j, k;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  long long sum = 0;
  sum = check(r);
  if (sum)
    cout << r << " " << sum;
  else {
    sum = check(l);
    cout << l << " " << sum;
  }
  return 0;
}
