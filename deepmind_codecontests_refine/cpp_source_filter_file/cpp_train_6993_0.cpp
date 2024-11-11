#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[200005];
int b[200005];
int l[200005];
int r[200005];
int cnt[200005];
int check[200005];
int ans;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> q;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) {
    if (l[a[i]] == 0) {
      l[a[i]] = i;
    }
    cnt[a[i]]++;
    r[a[i]] = i;
  }
  int ans = 0;
  for (i = 1; i <= n; i++) {
    int rr = r[a[i]];
    int k = 0;
    for (j = i; j <= rr; j++) {
      if (check[a[j]] == 0) {
        check[a[j]] = 1;
      }
      k = max(k, cnt[a[j]]);
      rr = max(rr, r[a[j]]);
    }
    ans += j - i - k;
    i = j;
  }
  cout << ans;
  return 0;
}
