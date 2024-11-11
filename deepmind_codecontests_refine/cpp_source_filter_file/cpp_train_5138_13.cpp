#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct uz {
  long long k, l, id, cnt;
  long long x, y, m;
  int i = 1;
  void add() {
    l = (l * x + y) % m;
    i++;
  }
} u[5035];
vector<pair<long long, long long>> ans;
int main() {
  scanf("%d", &n);
  long long aa = 0, sumk = 0;
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    long long tmp = 0;
    scanf("%lld%lld%lld%lld%lld", &u[i].k, &u[i].l, &u[i].x, &u[i].y, &u[i].m);
    sumk += u[i].k;
    long long last = u[i].l;
    for (int i = 2; i <= u[i].k; i++) {
      long long cur = (last * u[i].x + u[i].y) % u[i].m;
      if (last > cur) tmp++;
      last = cur;
    }
    aa = max(aa, tmp);
  }
  printf("%lld\n", aa);
  if (sumk > 200000) return 0;
  while (1) {
    long long start = ans.size();
    for (int(i) = 0; (i) < (int)(n); (i)++) {
      while (u[i].i <= u[i].k) {
        ans.push_back({u[i].l, i});
        u[i].add();
        if (ans.back().first > u[i].l) break;
      }
    }
    if (start == ans.size()) break;
    sort(ans.begin() + start, ans.end());
    if (start != 0) aa++;
  }
  for (auto p : ans) printf("%lld %lld\n", p.first, p.second + 1);
  return 0;
}
