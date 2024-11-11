#include <bits/stdc++.h>
using namespace std;
long long acum[4 * 2000007], menor[4 * 2000007], idx[4 * 2000007];
vector<int> comp;
void build(int id, int l, int r) {
  if (l == r) {
    menor[id] = -comp[l];
    idx[id] = comp[id];
  } else {
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    menor[id] = min(menor[2 * id], menor[2 * id + 1]);
    idx[id] = (menor[id] == menor[2 * id]) ? idx[2 * id] : idx[2 * id + 1];
  }
}
void add(int id, int l, int r, long long val) {
  menor[id] += val;
  acum[id] += val;
}
void update(int id, int l, int r, int x, int y, long long val) {
  if (l > y || r < x)
    return;
  else if (x <= l && r <= y)
    add(id, l, r, val);
  else {
    int mid = (l + r) / 2;
    add(2 * id, l, mid, acum[id]);
    add(2 * id + 1, mid + 1, r, acum[id]);
    acum[id] = 0;
    update(2 * id, l, mid, x, y, val);
    update(2 * id + 1, mid + 1, r, x, y, val);
    menor[id] = min(menor[2 * id], menor[2 * id + 1]);
    idx[id] = (menor[id] == menor[2 * id]) ? idx[2 * id] : idx[2 * id + 1];
  }
}
pair<long long, long long> query(int id, int l, int r, int x, long long y) {
  if (l > y || r < x)
    return {1e18 + 7, 1e9 + 7};
  else if (x <= l && r <= y)
    return {menor[id], idx[id]};
  else {
    int mid = (l + r) / 2;
    add(2 * id, l, mid, acum[id]);
    add(2 * id + 1, mid + 1, r, acum[id]);
    acum[id] = 0;
    return min(query(2 * id, l, mid, x, y),
               query(2 * id + 1, mid + 1, r, x, y));
  }
}
struct pt {
  long long x, y;
  long long v;
};
bool cmp(pt a, pt b) { return max(a.x, a.y) < max(b.x, b.y); }
pt p[2000007];
int main() {
  int n;
  scanf("%d", &n);
  comp.push_back(0);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", &p[i].x, &p[i].y, &p[i].v);
    comp.push_back(p[i].x);
    if (p[i].x > 0) comp.push_back(p[i].x - 1);
    comp.push_back(p[i].y);
    if (p[i].y > 0) comp.push_back(p[i].y - 1);
  }
  sort(p, p + n, cmp);
  sort(comp.begin(), comp.end());
  int sz = unique(comp.begin(), comp.end()) - comp.begin();
  comp.resize(sz);
  build(1, 0, sz);
  long long sum = 0LL;
  long long ans = 0LL;
  pair<long long, long long> points = {comp[sz - 1] + 1LL, comp[sz - 1] + 1LL};
  for (int i = 0; i < n;) {
    long long b = max(p[i].x, p[i].y);
    while (i < n && max(p[i].x, p[i].y) == b) {
      sum += p[i].v;
      int xx = lower_bound(comp.begin(), comp.end(), p[i].x) - comp.begin();
      int yy = lower_bound(comp.begin(), comp.end(), p[i].y) - comp.begin();
      update(1, 0, sz - 1, min(xx, yy) + 1, sz - 1, p[i].v);
      i++;
    }
    int bb = lower_bound(comp.begin(), comp.end(), bb) - comp.begin();
    pair<long long, long long> minus = query(1, 0, sz - 1, 0, bb);
    if (ans < (sum - b - minus.first)) {
      ans = sum - b - minus.first;
      points = {minus.second, b};
    }
  }
  printf("%lld\n", ans);
  printf("%lld %lld %lld %lld\n", points.first, points.first, points.second,
         points.second);
  return 0;
}
