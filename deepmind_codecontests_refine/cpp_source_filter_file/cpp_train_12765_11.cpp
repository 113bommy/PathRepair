#include <bits/stdc++.h>
using namespace std;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 1e9 + 5;
const long long linf = 1e18 + 5;
const double PI = acos(-1.0);
const long double eps = 1e-6;
const int MAXN = 1e5 + 1005;
const int N = 1e6 + 5;
const int K = 20;
int n, S;
long long cnt[2], ans = 0;
vector<pair<long long, long long> > v[2];
long long calc(int flag) {
  sort(v[flag].begin(), v[flag].end(),
       [](const pair<long long, long long> &x,
          const pair<long long, long long> &y) { return x.second > y.second; });
  long long d = cnt[flag] % S, s = 0;
  for (auto p : v[flag]) {
    if (p.first >= d) {
      s += d * p.second;
      break;
    } else
      d -= p.first, s += p.first * p.second;
  }
  return ans + s;
}
int work() {
  scanf("%d%d", &n, &S);
  for (register int i = (1), I = (n) + 1; i < I; ++i) {
    int s, a, b;
    scanf("%d%d%d", &s, &a, &b);
    if (a > b)
      cnt[0] += s, ans += 1LL * s * a, v[0].push_back({s, b - a});
    else
      cnt[1] += s, ans += 1LL * s * b, v[1].push_back({s, a - b});
  }
  if (cnt[0] % S + cnt[1] % S > S)
    return printf("-%lld\n", ans);
  else
    printf("%lld\n", max(calc(0), calc(1)));
  return 0;
}
int main() {
  work();
  return 0;
}
