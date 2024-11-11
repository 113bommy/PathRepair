#include <bits/stdc++.h>
using namespace std;
long long arr[100010];
long long sana(long long l, long long r, long long k) {
  if (k == -1) return 0;
  long long m;
  for (m = l; m < r && (!(arr[m] & (1 << k))); m++)
    ;
  if (l == m) return sana(m, r, k - 1);
  if (m == r) return sana(l, m, k - 1);
  return min(sana(l, m, k - 1), sana(m, r, k - 1)) | (1 << k);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long i, j, n, ans;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cout << sana(0, n, 32) << '\n';
  return 0;
}
