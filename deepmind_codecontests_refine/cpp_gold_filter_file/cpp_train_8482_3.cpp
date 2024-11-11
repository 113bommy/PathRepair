#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1.01e9;
const double eps = 1e-9;
const int maxn = 5e5 + 10;
pair<pair<long long, long long>, int> e[maxn];
int ec = 0;
pair<long long, long long> a[maxn];
int r[maxn];
pair<long long, int> b[maxn];
multiset<pair<long long, int>> second;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; (i) < (n); ++i)
    scanf("%I64d%I64d", &a[i].first, &a[i].second);
  for (int i = 0; (i) < (m); ++i) scanf("%I64d", &b[i].first), b[i].second = i;
  sort(b, b + m);
  for (int i = 0; (i) < (n - 1); ++i)
    e[ec++] = make_pair(
        make_pair(a[i + 1].first - a[i].second, a[i + 1].second - a[i].first),
        i);
  sort(e, e + ec);
  int j = 0;
  for (int i = 0; (i) < (m); ++i) {
    while (j < ec && e[j].first.first <= b[i].first) {
      second.insert(make_pair(e[j].first.second, e[j].second));
      ++j;
    }
    if (((int)(second).size())) {
      pair<long long, int> t = *second.begin();
      second.erase(second.begin());
      if (t.first < b[i].first) {
        return 0 * printf("No\n");
      }
      r[t.second] = b[i].second;
    }
  }
  if (((int)(second).size()) || j < ec) return 0 * printf("No\n");
  printf("Yes\n");
  for (int i = 0; (i) < (ec); ++i) printf("%d%c", r[i] + 1, " \n"[i + 1 == ec]);
  return 0;
}
