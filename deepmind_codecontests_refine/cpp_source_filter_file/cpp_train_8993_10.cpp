#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long int)1e9 + 10;
const long long int INFLL = (long long int)1e18 + 10;
const long double EPS = 1e-8;
const long double EPSLD = 1e-18;
const long long int MOD = 1e9 + 7;
template <class T>
T &chmin(T &a, const T &b) {
  return a = min(a, b);
}
template <class T>
T &chmax(T &a, const T &b) {
  return a = max(a, b);
}
const long long int MAX_N = 1024;
long long int n;
long long int a[MAX_N];
vector<pair<long long int, long long int> > res;
vector<pair<long long int, long long int> > ans;
void dfs(long long int t) {
  vector<long long int> v(0);
  long long int d = INFLL, cnt = 0, hs = 0;
  for (long long int i = (1); i < (long long int)(n + 2); i++) {
    if (d == INFLL) {
      if (abs(a[i] - a[i - 1]) == 1)
        d = a[i] - a[i - 1], cnt = 1;
      else
        v.emplace_back(i), hs++;
    } else {
      if (a[i] != a[i - 1] + d) {
        v.emplace_back(i), hs++;
        if (cnt == 1) v.emplace_back(i - 1);
        cnt = 0;
        d = INFLL;
      } else
        cnt++;
    }
  }
  if (hs > (3 - t) * 2) return;
  if (((long long int)(v).size()) == 0) {
    ans = res;
    return;
  } else if (t == 3)
    return;
  for (auto &l : v)
    for (auto &r : v)
      if (l < r) {
        reverse(a + l, a + r);
        res.emplace_back(l, r);
        dfs(t + 1);
        res.pop_back();
        reverse(a + l, a + r);
      }
}
int main() {
  scanf("%lld", &n);
  for (long long int i = (0); i < (long long int)(n); i++)
    scanf("%lld", &a[i + 1]);
  a[0] = 0;
  a[n + 1] = n + 1;
  dfs(0);
  reverse((ans).begin(), (ans).end());
  printf("%lld\n", ((long long int)(ans).size()));
  for (auto &w : ans) printf("%lld %lld\n", w.first, w.second - 1);
  return 0;
}
