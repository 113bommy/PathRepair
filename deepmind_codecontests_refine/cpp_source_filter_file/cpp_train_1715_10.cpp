#include <bits/stdc++.h>
using namespace std;
template <typename T>
string TO_STR(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <typename T>
T TO_NUM(const string &Text) {
  stringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
int IN_GRID(int x, int y, int r, int c) {
  return (x >= 0 && x < r && y >= 0 && y < c ? 1 : 0);
}
int ON(int N, int pos) { return N = N | (1 << pos); }
int OFF(int N, int pos) { return N = N & ~(1 << pos); }
bool IS_ON(int N, int pos) { return (bool)(N & (1 << pos)); }
int IS_LEAP_YEAR(int m) {
  if (m % 4 == 0 && m % 100 != 0)
    return 1;
  else if (m % 400 == 0)
    return 1;
  else
    return 0;
}
int DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string MONTHS[] = {"January",   "February", "March",    "April",
                   "May",       "June",     "July",     "August",
                   "September", "October",  "November", "December"};
struct NODE {
  int id, from, to, cost;
  NODE() {}
  NODE(int _id, int _from, int _to, int _cost) {
    id = _id, from = _from, to = _to, cost = _cost;
  }
};
int DX4[] = {-1, 0, 1, 0};
int DY4[] = {0, 1, 0, -1};
const double PI = acos(-1.0), EPS = 1e-9;
const int MAX = 2e5 + 5, MOD = 1e9 + 7;
const long long INF = 1e18;
int n, m;
int from[MAX], len[MAX], tot[MAX];
int seg[2][4 * MAX], dp[MAX];
void update(int id, int c, int s, int e, int qs, int qe, int v) {
  if (s == qs && e == qe) {
    seg[id][c] = v;
    return;
  }
  int m = (s + e) / 2;
  if (qe <= m)
    update(id, 2 * c + 1, s, m, qs, qe, v);
  else if (qs > m)
    update(id, 2 * c + 2, m + 1, e, qs, qe, v);
  else {
    update(id, 2 * c + 1, s, m, qs, m, v);
    update(id, 2 * c + 2, m + 1, e, m + 1, qe, v);
  }
  seg[id][c] = max(seg[id][2 * c + 1], seg[id][2 * c + 2]);
}
int query(int id, int c, int s, int e, int qs, int qe) {
  if (s == qs && e == qe) return seg[id][c];
  int m = (s + e) / 2;
  if (qe <= m)
    return query(id, 2 * c + 1, s, m, qs, qe);
  else if (qs > m)
    return query(id, 2 * c + 2, m + 1, e, qs, qe);
  else {
    int x = query(id, 2 * c + 1, s, m, qs, m);
    int y = query(id, 2 * c + 2, m + 1, e, m + 1, qe);
    return max(x, y);
  }
}
int getPos(int st, int ed) {
  int lo = st, hi = ed, best = ed;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int cur = query(1, 0, 0, n - 1, lo, mid);
    if (cur > ed) {
      best = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  return best;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &from[i], &len[i]);
    tot[i] = from[i] + len[i];
    update(0, 0, 0, n - 1, i, i, tot[i]);
  }
  for (int i = n - 1; i >= 0; i--) {
    update(1, 0, 0, n - 1, i, i, i);
    int cover = upper_bound(from, from + n, tot[i]) - from - 1;
    int last = query(1, 0, 0, n - 1, i, cover);
    update(1, 0, 0, n - 1, i, i, last);
    if (last != n - 1)
      dp[i] = from[last + 1] - query(0, 0, 0, n - 1, i, last) + dp[last + 1];
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    y = getPos(x, y);
    printf("%d\n", dp[x] - dp[y]);
  }
  return 0;
}
