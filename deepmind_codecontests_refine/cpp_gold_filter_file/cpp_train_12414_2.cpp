#include <bits/stdc++.h>
using namespace std;
long long int n, a, r, m;
long long int arr[100007];
long long int calc(long long int h) {
  long long int put = 0, rmv = 0, i, cost = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] > h)
      rmv += (arr[i] - h);
    else
      put += (h - arr[i]);
  }
  if (m < (a + r)) {
    long long int onetoanother = min(put, rmv);
    cost = onetoanother * m;
    put -= onetoanother;
    rmv -= onetoanother;
  }
  cost = cost + (a * put) + (r * rmv);
  return cost;
}
int main() {
  long long int i, j, k, p;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> a >> r >> m;
  for (i = 0; i < n; i++) cin >> arr[i];
  long long int l = 0, r = 1e9, mid1, mid2, cost = LLONG_MAX, cost1, cost2;
  while (l <= r) {
    mid1 = l + (r - l) / 3;
    mid2 = r - (r - l) / 3;
    cost1 = calc(mid1);
    cost2 = calc(mid2);
    if (cost1 <= cost2) {
      cost = min(cost, cost1);
      r = mid2 - 1;
    } else {
      cost = min(cost, cost2);
      l = mid1 + 1;
    }
  }
  cout << cost << endl;
  return 0;
}
