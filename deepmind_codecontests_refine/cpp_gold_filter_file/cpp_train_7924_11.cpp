#include <bits/stdc++.h>
using namespace std;
vector<long long> num;
const long long MAX = (long long)1E10;
void rec(long long x) {
  if (x > MAX) return;
  num.push_back(x * 10 + 4);
  num.push_back(x * 10 + 7);
  rec(x * 10 + 4);
  rec(x * 10 + 7);
}
long long pl, pr, vl, vr;
int k;
long double prob_p(long long a, long long b) {
  if (a > b || a > pr || b < pl) return 0;
  return (long double)(min(pr, b) - max(pl, a) + 1) / (pr - pl + 1);
}
long double prob_v(long long a, long long b) {
  if (a > b || a > vr || b < vl) return 0;
  return (long double)(min(vr, b) - max(vl, a) + 1) / (vr - vl + 1);
}
int main() {
  rec(0);
  num.push_back(-MAX);
  num.push_back(MAX);
  sort(num.begin(), num.end());
  cin >> pl >> pr >> vl >> vr >> k;
  long double ans = 0;
  int n = num.size();
  if (k > 1) {
    for (int i = 1; i + 2 < n; ++i) {
      long long a = num[i - 1] + 1, b = num[i];
      long long c = num[i + k - 1], d = num[i + k] - 1;
      ans += prob_p(a, b) * prob_v(c, d) + prob_v(a, b) * prob_p(c, d);
    }
  } else {
    for (int i = 1; i + 1 < n; ++i) {
      long long a = num[i - 1] + 1, b = num[i + 1] - 1;
      long long x = num[i];
      ans += prob_p(a, x - 1) * prob_v(x + 1, b) +
             prob_v(a, x - 1) * prob_p(x + 1, b) +
             +prob_p(a, x - 1) * prob_v(x, x) +
             prob_v(a, x - 1) * prob_p(x, x) +
             +prob_p(x + 1, b) * prob_v(x, x) +
             prob_v(x + 1, b) * prob_p(x, x) + prob_p(x, x) * prob_v(x, x);
    }
  }
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}
