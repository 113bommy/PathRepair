#include <bits/stdc++.h>
using namespace std;
struct Target {
  int x, y, t;
  double p;
  void read() { scanf("%d%d%d%lf", &x, &y, &t, &p); }
} T;
vector<Target> Vec;
double dist(const Target &A, const Target &B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
bool CMP(const Target &A, const Target &B) { return A.t < B.t; }
double a[1003];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    T.read();
    Vec.push_back(T);
  }
  sort(Vec.begin(), Vec.end(), CMP);
  double Max = 0;
  for (int i = 1; i <= n; i++) {
    T = Vec[i - 1];
    a[i] = T.p;
    for (int j = i - 1; j; j--)
      if (T.t - Vec[j - 1].t >= dist(T, Vec[j - 1]))
        a[i] = max(a[i], T.p + Vec[j - 1].p);
    Max = max(Max, a[i]);
  }
  printf("%.9lf", Max);
  return 0;
}
