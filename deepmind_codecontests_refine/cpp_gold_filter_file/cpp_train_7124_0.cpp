#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const double PI = atan(1.0) * 4;
const int inf = ~0u >> 1;
const int Dx[] = {1, 0, -1, 0}, Dy[] = {0, 1, 0, -1};
template <class T>
bool chmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool chmax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
int sgn(T first) {
  return (first > eps) - (first < -eps);
}
vector<pair<double, int> > vec;
int cnt;
void add(double l, double r) {
  while (l <= -PI) l += 2 * PI;
  while (l > PI) l -= 2 * PI;
  while (r <= -PI) r += 2 * PI;
  while (r > PI) r -= 2 * PI;
  vec.push_back(pair<double, int>(l, -1));
  vec.push_back(pair<double, int>(r, 1));
  if (l > r) ++cnt;
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  int first, second, r;
  for (int i = (0); i <= (int)(n - 1); i++) {
    scanf("%d%d%d", &first, &second, &r);
    double dis = sqrt(first * first + second * second + 0.0);
    int tl = max((int)ceil((dis - r) / d), 1), tr = floor((dis + r) / d);
    double th = atan2(second, first);
    for (int j = (tl); j <= (int)(tr); j++) {
      double th2 =
          acos(((double)j * j * d * d + dis * dis - r * r) / j / d / dis / 2);
      add(th - th2, th + th2);
    }
  }
  sort(vec.begin(), vec.end());
  int ans = cnt;
  for (int i = (0); i <= (int)(((int)(vec).size()) - 1); i++)
    chmax(ans, cnt -= (vec[i].second));
  cout << ans << endl;
  return 0;
}
