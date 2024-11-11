#include <bits/stdc++.h>
using namespace std;
long long int tot;
long long int maxx;
long long int ans;
long long int a[1034];
void dfs(long long int i, long long int curr) {
  long long int l, r;
  l = 2 * i;
  r = l + 1;
  if (maxx < curr) {
    maxx = curr;
  }
  if (l < tot) {
    dfs(l, curr + a[l]);
    dfs(r, curr + a[r]);
  }
}
long long int dfs1(long long int i, long long int curr) {
  long long int l, r;
  l = 2 * i;
  r = l + 1;
  if (l >= tot) {
    return maxx - curr;
  } else {
    long long int ll = dfs1(l, curr + a[l]);
    long long int rr = dfs1(r, curr + a[r]);
    long long int diff = abs(ll - rr);
    long long int d = max((ll - diff), (rr - diff));
    ans += (diff);
    return d;
  }
}
int main() {
  long long int n, i, j, k;
  cin >> n;
  tot = (long long int)pow((double)2, (double)(1 + n));
  for (i = 2; i < tot; i++) {
    cin >> a[i];
  }
  maxx = 0;
  ans = 0;
  dfs(1, 0);
  j = dfs1(1, 0);
  ans += j;
  cout << ans << endl;
  return 0;
}
