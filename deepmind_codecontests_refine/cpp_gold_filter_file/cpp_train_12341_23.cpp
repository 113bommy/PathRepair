#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5368709120")
const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 400;
const long double EPS = 1e-14;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
using namespace std;
double workTime() { return double(clock()) / CLOCKS_PER_SEC; }
void my_return(int code) { exit(code); }
int n;
long long x[100010], y[100010], z[100010];
long long safe_div(long long x, bool left) {
  if (x % 2) {
    if (left)
      ++x;
    else
      --x;
  }
  return x / 2;
}
bool check(long long d, long long &ansx, long long &ansy, long long &ansz) {
  long long mn[4], mx[4];
  for (int i = 0; i < 4; ++i) {
    mn[i] = -6e18 - 2;
    mx[i] = 6e18 + 2;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      long long cur = x[i];
      if (j & 1)
        cur -= y[i];
      else
        cur += y[i];
      if (j & 2)
        cur -= z[i];
      else
        cur += z[i];
      mn[j] = max(mn[j], cur - d);
      mx[j] = min(mx[j], cur + d);
    }
  }
  for (int r = 0; r < 2; ++r) {
    long long lb[4], rb[4];
    lb[0] = safe_div(mn[0] - 3 * r, true);
    rb[0] = safe_div(mx[0] - 3 * r, false);
    lb[1] = safe_div(mn[1] - r, true);
    rb[1] = safe_div(mx[1] - r, false);
    lb[2] = safe_div(mn[2] - r, true);
    rb[2] = safe_div(mx[2] - r, false);
    lb[3] = safe_div(-mx[3] - r, true);
    rb[3] = safe_div(-mn[3] - r, false);
    bool good = true;
    for (int i = 0; i < 4; ++i)
      if (lb[i] > rb[i]) good = false;
    if (!good) continue;
    if (lb[1] + lb[2] + lb[3] > rb[0] || rb[1] + rb[2] + rb[3] < lb[0])
      continue;
    long long ans[4];
    for (int i = 1; i <= 3; ++i) ans[i] = lb[i];
    for (int i = 1; i <= 3; ++i) {
      if (lb[0] <= ans[1] + ans[2] + ans[3] &&
          ans[1] + ans[2] + ans[3] <= rb[0])
        break;
      long long delta = rb[0] - ans[1] - ans[2] - ans[3];
      if (ans[i] + delta <= rb[i])
        ans[i] += delta;
      else
        ans[i] = rb[i];
    }
    if (lb[0] <= ans[1] + ans[2] + ans[3] &&
        ans[1] + ans[2] + ans[3] <= rb[0]) {
      long long a = 2 * ans[3] + r, b = 2 * ans[1] + r, c = 2 * ans[2] + r;
      ansx = (b + c) / 2;
      ansy = (a + c) / 2;
      ansz = (a + b) / 2;
      return true;
    }
  }
  return false;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  mt19937 mt_rand(time(0));
  int CASE;
  scanf("%d", &CASE);
  while (CASE--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d %I64d %I64d", &x[i], &y[i], &z[i]);
    long long ll = -1, rr = 3e18 + 2;
    long long ansx, ansy, ansz;
    while (ll + 1 < rr) {
      long long mid = (ll + rr) / 2;
      if (check(mid, ansx, ansy, ansz))
        rr = mid;
      else
        ll = mid;
    }
    check(rr, ansx, ansy, ansz);
    printf("%I64d %I64d %I64d\n", ansx, ansy, ansz);
  }
  my_return(0);
}
