#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  unsigned long long c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
bool get(int x, int y, int r, int xx, int yy, int R, int RR) {
  return ((sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy))) > (r + R) &&
           sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy))) > (r + RR)) ||
          (R >= (sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy))) + r) &&
           RR >= (sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy))) + r)) ||
          (r >= (sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy))) + R) &&
           r >= (sqrt(((x - xx) * (x - xx)) + ((y - yy) * (y - yy))) + RR)));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x, y, r, R, xx, yy, rr, RR;
  while (cin >> x >> y >> r >> R >> xx >> yy >> rr >> RR) {
    int rrr[] = {r, R, rr, RR};
    pair<int, int> arr[] = {{x, y}, {x, y}, {xx, yy}, {xx, yy}};
    int ans = 0;
    bool fl = 0;
    fl = get(arr[0].first, arr[0].second, rrr[0], arr[2].first, arr[2].second,
             rrr[2], rrr[3]);
    if (fl) ans++;
    fl = get(arr[1].first, arr[1].second, rrr[1], arr[2].first, arr[2].second,
             rrr[2], rrr[3]);
    if (fl) ans++;
    fl = get(arr[2].first, arr[2].second, rrr[2], arr[0].first, arr[0].second,
             rrr[0], rrr[1]);
    if (fl) ans++;
    fl = get(arr[2].first, arr[2].second, rrr[3], arr[0].first, arr[0].second,
             rrr[0], rrr[1]);
    if (fl) ans++;
    cout << ans << "\n";
  }
  return 0;
}
