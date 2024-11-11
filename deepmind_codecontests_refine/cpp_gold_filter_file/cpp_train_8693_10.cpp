#include <bits/stdc++.h>
using namespace std;
struct segmento {
  int x0, y0, x1, y1;
  segmento(int a, int b, int c, int d) {
    x0 = min(a, c);
    x1 = max(a, c);
    y0 = max(b, d);
    y1 = min(b, d);
  }
};
struct Evento {
  int x, y;
  bool e;
  Evento(int a, int b, bool c) { x = a, y = b, e = c; }
  bool isEntrada() { return e; }
  bool operator<(const Evento &other) const {
    if (y > other.y) return true;
    if (y < other.y) return false;
    if (e && !other.e) return true;
    if (!e && other.e) return false;
    return x < other.x;
  }
};
int n;
set<int> xs;
vector<segmento> all;
vector<Evento> eventos;
vector<segmento> horizontal, vertical;
vector<segmento> h, v;
map<int, int> cx;
int bit[100000];
bool orderX(const segmento &A, const segmento &B) {
  if (A.x0 < B.x0) return true;
  if (A.x0 > B.x0) return false;
  return A.y0 > B.y0;
}
bool orderY(const segmento &A, const segmento &B) {
  if (A.y0 > B.y0) return true;
  if (A.y0 < B.y0) return false;
  return A.x0 < B.x0;
}
long long _merge() {
  sort(horizontal.begin(), horizontal.end(), orderY);
  if (horizontal.size()) h.push_back(horizontal[0]);
  for (int i = 1; i < horizontal.size(); i++)
    if (horizontal[i].y0 == h[(int)h.size() - 1].y0 &&
        horizontal[i].x0 <= h[(int)h.size() - 1].x1)
      h[(int)h.size() - 1].x1 = max(h[(int)h.size() - 1].x1, horizontal[i].x1);
    else
      h.push_back(horizontal[i]);
  horizontal = h;
  h.clear();
  sort(vertical.begin(), vertical.end(), orderX);
  if (vertical.size()) v.push_back(vertical[0]);
  for (int i = 1; i < vertical.size(); i++)
    if (vertical[i].x0 == v[(int)v.size() - 1].x0 &&
        vertical[i].y0 >= v[(int)v.size() - 1].y1)
      v[(int)v.size() - 1].y1 = min(v[(int)v.size() - 1].y1, vertical[i].y1);
    else
      v.push_back(vertical[i]);
  vertical = v;
  v.clear();
  long long sum = 0;
  for (int i = 0; i < horizontal.size(); i++) {
    sum += horizontal[i].x1 - horizontal[i].x0 + 1;
  }
  for (int i = 0; i < vertical.size(); i++) {
    sum += vertical[i].y0 - vertical[i].y1 + 1;
  }
  return sum;
}
void build() {
  for (int i = 0; i < all.size(); i++)
    if (all[i].x0 == all[i].x1)
      vertical.push_back(all[i]);
    else
      horizontal.push_back(all[i]);
  all.clear();
}
int compress() {
  for (int i = 0; i < vertical.size(); i++) xs.insert(vertical[i].x0);
  for (int j = 0; j < horizontal.size(); j++) {
    xs.insert(horizontal[j].x0);
    xs.insert(horizontal[j].x1);
  }
  int k = 1;
  for (set<int>::iterator it = xs.begin(); it != xs.end(); it++) cx[*it] = k++;
  xs.clear();
  return k;
}
void update(int x, int delta) {
  while (x < 100000 && x > 0) {
    bit[x] += delta;
    x += x & -x;
  }
}
long long query(int x) {
  long long sum = 0;
  while (x > 0 && x < 100000) {
    sum += bit[x];
    x -= x & -x;
  }
  return sum;
}
long long process() {
  build();
  long long sum = _merge();
  compress();
  for (int i = 0; i < vertical.size(); i++) {
    Evento e(vertical[i].x0, vertical[i].y0, true);
    Evento e2(vertical[i].x0, vertical[i].y1, false);
    eventos.push_back(e);
    eventos.push_back(e2);
  }
  vertical.clear();
  int e = 0;
  sort(eventos.begin(), eventos.end());
  for (int i = 0; i < horizontal.size(); i++) {
    while (e < eventos.size() &&
           (eventos[e].y > horizontal[i].y0 ||
            (eventos[e].y == horizontal[i].y0 && eventos[e].isEntrada()))) {
      Evento evento = eventos[e];
      if (evento.isEntrada())
        update(cx[evento.x], 1);
      else
        update(cx[evento.x], -1);
      e++;
    }
    sum -= (query(cx[horizontal[i].x1]) - query(cx[horizontal[i].x0] - 1));
  }
  return sum;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    segmento s(a, b, c, d);
    all.push_back(s);
  }
  printf("%lld", process());
  return 0;
}
