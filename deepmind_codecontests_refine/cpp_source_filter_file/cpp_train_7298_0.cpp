#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, bnum = 300;
const long long oo = INT_MAX;
int n;
long double r, l;
pair<int, int> a[N];
void input() {
  bool neg = false, pos = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (y > 0)
      pos = true;
    else
      neg = true;
    a[i] = {x, abs(y)};
  }
  if (neg && pos) {
    cout << -1;
    exit(0);
  }
}
bool update(long double nl, long double nr) {
  if (nr < l) {
    return false;
  }
  if (r < nl) {
    return false;
  }
  l = max(l, nl);
  r = min(r, nr);
  return true;
}
bool isok(long double rad) {
  l = -oo, r = oo;
  for (int i = 0; i < n; i++) {
    int x = a[i].first, y = a[i].second;
    if (2 * rad < y) return false;
    long double t = sqrt(y * (rad * 2 - y));
    if (!update(x - t, x + t)) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  input();
  long double s = 0, e = oo;
  for (int i = 0; i < bnum; i++) {
    long double mid = (s + e) / 2;
    if (isok(mid)) {
      e = mid;
    } else
      s = mid;
  }
  cout << setprecision(7) << fixed << s;
  return 0;
}
