#include <bits/stdc++.h>
using namespace std;
long long s = 1, st[44], kt[44], dd[44];
long long f[44][44] = {0};
long long count(long long i, long long j, int k) {
  if (i > j) return 0;
  long long tmp = 0;
  for (int l = 1;; l++)
    if (st[l] > j)
      break;
    else if (i <= st[l] && kt[l] <= j) {
      tmp += f[l][k];
      i = kt[l] + 1;
    } else if (kt[l] >= i) {
      long long ii = max(st[l], i);
      long long jj = min(kt[l], j);
      long long mid = (st[l] + kt[l]) / 2;
      tmp += count(ii - dd[l - 1], min(jj, mid) - dd[l - 1], k);
      tmp += count(mid + 1 - 2 * dd[l - 1], jj - 2 * dd[l - 1], k - 1);
    }
  return tmp;
}
int main() {
  long long n, t;
  cin >> n >> t;
  st[1] = 1;
  kt[1] = 1;
  dd[1] = 1;
  for (int i = 2; i <= 40; i++) {
    st[i] = kt[i - 1] + 1;
    kt[i] = kt[i - 1] + 2 * (kt[i - 1] - st[i - 1] + 1);
    dd[i] = kt[i] - st[i] + 1;
  }
  f[1][1] = 1;
  for (int i = 2; i <= 40; i++)
    for (int j = 1; j <= i; j++) f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
  int bd = 0;
  for (int i = 1; i <= 40; i++) {
    if (s >= t) {
      bd = i;
      break;
    }
    s = s * 2;
  }
  int tt = bd == 1 ? 1 : 0;
  if (kt[bd] > n || s > t)
    cout << 0 << endl;
  else
    cout << count(1, n + 1, bd) - tt << endl;
  return 0;
}
