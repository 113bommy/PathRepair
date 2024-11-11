#include <bits/stdc++.h>
using namespace std;
map<pair<int, pair<long long int, long long int> >, long long int> dp;
char s[1000002], t[1000002];
bool compare(pair<double, int> a, pair<double, int> b) {
  if (a.first < b.first || (a.first == b.first && a.second > b.second))
    return true;
  return false;
}
int main() {
  int i, n;
  double a, b, maximo, p1, p2, t1, t2, k;
  vector<pair<double, int> > v;
  pair<double, int> ins;
  scanf("%d%lf%lf%lf", &n, &t1, &t2, &k);
  for (i = 1; i <= n; i++) {
    scanf("%lf%lf", &a, &b);
    p1 = (((100.0 - k) * a * t1) / 100.0) + (t2 * b);
    p2 = (((100.0 - k) * b * t1) / 100.0) + (t2 * a);
    ins.first = max(p1, p2);
    ins.second = i;
    v.push_back(ins);
  }
  sort(v.begin(), v.end(), compare);
  for (i = v.size() - 1; i >= 0; i--) {
    printf("%d %3.2lf\n", v[i].second, v[i].first);
  }
  return 0;
}
