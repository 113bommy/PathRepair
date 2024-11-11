#include <bits/stdc++.h>
using namespace std;
struct tri {
  long long x, y, z;
  tri() : x(0), y(0), z(0) {}
  tri(const long long x, const long long y, const long long z)
      : x(x), y(y), z(z) {}
  tri(const tri &t) : x(t.x), y(t.y), z(t.z) {}
};
bool query_compare(const tri &a, const tri &b) { return a.x < b.x; }
class OverlapCompare {
 public:
  bool operator()(const tri &a, const tri &b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};
long long n, m;
tri querys[300005];
set<tri, OverlapCompare> overlap;
long long dp[300005];
long long record[300005];
list<tri> be_add, be_remove;
bool removed[300005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> querys[i].x >> querys[i].y >> querys[i].z;
  }
  stable_sort(querys, querys + m, query_compare);
  fill_n(dp, n + 1, 1);
  for (long long i = 0; i < m; i++) {
    set<tri, OverlapCompare>::iterator lb =
        overlap.lower_bound(tri(-1LL, querys[i].y, querys[i].z));
    set<tri, OverlapCompare>::iterator ub =
        overlap.upper_bound(tri((long long)1e15, querys[i].z, 0LL));
    if (lb != overlap.begin()) {
      if ((--lb)->z < querys[i].y) {
        ++lb;
      }
    }
    for (set<tri, OverlapCompare>::iterator it = lb; it != ub; it++) {
      if (it->x == querys[i].x) continue;
      if (dp[querys[i].x] < dp[it->x] + 1) {
        dp[querys[i].x] = dp[it->x] + 1;
        record[querys[i].x] = it->x;
      }
    }
    be_add.clear();
    be_remove.clear();
    for (set<tri, OverlapCompare>::iterator it = lb; it != ub; it++) {
      bool cur_be_remove = false;
      if (it->y < querys[i].y && it->z >= querys[i].y) {
        be_add.push_back(tri(it->x, it->y, querys[i].y - 1));
        cur_be_remove = true;
      }
      if (it->y <= querys[i].z && querys[i].z < it->z) {
        be_add.push_back(tri(it->x, querys[i].z + 1, it->z));
        cur_be_remove = true;
      }
      if (it->y >= querys[i].y && it->z <= querys[i].z) {
        cur_be_remove = true;
      }
      if (cur_be_remove) {
        be_remove.push_back(*it);
      }
    }
    for (list<tri>::iterator it = be_remove.begin(); it != be_remove.end();
         it++) {
      overlap.erase(*it);
    }
    for (list<tri>::iterator it = be_add.begin(); it != be_add.end(); it++) {
      overlap.insert(*it);
    }
    overlap.insert(querys[i]);
  }
  long long rst_idx = 1;
  for (long long i = 1; i <= n; i++) {
    if (dp[i] > dp[rst_idx]) rst_idx = i;
  }
  long long i = rst_idx;
  fill_n(removed, n + 1, true);
  while (i != 0) {
    removed[i] = false;
    i = record[i];
  }
  cout << n - dp[rst_idx] << '\n';
  for (long long i = 1; i <= n; i++) {
    if (removed[i]) cout << i << ' ';
  }
  cout << '\n';
  return 0;
}
