#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 1e5 + 10;
struct zz {
  long long x, y;
} a[N];
bool check(zz z1, zz z2, zz y1, zz y2) {
  if ((z1.y - z2.y) * (y1.x - y2.x) == (z1.x - z2.x) * (y1.y - y2.y))
    return true;
  else
    return false;
}
long long dis(zz z1, zz z2) {
  return (z1.x - z2.x) * (z1.x - z2.x) + (z1.y - z2.y) * (z1.y - z2.y);
}
bool check(int n) {
  while (n % 2 == 0) {
    n /= 2;
  }
  if (n == 1)
    return true;
  else
    return false;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  if (n % 4 != 0) {
    cout << "NO" << endl;
    return;
  }
  int flag = 1;
  for (int i = 0; i < n / 2; i++) {
    if (!check(a[i], a[i + 1], a[i + n / 2], a[(i + n / 2 + 1) % n])) {
      flag = 0;
      break;
    }
  }
  if (flag && n == 4) {
    cout << "YES" << endl;
    return;
  }
  long long r = dis(a[1], a[0]);
  for (int i = 0; i < n / 2; i++) {
    if (dis(a[i], a[(i + 1) % n]) !=
        dis(a[i + n / 2], a[(i + n / 2 + 1) % n])) {
      flag = 0;
      break;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
