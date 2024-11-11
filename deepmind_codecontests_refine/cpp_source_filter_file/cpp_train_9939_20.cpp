#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int tot[maxn], cur[maxn], a[maxn];
int is1[maxn], is2[maxn];
int good1[maxn], good2[maxn];
int ok(int l, int r, int n) {
  if (l > (n + 1) / 2) {
    if (r < n && !is1[r + 1]) return 0;
    int rr = l - 1, ll = n - rr + 1;
    if (rr >= ll && ll >= 1 && ll <= n && !is2[ll]) return 0;
    return good1[(n + 1) / 2] && good2[n / 2 + 1];
  } else if (r <= n / 2) {
    if (l > 1 && !is1[l - 1]) return 0;
    int ll = r + 1, rr = n - ll + 1;
    if (ll <= n && ll >= 1 && rr >= ll && !is2[ll]) return 0;
    return good1[(n + 1) / 2] && good2[n / 2 + 1];
  } else {
    if (l > 1 && r < n && !is1[l - 1] && !is1[r + 1]) return 0;
    if (n - l + 1 <= r) {
      int rr = l - 1, ll = 1;
      if (rr >= 1 && !good1[rr]) return 0;
    } else {
      int ll = r + 1, rr = n - ll + 1;
      if (ll <= n && !good2[ll]) return 0;
    }
    return 1;
  }
}
int main() {
  int n, i, j, k;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i], tot[a[i]]++;
  int hehe = 0;
  for (i = 0; i <= n; i++)
    if (tot[i] & 1) hehe++;
  if (hehe > 1) {
    puts("0");
    return 0;
  }
  for (i = 1; i * 2 - 1 <= n; i++) {
    if (a[i] != a[n - i + 1]) break;
    is1[i] = is1[n - i + 1] = 1;
  }
  i = (n + 1) / 2, j = n - i + 1;
  while (i >= 1) {
    if (a[i] != a[j]) break;
    is2[i] = is2[j] = 1;
    i--, j++;
  }
  int ill = 0;
  for (i = 1; i * 2 - 1 <= n; i++) {
    j = i;
    cur[a[j]]++;
    if (cur[a[j]] * 2 - 1 == tot[a[j]])
      ill = 1;
    else if (cur[a[j]] * 2 > tot[a[j]])
      break;
    if (!ill)
      good1[j] = 1;
    else if (i * 2 - 1 == n)
      good1[j] = 1;
    else
      break;
  }
  ill = 0;
  memset(cur, 0, sizeof(cur));
  for (i = 1; i * 2 - 1 <= n; i++) {
    j = n - i + 1;
    cur[a[j]]++;
    if (cur[a[j]] * 2 - 1 == tot[a[j]])
      ill = 1;
    else if (cur[a[j]] * 2 > tot[a[j]])
      break;
    if (!ill)
      good2[j] = 1;
    else if (i * 2 - 1 == n)
      good2[j] = 1;
    else
      break;
  }
  int l, r, mid;
  int ans = 0;
  for (i = 1; i <= n; i++) {
    l = i, r = n + 1;
    while (l < r) {
      mid = (l + r) / 2;
      if (ok(i, mid, n))
        r = mid;
      else
        l = mid + 1;
    }
    ans += n - l + 1;
  }
  cout << ans << endl;
}
