#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const unsigned long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  string s = "/home/jslijin/jslijin/code/";
  freopen((s + "code.in").c_str(), "r", stdin);
  freopen((s + "code.out").c_str(), "w", stdout);
}
int n, a[N], cnt = 0, nxt[N], p[N];
unsigned long long ans = 0, ret;
set<int> S;
bool check(int x) {
  for (; x; x /= 10)
    if (x % 10 != 7 && x % 10 != 4) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]);
  for (int i = (1); i <= (n); ++i)
    if (check(a[i])) p[++cnt] = i;
  ans = (unsigned long long)n * (n - 1) * (n + 1) / 6 * (n + 2) / 4;
  for (int i = (1); i <= (cnt); ++i)
    for (int j = (i + 1); j <= (cnt); ++j)
      if (a[p[i]] == a[p[j]]) {
        nxt[i] = j;
        break;
      }
  for (int i = (1); i <= (cnt - 1); ++i) {
    S.clear(), ret = 0;
    S.insert(p[i + 1] - 1), S.insert(n + 1);
    for (int j = (i); j >= (1); --j) {
      for (int k = nxt[j]; k && k > i; k = nxt[k]) {
        auto l = S.lower_bound(p[k]), r = l--;
        ret +=
            (unsigned long long)(p[k] - *l) * (*r - p[k]) * (p[i + 1] - p[i]);
        if (l == S.begin())
          ret += (unsigned long long)(*r - p[k]) * (p[i + 1] - p[i] - 1) *
                 (p[i + 1] - p[i]) / 2;
        S.insert(p[k]);
      }
      ans -= ret * (p[j] - p[j - 1]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
