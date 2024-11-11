#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const double EPS = 1e-10;
inline int dcmp(const double& x) {
  return fabs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}
struct element {
  double val;
  int pos;
  inline element(const double& Val = 0, const int& Pos = 0) {
    val = Val;
    pos = Pos;
  }
  friend inline bool operator<(const element& A, const element& B) {
    return dcmp(A.val - B.val) != 0 ? dcmp(A.val - B.val) < 0 : A.pos < B.pos;
  }
};
int n, t, q, l[N], s[N], x, y, p[N];
double ans;
set<element> A, B;
inline void reset(void) {
  while (t) {
    if (A.empty()) break;
    set<element>::iterator it = --A.end();
    ans += it->val;
    int id = it->pos;
    A.erase(it);
    B.erase(element((1.0 * p[id] * (s[id]) / ((s[id]) + l[id])) -
                        (1.0 * p[id] * (s[id] - 1) / ((s[id] - 1) + l[id])),
                    id));
    if (++s[id], s[id] < l[id])
      A.insert(element((1.0 * p[id] * (s[id] + 1) / ((s[id] + 1) + l[id])) -
                           (1.0 * p[id] * (s[id]) / ((s[id]) + l[id])),
                       id));
    B.insert(element((1.0 * p[id] * (s[id]) / ((s[id]) + l[id])) -
                         (1.0 * p[id] * (s[id] - 1) / ((s[id] - 1) + l[id])),
                     id));
    --t;
  }
  while (!A.empty() && !B.empty()) {
    set<element>::iterator mx = --A.end(), mi = B.begin();
    if (mx->val <= mi->val) break;
    ans += mx->val - mi->val;
    int imx = mx->pos, imi = mi->pos;
    A.erase(mx);
    B.erase(mi);
    A.erase(element((1.0 * p[imi] * (s[imi] + 1) / ((s[imi] + 1) + l[imi])) -
                        (1.0 * p[imi] * (s[imi]) / ((s[imi]) + l[imi])),
                    imi));
    B.erase(element((1.0 * p[imx] * (s[imx]) / ((s[imx]) + l[imx])) -
                        (1.0 * p[imx] * (s[imx] - 1) / ((s[imx] - 1) + l[imx])),
                    imx));
    if (++s[imx], s[imx] < l[imx])
      A.insert(element((1.0 * p[imx] * (s[imx] + 1) / ((s[imx] + 1) + l[imx])) -
                           (1.0 * p[imx] * (s[imx]) / ((s[imx]) + l[imx])),
                       imx));
    B.insert(
        element((1.0 * p[imx] * (s[imx]) / ((s[imx]) + l[imx])) -
                    (1.0 * p[imx] * (s[imx] - 1) / ((s[imx] - 1) + l[imx])),
                imx));
    if (--s[imi])
      B.insert(
          element((1.0 * p[imi] * (s[imi]) / ((s[imi]) + l[imi])) -
                      (1.0 * p[imi] * (s[imi] - 1) / ((s[imi] - 1) + l[imi])),
                  imi));
    A.insert(element((1.0 * p[imi] * (s[imi] + 1) / ((s[imi] + 1) + l[imi])) -
                         (1.0 * p[imi] * (s[imi]) / ((s[imi]) + l[imi])),
                     imi));
  }
}
inline void Add(const int& x) {
  ans -= (1.0 * p[x] * (s[x]) / ((s[x]) + l[x]));
  A.erase(element((1.0 * p[x] * (s[x] + 1) / ((s[x] + 1) + l[x])) -
                      (1.0 * p[x] * (s[x]) / ((s[x]) + l[x])),
                  x));
  B.erase(element((1.0 * p[x] * (s[x]) / ((s[x]) + l[x])) -
                      (1.0 * p[x] * (s[x] - 1) / ((s[x] - 1) + l[x])),
                  x));
  if (++l[x], ans += (1.0 * p[x] * (s[x]) / ((s[x]) + l[x])), t)
    ++s[x], --t,
        ans += (1.0 * p[x] * (s[x]) / ((s[x]) + l[x])) -
               (1.0 * p[x] * (s[x] - 1) / ((s[x] - 1) + l[x]));
  if (s[x] < l[x])
    A.insert(element((1.0 * p[x] * (s[x] + 1) / ((s[x] + 1) + l[x])) -
                         (1.0 * p[x] * (s[x]) / ((s[x]) + l[x])),
                     x));
  if (s[x])
    B.insert(element((1.0 * p[x] * (s[x]) / ((s[x]) + l[x])) -
                         (1.0 * p[x] * (s[x] - 1) / ((s[x] - 1) + l[x])),
                     x));
  reset();
}
inline void Del(const int& x) {
  ans -= (1.0 * p[x] * (s[x]) / ((s[x]) + l[x]));
  A.erase(element((1.0 * p[x] * (s[x] + 1) / ((s[x] + 1) + l[x])) -
                      (1.0 * p[x] * (s[x]) / ((s[x]) + l[x])),
                  x));
  B.erase(element((1.0 * p[x] * (s[x]) / ((s[x]) + l[x])) -
                      (1.0 * p[x] * (s[x] - 1) / ((s[x] - 1) + l[x])),
                  x));
  if (s[x] == l[x]) --s[x], ++t;
  --l[x];
  ans += (1.0 * p[x] * (s[x]) / ((s[x]) + l[x]));
  if (s[x] < l[x])
    A.insert(element((1.0 * p[x] * (s[x] + 1) / ((s[x] + 1) + l[x])) -
                         (1.0 * p[x] * (s[x]) / ((s[x]) + l[x])),
                     x));
  if (s[x])
    B.insert(element((1.0 * p[x] * (s[x]) / ((s[x]) + l[x])) -
                         (1.0 * p[x] * (s[x] - 1) / ((s[x] - 1) + l[x])),
                     x));
  reset();
}
int main() {
  register int i;
  for (scanf("%d%d%d", &n, &t, &q), i = 1; i <= n; ++i) scanf("%d", &p[i]);
  for (i = 1; i <= n; ++i)
    scanf("%d", &l[i]), A.insert(element((1.0 * p[i] * (1) / ((1) + l[i])) -
                                             (1.0 * p[i] * (0) / ((0) + l[i])),
                                         i));
  for (reset(), i = 1; i <= n; ++i)
    if (s[i])
      B.insert(element((1.0 * p[i] * (s[i]) / ((s[i]) + l[i])) -
                           (1.0 * p[i] * (s[i] - 1) / ((s[i] - 1) + l[i])),
                       i));
  for (i = 1; i <= q; printf("%.10lf\n", ans), ++i)
    if (scanf("%d%d", &x, &y), x == 1)
      Add(y);
    else
      Del(y);
  return 0;
}
