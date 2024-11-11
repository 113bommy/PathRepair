#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<pair<int, int>, pair<int, int> > > ans;
int cnt = 0;
map<pair<pair<int, int>, pair<int, int> >, int> mp;
int send_query(int x1, int y1, int x2, int y2) {
  if (mp.find(pair<pair<int, int>, pair<int, int> >(
          pair<int, int>(x1, y1), pair<int, int>(x2, y2))) != mp.end()) {
    return mp[pair<pair<int, int>, pair<int, int> >(pair<int, int>(x1, y1),
                                                    pair<int, int>(x2, y2))];
  }
  cnt++;
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  int a;
  scanf("%d", &a);
  mp[pair<pair<int, int>, pair<int, int> >(pair<int, int>(x1, y1),
                                           pair<int, int>(x2, y2))] = a;
  return a;
}
void solve(int x1, int y1, int x2, int y2, int type) {
  int l, r;
  if (!(type >> 0 & 1)) {
    l = x1, r = x2 + 1;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      int re = send_query(mid, y1, x2, y2);
      if (re == 1)
        l = mid;
      else
        r = mid;
    }
    x1 = l;
  }
  if (!(type >> 1 & 1)) {
    l = y1, r = y2 + 1;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      int re = send_query(x1, mid, x2, y2);
      if (re == 1)
        l = mid;
      else
        r = mid;
    }
    y1 = l;
  }
  if (!(type >> 2 & 1)) {
    l = x1 - 1, r = x2;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      int re = send_query(x1, y1, mid, y2);
      if (re == 1)
        r = mid;
      else
        l = mid;
    }
    x2 = r;
  }
  if (!(type >> 3 & 1)) {
    l = y1 - 1, r = y2;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      int re = send_query(x1, y1, x2, mid);
      if (re == 1)
        r = mid;
      else
        l = mid;
    }
    y2 = r;
  }
  ans.push_back(pair<pair<int, int>, pair<int, int> >(pair<int, int>(x1, y1),
                                                      pair<int, int>(x2, y2)));
}
int main(void) {
  scanf("%d", &n);
  int l = 0, r = n;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int re = send_query(1, 1, n, mid);
    if (re == 2)
      r = mid;
    else
      l = mid;
  }
  int y_r = r;
  l = 1;
  r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int re = send_query(1, mid, n, n);
    if (re == 2)
      l = mid;
    else
      r = mid;
  }
  int y_l = l;
  l = 0, r = n;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int re = send_query(1, 1, mid, n);
    if (re == 2)
      r = mid;
    else
      l = mid;
  }
  int x_r = r;
  l = 1;
  r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int re = send_query(mid, 1, n, n);
    if (re == 2)
      l = mid;
    else
      r = mid;
  }
  int x_l = l;
  l = x_l - 1, r = x_r;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int re = send_query(x_l, y_l, mid, y_r);
    if (re == 0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (r < x_r && send_query(x_l, y_l, r, y_r) == 1 &&
      send_query(r + 1, y_l, x_r, y_r) == 1) {
    solve(x_l, y_l, r, y_r, 1);
    solve(r + 1, y_l, x_r, y_r, 4);
    printf("!");
    printf(" %d %d %d %d", ans[0].first.first, ans[0].first.second,
           ans[0].second.first, ans[0].second.second);
    printf(" %d %d %d %d", ans[1].first.first, ans[1].first.second,
           ans[1].second.first, ans[1].second.second);
    printf("\n");
  }
  l = y_l - 1, r = y_r;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    int re = send_query(x_l, y_l, x_r, mid);
    if (re == 0) {
      l = mid;
    } else {
      r = mid;
    }
  }
  solve(x_l, y_l, x_r, r, 2);
  solve(x_l, r + 1, x_r, y_r, 8);
  printf("!");
  printf(" %d %d %d %d", ans[0].first.first, ans[0].first.second,
         ans[0].second.first, ans[0].second.second);
  printf(" %d %d %d %d", ans[1].first.first, ans[1].first.second,
         ans[1].second.first, ans[1].second.second);
  printf("\n");
  return 0;
}
