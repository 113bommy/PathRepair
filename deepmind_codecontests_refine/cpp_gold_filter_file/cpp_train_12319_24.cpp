#include <bits/stdc++.h>
using namespace std;
long n, a[1000001];
bool check[1 << 22];
bool d[1 << 22][23];
void query(long mask, int maskIndex) {
  if (maskIndex > 22) {
    cout << mask << ' ';
    return;
  }
  bool res = d[mask][maskIndex];
  if (mask & (1 << (maskIndex - 1))) {
    long tmp = mask - (1 << (maskIndex - 1));
    query(tmp, maskIndex + 1);
    return;
  }
  long tmp = mask + (1 << (maskIndex - 1));
  if (d[tmp][maskIndex + 1] == res)
    query(tmp, maskIndex + 1);
  else
    query(mask, maskIndex + 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long i = 1; i <= n; ++i) cin >> a[i];
  for (long i = 1; i <= n; ++i) check[a[i]] = 1;
  for (long j = 0; j < (1 << 22); ++j) d[j][23] = check[j];
  for (int i = 22; i >= 1; --i)
    for (long j = 0; j < (1 << 22); ++j) {
      long mask = j;
      int maskIndex = i;
      if (mask & (1 << (maskIndex - 1))) {
        long tmp = mask - (1 << (maskIndex - 1));
        d[mask][maskIndex] = d[tmp][maskIndex + 1];
      } else {
        long tmp = mask + (1 << (maskIndex - 1));
        d[mask][maskIndex] = (d[tmp][maskIndex + 1] | d[mask][maskIndex + 1]);
      }
    }
  for (long i = 1; i <= n; ++i) {
    bool res = d[a[i]][1];
    if (res)
      query(a[i], 1);
    else
      cout << -1 << ' ';
  }
  return 0;
}
