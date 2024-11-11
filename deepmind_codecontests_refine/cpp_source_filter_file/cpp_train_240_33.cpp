#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
map<pair<long long, long long>, long long> now;
int dfs(long long a, long long b) {
  if (a > b) swap(a, b);
  bool was = now.count(make_pair(a, b));
  long long &res = now[make_pair(a, b)];
  if (!a) return res = 0;
  if (was) return res;
  res = max(res, (long long)dfs(a, b % a) ^ 1);
  long long x = b / a - 1;
  if (b % 2 == 1) {
    res = max(res, x % 2);
  } else {
    x %= a + 1;
    res = max(res, x % 2);
    if (x == a) res = 1;
  }
  return res;
}
int main(void) {
  int t;
  scanf("%d", &t);
  for (int(i) = 0; (i) < (t); ++(i)) {
    long long x, y;
    cin >> x >> y;
    puts(dfs(x, y) ? "First" : "Second");
  }
  return 0;
}
