#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "b";
const int NMAX = 100100;
int n, k, h, ans[NMAX];
pair<pair<int, int>, int> q[NMAX];
int may(double lvl) {
  int now = 0;
  for (int i = 0; i < (int)n; i++)
    if (now < k && q[i].first.second * lvl > h * (now + 1))
      ans[now++] = q[i].second;
  return now == k;
}
int main() {
  cin >> n >> k >> h;
  for (int i = 0; i < (int)n; i++) {
    q[i].second = i + 1;
    scanf("%d", &q[i].first.first);
  }
  for (int i = 0; i < (int)n; i++) scanf("%d", &q[i].first.second);
  sort(q, q + n);
  double l = 0, r = 1e9;
  for (int i = 0; i < (int)80; i++) {
    double m = (l + r) / 2;
    if (may(m))
      r = m;
    else
      l = m;
  }
  may(r);
  for (int i = 0; i < (int)k; i++) printf("%d ", ans[i]);
  return 0;
}
