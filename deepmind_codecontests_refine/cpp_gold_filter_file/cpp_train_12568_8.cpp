#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, cc;
  cin >> c >> cc;
  vector<int> res(2 * c), car(2 * c);
  using point = tuple<int, int>;
  vector<point> park_point(2 * c), car_point(2 * c);
  for (int i = 0; i < 2 * c; ++i) {
    park_point[i] = {(i < c) ? 1 : 4, (i < c) ? (i + 1) : (2 * c - i)};
    car_point[i] = {(i < c) ? 2 : 3, (i < c) ? (i + 1) : (2 * c - i)};
  };
  for (int i = 0; i < c; ++i) cin >> res[i];
  for (int i = 0; i < c; ++i) cin >> car[i];
  for (int i = 0; i < c; ++i) cin >> car[2 * c - i - 1];
  for (int i = 0; i < c; ++i) cin >> res[2 * c - i - 1];
  int l = 2 * c;
  using ap = tuple<int, int, int>;
  vector<ap> ans;
  ans.reserve(15000);
  auto park = [&] {
    for (int i = 0; i < l; ++i) {
      if (res[i] && res[i] == car[i]) {
        car[i] = 0;
        --cc;
        ans.push_back(
            {res[i], (i < c) ? 1 : 4, (i < c) ? (i + 1) : (2 * c - i)});
      }
    }
  };
  park();
  if (cc == l) {
    cout << -1;
    return 0;
  }
  int es = [&] {
    for (int i = 0; i < l; ++i)
      if (car[i] == 0) return i;
  }();
  auto round = [&] {
    for (int i = 0; i < l - 1; ++i) {
      int cid = (es + i) % l;
      int nid = (es + i + 1) % l;
      car[cid] = car[nid];
      if (car[cid]) {
        auto [x, y] = car_point[cid];
        ans.push_back({car[cid], x, y});
      }
    }
    --es;
    if (es < 0) es = l - 1;
    car[es] = 0;
  };
  while (cc) {
    round();
    park();
  }
  cout << ans.size() << '\n';
  for (auto &a : ans) {
    auto [c, x, y] = a;
    cout << c << ' ' << x << ' ' << y << '\n';
  }
  return 0;
}
