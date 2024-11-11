#include <bits/stdc++.h>
using namespace std;
int Sig(double a) {
  if (a < -1e-8) return -1;
  return a > 1e-8;
}
double pp[110];
int qq;
double v;
void get(double x, double y) {
  double a = -x * x * 9.8 / (2.0 * v * v);
  double b = x;
  double c = -y - x * x * 9.8 / (2.0 * v * v);
  double delta = b * b - 4.0 * a * c;
  if (Sig(delta) < 0) return;
  if (Sig(delta) == 0) delta = 0;
  double x1 = (-b + sqrt(delta)) / (2.0 * a);
  double x2 = (-b - sqrt(delta)) / (2.0 * a);
  pp[qq++] = atan(x1);
  pp[qq++] = atan(x2);
}
struct Seg {
  double x, y;
  void in() { scanf("%lf %lf", &x, &y); }
} seg[100010];
bool cmp_seg(Seg a, Seg b) { return a.x < b.x; }
double angle[100010];
struct Event {
  double s;
  int flag;
  int id;
  Event() {}
  Event(double s0, int flag0, int id0) : s(s0), flag(flag0), id(id0) {}
};
vector<Event> g;
bool cmp(Event a, Event b) { return a.s < b.s; }
set<int> ooxx;
int who[100010];
int main() {
  g.clear();
  int n;
  scanf("%d %lf", &n, &v);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &angle[i]);
    g.push_back(Event(angle[i], 0, i));
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) seg[i].in();
  sort(seg, seg + m, cmp_seg);
  for (int i = 0; i < m; i++) {
    qq = 0;
    get(seg[i].x, 0);
    get(seg[i].x, seg[i].y);
    sort(pp, pp + qq);
    if (qq > 0) {
      g.push_back(Event(pp[0] - 1e-4, -1, i));
      g.push_back(Event(pp[1] + 1e-4, 1, i));
    }
    if (qq > 2) {
      g.push_back(Event(pp[2] - 1e-4, -1, i));
      g.push_back(Event(pp[3] + 1e-4, 1, i));
    }
  }
  sort(g.begin(), g.end(), cmp);
  ooxx.clear();
  memset(who, -1, sizeof(who));
  int len = g.size();
  for (int i = 0; i < len; i++) {
    Event o = g[i];
    if (o.flag == -1) ooxx.insert(o.id);
    if (o.flag == 1) ooxx.erase(o.id);
    if (o.flag == 0) {
      set<int>::iterator ll = ooxx.begin();
      if (ll != ooxx.end()) who[o.id] = *ll;
    }
  }
  for (int i = 0; i < n; i++) {
    if (who[i] == -1) {
      double t = 2.0 * v * sin(angle[i]) / 9.8;
      double x = v * cos(angle[i]) * t;
      double y = 0;
      printf("%.8f %.8f\n", x, y);
    } else {
      double x = seg[who[i]].x;
      double t = x / v / cos(angle[i]);
      double y = v * sin(angle[i]) * t - 9.8 * t * t * 0.5;
      printf("%.8f %.8f\n", x, y);
    }
  }
  return 0;
}
