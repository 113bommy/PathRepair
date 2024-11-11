#include <bits/stdc++.h>
using namespace std;
int n;
double eps = 0.000001;
struct point {
  double x, y;
  point(double _x = 0, double _y = 0) {
    x = _x;
    y = _y;
  }
  double len() { return (x * x + y * y); }
  point operator-(point b) { return point(x - b.x, y - b.y); }
  double operator*(point b) { return x * b.x + y * b.y; }
  double operator%(point b) { return x * b.y - y * b.x; }
  double ang() {
    return atan2(point(x, y) % point(1, 0), point(x, y) * point(1, 0));
  }
};
point a[2000];
vector<pair<double, double> > v;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = point(x, y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j].x > a[i].x || (a[j].x == a[i].x && a[j].y > a[i].y))
        v.push_back(make_pair((a[j] - a[i]).len(), (a[j] - a[i]).ang()));
      else
        v.push_back(make_pair((a[i] - a[j]).len(), (a[i] - a[j]).ang()));
    }
  }
  sort(v.begin(), v.end());
  int cur = 0;
  long long ans = 0;
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first > v[cur].first || v[i].second > v[cur].second) {
      ans += (long long)(i - cur) * (long long)(i - cur - 1) / 2;
      cur = i;
    }
  }
  ans += (long long)(v.size() - cur) * (long long)(v.size() - cur - 1) / 2;
  cout << ans / 2 << "\n";
  return 0;
}
