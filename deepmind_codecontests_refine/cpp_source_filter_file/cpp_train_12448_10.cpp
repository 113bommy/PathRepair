#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
bitset<N> dp;
int p[N], A[N], vis[N];
long long buc[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, n, i, j, k;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> p[i];
  int len = 0;
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      int tp = i;
      int c = 0;
      do {
        vis[tp] = 1;
        tp = p[tp];
        c++;
      } while (tp != i);
      buc[c]++;
    }
  }
  for (i = 1; i <= n; i++) {
    if (buc[i]) {
      int val = buc[i];
      int j = 0;
      long long tot = 0;
      while ((1 << j) <= val) {
        A[++len] = i * (1 << j);
        val -= (1 << j);
        j++;
        tot += A[len];
      }
      if (tot != 1ll * buc[i] * i) A[++len] = (1ll * i * buc[i] - tot);
    }
  }
  int mx;
  dp.set(0);
  for (i = 1; i <= len; i++) dp |= (dp << A[i]);
  if (dp.test(k))
    mx = k;
  else
    mx = k + 1;
  int temp = k;
  for (i = 1; i <= n; i++) temp -= (buc[i] * i) / 2;
  temp = max(temp, 0);
  int ans = 2 * (k - temp);
  if (temp) {
    ans += temp;
  }
  cout << min(mx, n) << " " << min(n, ans) << "\n";
  return 0;
}
