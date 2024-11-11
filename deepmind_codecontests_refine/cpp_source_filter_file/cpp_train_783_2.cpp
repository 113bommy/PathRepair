#include <bits/stdc++.h>
using namespace std;
const int Maxn = 11111;
const double Eps = 1e-9;
int n, w, bus, person, posl, posu, posr, posd;
pair<int, int> coor[Maxn];
int main() {
  scanf("%d%d%d%d", &n, &w, &bus, &person);
  pair<int, int> left, right, up, down;
  left = down = make_pair(INT_MAX, INT_MAX);
  up = right = make_pair(0, 0);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &coor[i].first, &coor[i].second);
    if (coor[i].first >= 0 && coor[i].second >= 0 && coor[i].second <= w) {
      if (coor[i] < left) {
        left = coor[i];
        posl = i;
      }
      if ((coor[i].second > up.second) ||
          (coor[i].second == up.second && coor[i].first > up.first)) {
        up = coor[i];
        posu = i;
      }
      if ((coor[i].second < down.second) ||
          (coor[i].second == down.second && coor[i].first < down.first)) {
        down = coor[i];
        posd = i;
      }
      if ((coor[i].first > right.first) ||
          (coor[i].first == right.first && coor[i].second < right.second)) {
        right = coor[i];
        posr = i;
      }
    }
  }
  bool reach = true;
  if (posu && posl) {
    if (posu < posl) {
      for (int i = posu; i <= posl; ++i) {
        if (coor[i].second - coor[i].first / double(bus) * person > Eps) {
          reach = false;
          break;
        }
      }
    } else {
      for (int i = 1; i <= posl; ++i) {
        if (coor[i].second - coor[i].first / double(bus) * person > Eps) {
          reach = false;
          break;
        }
      }
      for (int i = posu; i <= n; ++i) {
        if (coor[i].second - coor[i].first / double(bus) * person > Eps) {
          reach = false;
          break;
        }
      }
    }
  }
  double ans = 0;
  if (reach) {
    ans = w / double(person);
  } else {
    int lasty = 0;
    if (posd < posr) {
      for (int i = posd; i <= posr; ++i) {
        ans += max(max(coor[i].first / double(bus) - ans, double(0)),
                   (coor[i].second - lasty) / double(person));
        lasty = coor[i].second;
      }
    } else {
      for (int i = posd; i <= n; ++i) {
        ans += max(max(coor[i].first / double(bus) - ans, double(0)),
                   (coor[i].second - lasty) / double(person));
        lasty = coor[i].second;
      }
      for (int i = 1; i <= posr; ++i) {
        ans += max(max(coor[i].first / double(bus) - ans, double(0)),
                   (coor[i].second - lasty) / double(person));
        lasty = coor[i].second;
      }
    }
    ans += (w - lasty) / double(person);
  }
  printf("%.10lf\n", ans);
  return 0;
}
