#include <bits/stdc++.h>
using namespace std;
set<pair<pair<long long, long long>, long long> > s[2];
long long aux[100005][2], best[1000005][2];
int main() {
  long long n, m, k, d, f, t, c;
  scanf("%lld %lld %lld", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%lld %lld %lld %lld", &d, &f, &t, &c);
    if (t == 0)
      s[0].insert(make_pair(make_pair(d, f), c));
    else
      s[1].insert(make_pair(make_pair(-d, t), c));
  }
  for (int i = 1; i <= n; i++) {
    aux[i][0] = -1ll;
    aux[i][1] = -1ll;
  }
  for (int i = 1; i < 1000005; i++) {
    best[i][0] = -1ll;
    best[i][1] = -1ll;
  }
  long long left = n, sum = 0ll;
  for (auto a : s[0]) {
    d = a.first.first;
    f = a.first.second;
    c = a.second;
    if (aux[f][0] == -1) {
      aux[f][0] = c;
      sum += c;
      left--;
    } else {
      if (c < aux[f][0]) {
        sum -= aux[f][0];
        aux[f][0] = c;
        sum += aux[f][0];
      }
    }
    if (!left) {
      if (best[d - 1][0] == -1)
        best[d][0] = sum;
      else
        best[d][0] = min(best[d - 1][0], sum);
    }
  }
  left = n, sum = 0ll;
  for (auto a : s[1]) {
    d = -a.first.first;
    f = a.first.second;
    c = a.second;
    if (aux[f][1] == -1) {
      aux[f][1] = c;
      sum += c;
      left--;
    } else {
      if (c < aux[f][1]) {
        sum -= aux[f][1];
        aux[f][1] = c;
        sum += aux[f][1];
      }
    }
    if (!left) {
      if (best[d + 1][1] == -1)
        best[d][1] = sum;
      else
        best[d][1] = min(best[d + 1][1], sum);
    }
  }
  for (int i = 2; i <= 1000000; i++) {
    if (best[i][0] == -1) best[i][0] = best[i - 1][0];
  }
  for (int i = 1000000; i >= 1; i--) {
    if (best[i][1] == -1) best[i][1] = best[i + 1][1];
  }
  long long ans = 1000000000000000000ll;
  for (long long i = 1; i + k + 1 <= 1000000; i++) {
    if (best[i][0] != -1 && best[i + k + 1][1] != -1) {
      ans = min(ans, best[i][0] + best[i + k + 1][1]);
    }
  }
  if (ans == 1000000000000000000ll) ans = -1ll;
  printf("%lld\n", ans);
  return 0;
}
