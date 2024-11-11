#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <class T>
int chmin(T &t, T f) {
  return (t > f) ? (t = f, 1) : 0;
}
template <class T>
int chmax(T &t, T f) {
  return (t < f) ? (t = f, 1) : 0;
}
inline int getint() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"), -1);
}
inline double getdouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"), -1);
}
pair<int, int> operator-(const pair<int, int> &a, const pair<int, int> &b) {
  return pair<int, int>(a.first - b.first, a.second - b.second);
}
int operator^(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first * b.second - a.second * b.first;
}
int sign(int first) { return (first > 0) - (first < 0); }
int ccw(const pair<int, int> &a, const pair<int, int> &b,
        const pair<int, int> &c) {
  return sign((a - c) ^ (b - c));
}
vector<pair<int, int> > halfHull(vector<pair<int, int> > &a) {
  vector<pair<int, int> > ret;
  for (int i = (int)(0); i < (int)(((int)(a).size())); i++) {
    while (((int)(ret).size()) >= 2 &&
           ccw(ret[((int)(ret).size()) - 2], ret.back(), a[i]) >= 0)
      ret.pop_back();
    ret.push_back(a[i]);
  }
  if (!ret.empty()) ret.pop_back();
  return ret;
}
vector<pair<int, int> > convexHull(vector<pair<int, int> > a) {
  sort(a.begin(), a.end());
  vector<pair<int, int> > ret = halfHull(a);
  reverse(a.begin(), a.end());
  vector<pair<int, int> > b = halfHull(a);
  for (int i = (int)(0); i < (int)(((int)(b).size())); i++) ret.push_back(b[i]);
  return ret;
}
int exist[9][9];
void myCode() {
  int m = getint(), n = getint();
  getint();
  int slen = getint();
  vector<vector<pair<int, int> > > a(9);
  for (int i = (int)(0); i < (int)(m); i++)
    for (int j = (int)(0); j < (int)(n); j++)
      a[getint() - 1].push_back(pair<int, int>(i, j));
  for (int i = (int)(0); i < (int)(9); i++) {
    a[i] = convexHull(a[i]);
  }
  int last = getint() - 1;
  for (int i = (int)(0); i < (int)(slen - 1); i++) {
    int first = getint() - 1;
    exist[first][last] = exist[last][first] = 1;
    last = first;
  }
  int ret = 0;
  for (int i = (int)(0); i < (int)(9); i++)
    for (int j = (int)(i + 1); j < (int)(9); j++)
      if (exist[i][j])
        for (int s = (int)(0); s < (int)(((int)(a[i]).size())); s++)
          for (int t = (int)(0); t < (int)(((int)(a[j]).size())); t++)
            chmax(ret, abs(a[i][s].first - a[j][t].first) +
                           abs(a[i][s].second - a[j][t].second));
  printf("%d\n", ret);
}
int main() {
  myCode();
  return 0;
}
