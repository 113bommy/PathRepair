#include <bits/stdc++.h>
using namespace std;
long long n, m, ns, nl, v, s[100005], l[100005], x1, y11, x2, y2, q;
long long cautbin(long long, long long[], long long, long long);
long long takeElevator(long long, long long, long long, long long, long long);
long long takeStairs(long long, long long, long long, long long, long long);
int main() {
  cin >> n >> m >> ns >> nl >> v;
  for (int i = 1; i <= ns; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= nl; i++) {
    cin >> l[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x1 >> y11 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y11 - y2) << '\n';
      continue;
    }
    long long edr = cautbin(y11, l, nl, 1);
    long long est = cautbin(y11, l, nl, -1);
    long long sdr = cautbin(y11, s, ns, 1);
    long long sst = cautbin(y11, s, ns, -1);
    long long anse = min(takeElevator(l[edr], x1, y11, x2, y2),
                         takeElevator(l[est], x1, y11, x2, y2));
    long long anss = min(takeStairs(s[sdr], x1, y11, x2, y2),
                         takeStairs(s[sst], x1, y11, x2, y2));
    long long ans = min(anss, anse);
    cout << ans << '\n';
  }
  return 0;
}
long long cautbin(long long x, long long a[], long long n, long long sign) {
  long long st = 1, dr = n, ans = 0;
  while (st <= dr) {
    long long mij = (st + dr) / 2;
    if (a[mij] == x) {
      return mij;
    }
    if (a[mij] < x) {
      st = mij + 1;
      if (sign == -1) {
        ans = mij;
      }
    }
    if (a[mij] > x) {
      dr = mij - 1;
      if (sign == 1) {
        ans = mij;
      }
    }
  }
  return ans;
}
long long takeElevator(long long e, long long x1, long long y11, long long x2,
                       long long y2) {
  long long ans = 0;
  if (e == 0) {
    return 1e9;
  }
  long long dx = abs(x1 - x2);
  ans += abs(y11 - e);
  ans += dx / v + (dx % v != 0);
  ans += abs(y2 - e);
  return ans;
}
long long takeStairs(long long s, long long x1, long long y11, long long x2,
                     long long y2) {
  long long ans = 0;
  if (s == 0) {
    return 1e9;
  }
  long long dx = abs(x1 - x2);
  ans += abs(y11 - s);
  ans += dx;
  ans += abs(y2 - s);
  return ans;
}
