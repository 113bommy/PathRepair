#include <bits/stdc++.h>
using namespace std;
float avg1(long long int n, long long int h, long long int c) {
  return (float)((n + 1) * h + (n - 1) * c) / (2 * n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  cin >> tt;
  for (int pp = 0; pp < tt; pp++) {
    long long int h, c, t;
    cin >> h >> c >> t;
    long long int ans = 0;
    double avg = (h + c) / 2;
    if (t >= h) {
      ans = 1;
    } else if (t <= avg) {
      ans = 2;
    } else {
      double n = (float)(c - h) / (h + c - 2 * t);
      long long int r = ceil(n);
      long long int l = floor(n);
      float diff1, diff2;
      if (l % 2 == 0) l--;
      if (r % 2 == 0) r++;
      diff1 = avg1(l, h, c) - (float)t;
      diff2 = (float)t - avg1(r, h, c);
      if (diff1 <= diff2)
        ans = l;
      else {
        ans = r;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
