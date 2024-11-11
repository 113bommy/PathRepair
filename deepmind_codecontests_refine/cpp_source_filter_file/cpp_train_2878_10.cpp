#include <bits/stdc++.h>
struct At {
  double t;
  int dis_t;
  int id;
  At() {
    t = 0;
    dis_t = 0;
    id = 0;
  }
  At(double ta, int dis_ta, int ida) {
    t = ta;
    dis_t = dis_ta;
    id = ida;
  }
};
bool cmp1(At a, At b) { return a.t < b.t; }
bool cmp2(At a, At b) { return a.t > b.t; }
using namespace std;
int n;
double w;
At t1[100000 + 10];
At t2[100000 + 10];
int x[100000 + 10];
int v[100000 + 10];
int tre[100000 + 10];
int low_bit(int x) { return x & (-x); }
int query(int k) {
  int res = 0;
  while (k > 0) {
    res += tre[k];
    k -= low_bit(k);
  }
  return res;
}
void update(int k) {
  while (k <= n) {
    tre[k]++;
    k += low_bit(k);
  }
}
int main() {
  scanf("%d %lf", &n, &w);
  w += 0.000001;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &x[i], &v[i]);
    t1[i].t = double(-x[i]) / (v[i] - w);
    t1[i].id = i;
  }
  sort(t1 + 1, t1 + n + 1, cmp1);
  int num = 0;
  for (int i = 1; i <= n; ++i) {
    if (t1[i].t == t1[i - 1].t)
      t1[i].dis_t = num;
    else
      t1[i].dis_t = ++num;
    t2[i].t = double(-x[t1[i].id]) / (v[t1[i].id] + w);
    t2[i].id = i;
  }
  sort(t2 + 1, t2 + n + 1, cmp2);
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int target = t1[t2[i].id].dis_t;
    res += query(target);
    update(target);
  }
  printf("%lld\n", res);
  return 0;
}
