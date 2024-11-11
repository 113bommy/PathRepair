#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
pair<long long, long long> p[N];
int n;
long long cross_product(const pair<long long, long long>& a,
                        const pair<long long, long long>& b) {
  return a.first * b.second - a.second * b.first;
}
inline bool on_same_line(const pair<long long, long long>& p,
                         const pair<long long, long long>& a,
                         const pair<long long, long long>& b) {
  return cross_product(pair<long long, long long>((b).first - (a).first,
                                                  (b).second - (a).second),
                       pair<long long, long long>((p).first - (a).first,
                                                  (p).second - (a).second)) ==
         0;
}
bool ok(pair<long long, long long> a, pair<long long, long long> b) {
  pair<long long, long long> p1, p2;
  int diff = 0;
  for (int i = 0; i < n; ++i) {
    if (on_same_line(p[i], a, b)) continue;
    if (diff == 2 && !on_same_line(p[i], p1, p2))
      return 0;
    else if (diff == 0) {
      p1 = p[i];
      ++diff;
    } else if (diff == 1) {
      p2 = p[i];
      ++diff;
    }
  }
  return 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", &p[i].first, &p[i].second);
  }
  if (n <= 4) {
    puts("YES");
    return 0;
  }
  if (ok(p[0], p[1]) || ok(p[1], p[2]) || ok(p[0], p[2]))
    puts("YES");
  else
    puts("NO");
  return 0;
}
