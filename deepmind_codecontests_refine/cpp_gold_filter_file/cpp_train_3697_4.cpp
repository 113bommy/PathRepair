#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12;
struct Point {
  long double x;
  long double y;
  Point(){};
  Point(long double _x, long double _y) : x(_x), y(_y){};
};
int N;
vector<Point> p;
int main() {
  scanf("%d", &N);
  int nb_orig = 0;
  for (int i = 0; i < N; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c)
      p.push_back(Point(b * c / (long double)(a * a + b * b),
                        a * c / (long double)(a * a + b * b)));
    else
      nb_orig++;
  }
  int orig_N = N;
  N = p.size();
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    vector<long double> pentes;
    int nb_vert = 0;
    for (int j = 0; j < N; j++)
      if (i != j) {
        if (abs(p[j].x - p[i].x) < EPS)
          nb_vert++;
        else
          pentes.push_back((p[j].y - p[i].y) / (p[j].x - p[i].x));
      }
    ans += nb_vert * (nb_vert - 1) / 2;
    sort(pentes.begin(), pentes.end());
    int act = 1;
    for (int j = 1; j < (int)pentes.size(); j++) {
      if (abs(pentes[j] - pentes[j - 1]) < EPS)
        act++;
      else {
        ans += act * (act - 1) / 2;
        act = 1;
      }
    }
    ans += act * (act - 1) / 2;
  }
  ans = ans / 3 + ((nb_orig == 2) ? orig_N - 2 : 0);
  printf("%I64d\n", ans);
  return 0;
}
