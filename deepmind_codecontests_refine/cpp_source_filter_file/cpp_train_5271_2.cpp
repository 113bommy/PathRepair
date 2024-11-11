#include <bits/stdc++.h>
using namespace std;
const int msz = 3e5 + 5;
int n, k;
int arr[msz], nr[msz], cmp[msz];
bool ok(int d) {
  int p1 = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (arr[p1] - arr[i] > d) {
      p1--;
    }
    nr[i] = p1;
  }
  memset(cmp, -1, sizeof(cmp));
  cmp[n] = n;
  for (int i = n - 1; i >= 0; --i) {
    p1 = i + k - 1;
    if (p1 > nr[i]) {
      cmp[i] = cmp[i + 1];
    } else {
      if (cmp[p1 + 1] == p1 + 1)
        cmp[i] = i;
      else
        cmp[i] = cmp[i + 1];
    }
  }
  return cmp[0] == 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  if (k == 1) return cout << 0, 0;
  sort(arr, arr + n);
  int lo = 0, hi = 1e9 + 9;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (ok(mid))
      hi = mid - 1;
    else
      lo = mid + 1;
  }
  cout << hi + 1;
  return 0;
}
