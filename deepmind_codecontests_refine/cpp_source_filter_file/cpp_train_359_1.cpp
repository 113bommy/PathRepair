#include <bits/stdc++.h>
using namespace std;
int s[200020], r[200020];
int st[200020];
vector<int> ids[200020];
struct line {
  long long s, r;
  int id;
};
bool check(const line &l1, const line &l2, const line &l3) {
  return (l1.s * l3.s - l2.s * l3.s) * (l1.r * l2.r - l1.r * l3.r) >=
         (l1.r * l3.r - l2.r * l3.r) * (l1.s * l2.s - l1.s * l3.s);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d%d", s + i, r + i);
  int r_largest = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (r[r_largest] < r[i] || (r[r_largest] == r[i] && s[r_largest] < s[i]))
      r_largest = i;
  }
  vector<line> vl;
  for (int i = 0; i < (int)(n); i++) {
    if (s[i] < s[r_largest]) continue;
    vl.push_back({s[i], r[i], i});
  }
  sort((vl).begin(), (vl).end(), [&](const line &p, const line &q) {
    if (p.s != q.s) return p.s < q.s;
    return p.r > q.r;
  });
  vector<line> vv;
  for (int i = 0; i < (int)vl.size();) {
    int sz = (int)vv.size();
    vv.push_back({vl[i].s, vl[i].r, sz});
    int j = i;
    while (j < (int)vl.size() && vl[j].s == vl[i].s) {
      if (vl[j].r == vl[i].r) ids[sz].push_back(vl[j].id);
      j++;
    }
    i = j;
  }
  vl.clear();
  if (vv.size() <= 2) {
    vector<int> ans;
    for (int z = 0; z < (int)(vv.size()); z++)
      for (int i = 0; i < (int)(ids[z].size()); i++)
        ans.push_back(ids[z][i] + 1);
    sort((ans).begin(), (ans).end());
    for (int i = 0; i < (int)(ans.size()); i++)
      printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    return 0;
  }
  int k = 0;
  for (int i = 0; i < (int)vv.size(); i++) {
    while (k >= 2 && check(vv[st[k - 2]], vv[st[k - 1]], vv[i])) k--;
    st[k++] = i;
  }
  vector<int> ans;
  for (int z = 0; z < (int)(k); z++)
    for (int i = 0; i < (int)(ids[vv[st[z]].id].size()); i++)
      ans.push_back(ids[vv[st[z]].id][i] + 1);
  sort((ans).begin(), (ans).end());
  for (int i = 0; i < (int)(ans.size()); i++)
    printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
  return 0;
}
