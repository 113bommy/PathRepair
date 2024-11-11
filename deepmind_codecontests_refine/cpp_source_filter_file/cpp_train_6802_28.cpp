#include <bits/stdc++.h>
using namespace std;
int s, a, b, c;
struct Node {
  int k, num;
  double w;
} data[3];
bool cmp1(Node a, Node b) { return a.k > b.k; }
bool cmp2(Node a, Node b) { return a.num < b.num; }
double compute(double s, double &w) {
  double g = 0, h = s;
  while (h - g > 1e-10) {
    double t1 = (h - g) / 3 + g, t2 = (h - g) * 2 / 3 + g;
    double w1 = (data[1].k == 0 ? 0 : data[1].k * log(t1)) +
                (data[2].k == 0 ? 0 : data[2].k * log(s - t1)),
           w2 = (data[1].k == 0 ? 0 : data[1].k * log(t2)) +
                (data[2].k == 0 ? 0 : data[2].k * log(s - t2));
    if (w1 < w2)
      g = t1;
    else
      h = t2;
  }
  w = g;
  return (data[1].k == 0 ? 0 : data[1].k * log(g)) +
         (data[2].k == 0 ? 0 : data[2].k * log(s - g));
}
int main() {
  scanf("%d%d%d%d", &s, &data[0].k, &data[1].k, &data[2].k);
  double g = 0, h = s, ans = -1e18;
  while (h - g > 1e-10) {
    double t1 = (h - g) / 3 + g, t2 = (h - g) * 2 / 3 + g, h1, h2;
    double w1 = compute(s - t1, h1) + data[0].k * log(t1),
           w2 = compute(s - t2, h2) + data[0].k * log(t2);
    if (w1 < w2) {
      g = t1;
      if (w2 > ans) {
        data[0].w = t2;
        data[1].w = h2;
        ans = w2;
      }
    } else {
      h = t2;
      if (w1 > ans) {
        data[0].w = t1;
        data[1].w = h1;
        ans = w1;
      }
    }
  }
  data[2].w = s - data[0].w - data[1].w;
  printf("%.8f %.8f %.8f\n", data[0].w, data[1].w, data[2].w);
  return 0;
}
