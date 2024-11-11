#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int a[MAXN];
vector<pair<int, int> > v;
int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!v.empty() && a[i] == v.back().first)
      v.back().second++;
    else
      v.push_back(make_pair(a[i], 1));
    if (v.back().second == k) v.pop_back();
  }
  int st = 0, en = (int)v.size() - 1;
  long long s = 0;
  for (int i = 0; i < v.size(); i++) s += v[i].second;
  s *= m;
  while (st < en) {
    if (v[st].first != v[en].first) return 0 * printf("%lld\n", s);
    if (v[st].second + v[en].second == k) {
      s -= (long long)(m - 1) * k;
      st++, en--;
      continue;
    }
    if (v[st].second + v[en].second > k) s -= (long long)(m - 1) * k;
    return 0 * printf("%lld\n", s);
  }
  if (((long long)m * v[st].second) % k == 0) {
    puts("0");
    return 0;
  }
  s -= (long long)(m * v[st].second) / k * k;
  printf("%lld\n", s);
  return 0;
}
