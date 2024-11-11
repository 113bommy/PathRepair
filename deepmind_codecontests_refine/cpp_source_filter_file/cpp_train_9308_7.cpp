#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> red[2005], blue[2005];
pair<int, int> rred[2005][2], rblue[2005][2];
int vis[2005][2005];
vector<pair<pair<int, int>, pair<int, int> > > re, bl;
int check1(pair<pair<int, int>, pair<int, int> > x,
           pair<pair<int, int>, pair<int, int> > y) {
  if (y.first.second >= x.first.second && y.first.second <= x.second.second &&
      x.first.first >= y.first.first && x.first.first <= y.second.first)
    return 1;
  return 0;
}
bool check(int t) {
  int pre = 0;
  re.clear();
  bl.clear();
  for (int i = 0; i < n; i++) {
    rblue[i][0] = make_pair(blue[i].first, blue[i].second - 2 * t);
    rblue[i][1] = make_pair(blue[i].first, blue[i].second + 2 * t);
    if (i == 0) continue;
    if (blue[i].first == blue[pre].first && rblue[i][0] <= rblue[pre][1]) {
      rblue[pre][1] = rblue[i][1];
    } else {
      bl.push_back(make_pair(rblue[pre][0], rblue[pre][1]));
      pre = i;
    }
  }
  bl.push_back(make_pair(rblue[pre][0], rblue[pre][1]));
  pre = 0;
  for (int i = 0; i < m; i++) {
    rred[i][0] = make_pair(red[i].first - 2 * t, red[i].second);
    rred[i][1] = make_pair(red[i].first + 2 * t, red[i].second);
    if (i == 0) continue;
    if (red[i].second == red[pre].second && rred[i][0] <= rred[i][1]) {
      rred[pre][1] = rred[i][1];
    } else {
      re.push_back(make_pair(rred[pre][0], rred[pre][1]));
      pre = i;
    }
  }
  re.push_back(make_pair(rred[pre][0], rred[pre][1]));
  memset(vis, 0, sizeof(vis));
  int lenr = re.size();
  int lenb = bl.size();
  for (int i = 0; i < lenb; i++) {
    for (int j = 0; j < lenr; j++) {
      if (check1(bl[i], re[j])) {
        for (int k = j + 1; k < lenr; k++) {
          if (check1(bl[i], re[k])) {
            if (vis[j][k]) return true;
            vis[j][k]++;
          }
        }
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    blue[i] = make_pair(x + y, x - y);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    red[i] = make_pair(x + y, x - y);
  }
  sort(blue, blue + n);
  for (int i = 0; i < m; i++) swap(red[i].first, red[i].second);
  sort(red, red + m);
  for (int i = 0; i < m; i++) swap(red[i].first, red[i].second);
  if (blue[0].first == blue[n - 1].first ||
      red[0].second == red[m - 1].second) {
    puts("Poor Sereja!");
    return 0;
  }
  int L = 0, R = 0x7fffffff, ans = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid)) {
      R = mid - 1;
      ans = mid;
    } else
      L = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
