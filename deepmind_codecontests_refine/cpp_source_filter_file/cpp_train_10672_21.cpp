#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 7;
const int inf = 1e9;
const long long maxx = 1e6 + 7;
long long p, n;
double ans = 0;
struct node {
  long long cnt;
  long long len;
} str[maxn];
int main() {
  scanf("%d%d", &n, &p);
  long long x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &x, &y);
    str[i].cnt = y / p - (x - 1) / p;
    str[i].len = y - x + 1;
  }
  for (int i = 1; i < n; i++) {
    long long r1 = str[i].cnt * str[i + 1].len;
    long long r2 = str[i + 1].cnt * (str[i].len - str[i].cnt);
    ans += (double)(r1 + r2) * 2000.0 / (str[i].len * str[i + 1].len);
  }
  long long r1 = str[n].cnt * str[1].len;
  long long r2 = str[1].cnt * (str[n].len - str[n].cnt);
  ans += (double)(r1 + r2) * 2000.0 / (str[n].len * str[1].len);
  printf("%.1f", ans);
}
