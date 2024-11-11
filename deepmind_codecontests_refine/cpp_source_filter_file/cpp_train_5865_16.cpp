#include <bits/stdc++.h>
using namespace std;
double x[100005];
double v1, v2;
double l;
double s;
int n;
vector<pair<double, int> > pos;
int main() {
  cin >> n >> l >> v1 >> v2;
  s = (l / (v1 + v2)) * v2;
  for (int i = (1); i <= (n); i++) {
    double x;
    cin >> x;
    pos.push_back(make_pair(x, 1));
    pos.push_back(make_pair(x + 2 * l, 1));
    if (x - s >= 0) pos.push_back(make_pair(x - s, 0));
    if (x + 2 * l - s >= 0) pos.push_back(make_pair(x - s + 2 * l, 0));
  }
  pos.push_back(make_pair(0, 0));
  pos.push_back(make_pair(2 * l, 0));
  sort((pos).begin(), (pos).end());
  int j = 0;
  int sum = 0;
  for (int i = (0); i <= (((int)pos.size()) - 2); i++) {
    double x1 = pos[i].first;
    if (x1 >= 2 * l) break;
    double x2 = pos[i + 1].first;
    x2 = min(x2, 2 * l);
    if (x2 < x1) break;
    while (j < ((int)pos.size())) {
      if (pos[j].first - 0.00000001 <= x1 + s) {
        sum += pos[j].second;
        ++j;
      } else
        break;
    }
    sum -= pos[i].second;
    x[sum] += x2 - x1;
  }
  for (int i = (0); i <= (n); i++) {
    printf("%.13lf\n", x[i] / (2 * l));
  }
  return 0;
}
