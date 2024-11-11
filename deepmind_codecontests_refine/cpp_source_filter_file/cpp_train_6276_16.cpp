#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<pair<int, int> > v_p;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x2 < x1) swap(x1, x2);
  if (y2 < y1) swap(y1, y2);
  for (int i = y1; i <= y2; i++) {
    v_p.push_back(make_pair(x1, i));
    v_p.push_back(make_pair(x2, i));
  }
  for (int i = x1 + 1; i < x2; i++) {
    v_p.push_back(make_pair(i, x1));
    v_p.push_back(make_pair(i, x2));
  }
  int n, x, y, r;
  cin >> n;
  vector<tuple<int, int, int> > v;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> r;
    v.push_back(make_tuple(x, y, r));
  }
  int cnt = 0;
  for (int i = 0; i < v_p.size(); i++) {
    bool flag = 1;
    for (int j = 0; j < n; j++) {
      int x2 = get<0>(v[j]);
      int y2 = get<1>(v[j]);
      int r = get<2>(v[j]);
      if (r * r >= ((v_p[i].first - x2) * (v_p[i].first - x2)) +
                       ((v_p[i].second - y2) * (v_p[i].second - y2))) {
        flag = 0;
        break;
      }
    }
    if (flag) cnt++;
  }
  cout << cnt;
  return 0;
}
