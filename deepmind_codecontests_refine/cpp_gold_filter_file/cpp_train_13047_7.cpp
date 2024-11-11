#include <bits/stdc++.h>
using namespace std;
const int N = 100086;
struct node {
  int w, id, v;
  node(int _w, int _v, int _id) : w(_w), v(_v), id(_id){};
  bool operator<(const node& sec) const {
    if (w > sec.w)
      return true;
    else if (w == sec.w && v > sec.v)
      return true;
    return false;
  }
};
int n, k, h;
vector<node> dat;
int mtmp[N], vtmp[N];
vector<int> ans, anstmp;
bool isok(double t) {
  int cnt = 0;
  anstmp.clear();
  for (int i = 0; i < n; i++) {
    if (dat[i].v * 1.0 * t >= (k - cnt + 0.0) * (double)h) {
      anstmp.push_back(dat[i].id);
      cnt++;
    }
    if (cnt == k) return true;
  }
  return false;
}
int main() {
  while (scanf("%d %d %d", &n, &k, &h) == 3) {
    dat.clear();
    ans.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &mtmp[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &vtmp[i]);
    }
    for (int i = 0; i < n; i++) {
      dat.push_back(node(mtmp[i], vtmp[i], i + 1));
    }
    sort(dat.begin(), dat.end());
    double lef = 0, rig = 1e15, mid = 0;
    for (int it = 0; it < 200; it++) {
      mid = (lef + rig) / 2;
      if (isok(mid)) {
        ans = anstmp;
        rig = mid;
      } else
        lef = mid;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < k; i++) {
      printf("%d%c", ans[i], i == k - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
