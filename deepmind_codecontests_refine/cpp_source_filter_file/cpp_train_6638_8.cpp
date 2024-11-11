#include <bits/stdc++.h>
using namespace std;
bool ccw(long long x1, long long y1, long long x2, long long y2) {
  return x2 * y1 - x1 * y2;
}
typedef struct point {
  long long x, y, num;
  point(long long x, long long y, long long num) : x(x), y(y), num(num) {}
  point operator-() const { return {-x, -y, -num}; }
  bool operator<(const point &O) const {
    if ((make_pair(x, y) > make_pair(0LL, 0LL)) ^
        (make_pair(O.x, O.y) > make_pair(0LL, 0LL)))
      return (make_pair(x, y) > make_pair(0LL, 0LL));
    return ccw(x, y, O.x, O.y) > 0;
  }
};
bool is_60angle(point X, point Y) {
  return (X.x * Y.x + X.y * Y.y) * 2 + 1e-6 >=
         sqrt(X.x * X.x + X.y * X.y) * sqrt(Y.x * Y.x + Y.y * Y.y);
}
int N;
stack<point> P;
int nxt_pos[2000010];
int ans[2000010];
int main(void) {
  scanf("%d", &N);
  long long x, y;
  for (int i = 1; i <= N; i++)
    scanf("%lld%lld", &x, &y), P.push(point(x, y, i));
  if (N == 1) return 0 * printf("1");
  int cnt = N;
  while (P.size() > 2) {
    vector<point> T;
    point p1 = P.top();
    P.pop();
    point p2 = P.top();
    P.pop();
    point p3 = P.top();
    P.pop();
    T.clear();
    T.push_back(p1);
    T.push_back(-p1);
    T.push_back(p2);
    T.push_back(-p2);
    T.push_back(p3);
    T.push_back(-p3);
    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < T.size(); i++) {
      for (int j = i + 1; j < T.size(); j++) {
        if (T[i].num == -T[j].num) continue;
        if (is_60angle(T[i], T[j])) pos1 = i, pos2 = j;
      }
    }
    ++cnt;
    nxt_pos[abs(T[pos1].num)] = cnt * (T[pos1].num / abs(T[pos1].num));
    nxt_pos[abs(T[pos2].num)] = -cnt * (T[pos2].num / abs(T[pos2].num));
    point pos3 = p1;
    if (abs(T[pos1].num) != abs(p2.num) && abs(T[pos2].num) != abs(p2.num))
      pos3 = p2;
    if (abs(T[pos1].num) != abs(p3.num) && abs(T[pos2].num) != abs(p3.num))
      pos3 = p3;
    P.push(point(T[pos1].x - T[pos2].x, T[pos1].y - T[pos2].y, cnt));
    P.push(pos3);
  }
  point p1 = P.top();
  P.pop();
  point p2 = P.top();
  P.pop();
  ++cnt;
  if ((p1.x + p2.x) * (p1.x + p2.x) + (p1.y + p2.y) * (p1.y + p2.y) >
      (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y))
    nxt_pos[p1.num] = cnt, nxt_pos[p2.num] = cnt;
  else
    nxt_pos[p1.num] = cnt, nxt_pos[p2.num] = -cnt;
  int cur_pos;
  ans[cnt] = 1;
  for (int i = cnt; i >= 1; i--) {
    if (nxt_pos[i] == 0) continue;
    ans[i] = ans[abs(nxt_pos[i])] * nxt_pos[i] / abs(nxt_pos[i]);
  }
  for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
  return 0;
}
