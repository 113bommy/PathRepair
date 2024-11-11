#include <bits/stdc++.h>
using namespace std;
inline int ab(int x) { return x > 0 ? x : -x; }
inline long long sq(long long x) { return x * x; }
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int p[500010][2];
double d[500010];
pair<int, int> a[500010];
map<pair<int, int>, vector<int> > ma;
int mls(int x, int y) {
  return ab(p[x][0]) + ab(p[x][1]) < ab(p[y][0]) + ab(p[y][1]);
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i][0], &p[i][1]);
    if (p[i][0] || p[i][1]) {
      int g = gcd(ab(p[i][0]), ab(p[i][1]));
      a[i] = make_pair(p[i][0] / g, p[i][1] / g);
    }
    ma[a[i]].push_back(i);
    d[i] = sqrt(sq(p[i][0]) + sq(p[i][1]));
  }
  vector<double> vd;
  for (map<pair<int, int>, vector<int> >::iterator it = ma.begin();
       it != ma.end(); it++) {
    vector<int> &v = it->second;
    sort(v.begin(), v.end(), mls);
    int h = 0, t = (int)v.size();
    double s = 0;
    for (int j = 0; j < v.size(); j++) {
      int c = k - 1 - 2 * j;
      if (c >= 0) {
        vd.push_back(d[v[--t]] * c);
      } else {
        double td = d[v[h++]];
        vd.push_back(td * (k - 1 - 2 * ((int)v.size() - h)) + 2 * s);
        s -= td;
      }
    }
  }
  sort(vd.begin(), vd.end());
  reverse(vd.begin(), vd.end());
  double ans = 0;
  for (int i = 0; i < k; i++) {
    ans += vd[i];
  }
  printf("%.12f\n", ans);
  return 0;
}
