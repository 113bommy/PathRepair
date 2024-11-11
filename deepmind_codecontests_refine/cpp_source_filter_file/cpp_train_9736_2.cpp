#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const int N = 2e5 + 10;
const long double eps = 1e-8;
int dcmp(long double x) { return x < -eps ? -1 : (x > eps); }
struct item {
  int id;
  long double v;
  item(int u, long double x) : id(u), v(x) {}
  friend bool operator<(item A, item B) {
    if (dcmp(A.v - B.v)) return A.v < B.v;
    return A.id < B.id;
  }
};
set<item> A, B;
int rb[N], p[N], c[N];
int n, t, q;
long double ans;
inline long double getA(int x) {
  return (long double)p[x] * rb[x] / (rb[x] + c[x]) / (rb[x] + c[x] + 1);
}
inline long double getB(int x) {
  return (long double)p[x] * rb[x] / (rb[x] + c[x]) / (rb[x] + c[x] - 1);
}
int cnt;
void Ins(int u) {
  if (c[u] < rb[u]) A.insert(item(u, getA(u)));
  if (c[u]) B.insert(item(u, getB(u)));
}
void Del(int u) {
  if (c[u] < rb[u]) A.erase(item(u, getA(u)));
  if (c[u]) B.erase(item(u, getB(u)));
}
void ins(int u) {
  Del(u);
  ans += getA(u);
  c[u]++, t--;
  Ins(u);
}
void del(int u) {
  Del(u);
  ans -= getB(u);
  c[u]--, t++;
  Ins(u);
}
int main() {
  rd(n), rd(t), rd(q);
  for (int i = 1; i <= n; ++i) rd(p[i]);
  for (int i = 1; i <= n; ++i) rd(rb[i]), Ins(i);
  while (t && !A.empty()) ins(A.rbegin()->id);
  while (q--) {
    int ty, x;
    rd(ty), rd(x);
    if (c[x] == rb[x] && ty == 2) del(x);
    Del(x), ans -= (long double)p[x] * c[x] / (rb[x] + c[x]);
    if (ty == 1)
      rb[x]++;
    else
      rb[x]--;
    Ins(x), ans += (long double)p[x] * c[x] / (rb[x] + c[x]);
    if (t > 0 && !A.empty()) ins(A.rbegin()->id);
    if (!A.empty() && !B.empty() &&
        dcmp((A.rbegin()->v) - (B.begin()->v)) > 0) {
      int x = B.begin()->id, y = A.rbegin()->id;
      del(x), ins(y);
    }
    printf("%.10Lf\n", ans);
  }
  return 0;
}
