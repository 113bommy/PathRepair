#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:67108864")
const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 400;
const long double EPS = 1e-9;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
using namespace std;
double workTime() { return double(clock()) / CLOCKS_PER_SEC; }
void my_return(int code) { exit(code); }
int n, l, v1, v2, k;
bool func(long double ans) {
  long double x = 0, t = 0.0, busx = 0.0;
  int cnt = n;
  while (cnt > 0) {
    long double meet = (busx - x) / (v1 + v2);
    t += meet;
    x += v1 * meet;
    busx -= v2 * meet;
    long double t1 = (l - x - v1 * (ans - t)) / (v2 - v1);
    t += t1;
    x += v1 * t1;
    busx += v2 * t1;
    cnt -= k;
  }
  return t <= ans;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  mt19937 mt_rand(time(0));
  scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
  long double ll = l / (long double)v2, rr = l / (long double)v1;
  for (int iter = 0; iter < 100; ++iter) {
    long double mid = (ll + rr) / 2.0;
    if (func(mid))
      rr = mid;
    else
      ll = mid;
  }
  printf("%.7lf\n", (double)rr);
  my_return(0);
}
