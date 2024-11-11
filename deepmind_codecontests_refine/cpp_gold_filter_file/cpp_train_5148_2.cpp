#include <bits/stdc++.h>
using namespace std;
char s[50010];
struct T {
  int l, r, s;
};
bool cmp(const T &a, const T &b) {
  if (a.s == b.s) return a.l < b.l;
  return a.s < b.s;
}
vector<T> v;
int d[5][50010];
int l;
map<int, pair<int, int> > m;
bool cmp2(const T &a, const T &b) { return a.l < b.l; }
inline void update(int &r, const T &a, const T &b) {
  int l1 = min(a.l, b.l), r1 = max(a.r, b.r);
  r = min(r, r1 - l1);
}
int solve(int c1, int c2) {
  int l1 = m[c1].first, l2 = m[c2].first;
  int r1 = m[c1].second, r2 = m[c2].second;
  if (l1 == r1 || l2 == r2) return -1;
  if (r1 - l1 > r2 - l2) {
    swap(l1, l2);
    swap(r1, r2);
  }
  int res = l;
  for (int ll = l1; ll < r1; ll++) {
    int l_ =
        lower_bound(v.begin() + l2, v.begin() + r2, v[ll], cmp2) - v.begin();
    if (l_ > l2) {
      update(res, v[ll], v[l_ - 1]);
    }
    if (l_ < r2) {
      update(res, v[ll], v[l_]);
    }
  }
  return res;
}
const int C = 340;
int w[540000];
int rw[700];
int ans[700][700];
int main() {
  scanf("%s", s);
  for (; s[l]; l++) {
    for (int i = 1; i <= 4; i++) {
      if (l < i - 1) continue;
      T t;
      t.l = l - i + 1;
      t.r = l + 1;
      t.s = d[i][l] = d[i - 1][l - 1] * 27 + s[l] - 'a' + 1;
      v.push_back(t);
    }
  }
  sort(v.begin(), v.end(), cmp);
  int c = 0, W = 1;
  for (int i = 0; i < v.size(); i++) {
    if (i && v[i].s == v[i - 1].s) {
      c++;
    } else {
      if (i) {
        m[v[i - 1].s].second = i;
        if (c >= C) {
          rw[W] = v[i - 1].s;
          w[v[i - 1].s] = W++;
        }
      }
      m[v[i].s].first = i;
      c = 1;
    }
  }
  m[v[v.size() - 1].s].second = v.size();
  if (c >= C) {
    rw[W] = v[v.size() - 1].s;
    w[v[v.size() - 1].s] = W++;
  }
  for (int i = 1; i < W; i++) {
    for (int j = 1; j < W; j++) {
      ans[i][j] = ans[j][i] = solve(rw[i], rw[j]);
    }
  }
  int n;
  scanf("%d", &n);
  char q1[5], q2[5];
  int l1, l2, r1, r2;
  for (int i = 0; i < n; i++) {
    scanf("%s %s", q1, q2);
    for (l1 = r1 = 0; q1[l1]; l1++) {
      r1 = r1 * 27 + q1[l1] - 'a' + 1;
    }
    for (l2 = r2 = 0; q2[l2]; l2++) {
      r2 = r2 * 27 + q2[l2] - 'a' + 1;
    }
    if (w[r1] && w[r2]) {
      printf("%d\n", ans[w[r1]][w[r2]]);
    } else {
      printf("%d\n", solve(r1, r2));
    }
  }
  return 0;
}
