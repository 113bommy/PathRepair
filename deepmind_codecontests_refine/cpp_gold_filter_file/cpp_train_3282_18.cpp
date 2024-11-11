#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const long long INF = 1LL * inf * inf;
const double eps = 1e-9;
const int MAXN = 2500;
const int md = (int)1e9 + 7;
struct req {
  int type, t, x, id;
};
bool operator<(const req& a, const req& b) {
  if (a.t != b.t)
    return a.t < b.t;
  else
    return a.id < b.id;
}
map<int, int> cnt;
vector<pair<int, int> > ans;
req a[2000000];
int n;
set<req> promised, ret;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d%d", &a[i].type, &a[i].t, &a[i].x), a[i].id = i;
  for (int i = 0; i < n; i++) {
    if (a[i].type != 3) promised.insert(a[i]);
    if (a[i].type == 3) {
      while (!promised.empty()) {
        req w = *(promised.begin());
        if (w.t <= a[i].t) {
          if (w.type == 1) {
            cnt[w.x]++;
          }
          if (w.type == 2) {
            cnt[w.x]--;
          }
          promised.erase(promised.begin());
          ret.insert(w);
        } else
          break;
      }
      while (!ret.empty()) {
        set<req>::iterator it = ret.end();
        it--;
        req w = *it;
        if (w.t > a[i].t) {
          if (w.type == 1) {
            cnt[w.x]--;
          }
          if (w.type == 2) {
            cnt[w.x]++;
          }
          ret.erase(ret.begin());
          promised.insert(w);
        } else
          break;
      }
      cout << abs(cnt[a[i].x]) << "\n";
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << ans[i].second << "\n";
  return 0;
}
