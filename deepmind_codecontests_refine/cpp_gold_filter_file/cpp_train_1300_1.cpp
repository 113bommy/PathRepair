#include <bits/stdc++.h>
using namespace std;
int n, m;
long long orig[200010];
pair<long long, int> arr[200010];
int find_peg(int peg, long long len, bool lef, bool init) {
  int nex =
      lef ? upper_bound(arr, arr + n, make_pair(arr[peg].first + len, n + 1)) -
                1 - arr
          : lower_bound(arr, arr + n, make_pair(arr[peg].first - len, -1)) -
                arr;
  long long exlen = abs(arr[nex].first - arr[peg].first);
  if (exlen != 0) {
    if (init) return find_peg(nex, len - exlen, !lef, false);
    long long q = len / exlen, r = len % exlen;
    if (q & 1) return find_peg(nex, r, !lef, false);
    return find_peg(peg, r, lef, false);
  }
  lef = !lef;
  nex =
      lef ? upper_bound(arr, arr + n, make_pair(arr[peg].first + len, n + 1)) -
                1 - arr
          : lower_bound(arr, arr + n, make_pair(arr[peg].first - len, -1)) -
                arr;
  exlen = abs(arr[nex].first - arr[peg].first);
  if (exlen != 0) {
    if (init) return find_peg(nex, len - exlen, !lef, false);
    long long q = len / exlen, r = len % exlen;
    if (q & 1) return find_peg(nex, r, !lef, false);
    return find_peg(peg, r, lef, false);
  }
  return arr[peg].second;
}
int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &arr[i].first);
    arr[i].second = i;
    orig[i] = arr[i].first;
  }
  sort(arr, arr + n);
  for (int i = 0; i < m; i++) {
    long long len;
    int peg;
    scanf("%d%lld", &peg, &len);
    peg--;
    int npeg = lower_bound(arr, arr + n, make_pair(orig[peg], -1)) - arr;
    printf("%d\n", find_peg(npeg, len, true, true) + 1);
  }
  return 0;
}
