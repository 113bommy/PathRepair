#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
long long POWER(long long x, long long y, long long m) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    long long temp = POWER(x, y / 2, m);
    temp *= temp;
    temp %= m;
    return temp;
  }
  long long temp = POWER(x, y - 1, m);
  temp *= x;
  temp %= m;
  return temp;
}
long long POWER(long long x, long long y) {
  if (y == 0) return 1;
  if (y % 2 == 0) {
    long long temp = POWER(x, y / 2);
    temp *= temp;
    return temp;
  }
  long long temp = POWER(x, y - 1);
  temp *= x;
  return temp;
}
struct candy {
  int t, h, m;
  candy() {}
  candy(int tt, int hh, int mm) {
    t = tt;
    h = hh;
    m = mm;
  }
};
bool used[2010];
candy a[2010];
int main() {
  ifstream fin("ali");
  int n;
  long long x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    long long t, h, m;
    cin >> t >> h >> m;
    a[i] = candy(t, h, m);
  }
  int cnt1 = 0;
  int cur = 0, cnt2 = 0;
  int y = x;
  memset(used, 0, sizeof used);
  while (1) {
    int mx = -1, ind = 0;
    for (int i = 0; i < n; i++) {
      if (a[i].t == cur && a[i].h <= x && a[i].m > mx && !used[i]) {
        mx = a[i].m;
        ind = i;
      }
    }
    if (mx == -1) break;
    cnt1++;
    used[ind] = 1;
    x += mx;
    cur = (cur + 1) % 2;
  }
  memset(used, 0, sizeof used);
  cur = 1;
  x = y;
  while (1) {
    int mx = -1, ind = 0;
    for (int i = 0; i < n; i++) {
      if (a[i].t == cur && a[i].h <= x && a[i].m > mx && !used[i]) {
        mx = a[i].h;
        ind = i;
      }
    }
    if (mx == -1) break;
    cnt2++;
    used[ind] = 1;
    x += mx;
    cur = (cur + 1) % 2;
  }
  cout << max(cnt1, cnt2) << '\n';
}
