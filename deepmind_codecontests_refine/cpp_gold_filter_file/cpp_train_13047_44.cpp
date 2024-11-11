#include <bits/stdc++.h>
using namespace std;
int n, k, h;
vector<pair<pair<int, int>, int> > V;
int ans[100005];
double eps = 1.0e-9;
bool can(double T) {
  int lem = k, per = 0;
  for (; per < n && lem > 0;) {
    double t = 1.0 * lem * h;
    t /= (-V[per].first.second);
    if (T >= t || (t - T) <= eps) {
      lem--;
    }
    per++;
  }
  if (lem <= 0) return true;
  return false;
}
void doit(double T) {
  int lem = k, per = 0;
  for (; per < n && lem > 0;) {
    double t = 1.0 * lem * h;
    t /= (-V[per].first.second);
    if (T >= t || (t - T) <= eps) {
      ans[lem] = V[per].second;
      lem--;
    }
    per++;
  }
  for (int i = 1; i <= k; i++) printf("%d ", ans[i] + 1);
  printf("\n");
}
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  scanf("%d", &h);
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    V.push_back(make_pair(make_pair(-w, 0), i));
  }
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    V[i].first.second = -v;
  }
  sort(V.begin(), V.end());
  double lo = 0.0, hi = 2.0 * 1e9;
  int iter = 300;
  while (iter > 0) {
    double mid = (hi + lo) / 2.0;
    if (can(mid))
      hi = mid;
    else
      lo = mid;
    iter--;
  }
  doit(hi);
  return 0;
}
