#include <bits/stdc++.h>
using namespace std;
struct Point {
  long double x, y;
  Point(){};
  Point(long double a, long double b) {
    x = a;
    y = b;
  }
  void input() { cin >> x >> y; }
};
long double ra(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
long double ra_po(Point a, Point b, Point c) {
  if (b.x == c.x) {
    if (b.y > c.y) swap(b, c);
    if (b.y <= a.y && c.y >= a.y) {
      return abs(b.x - a.x);
    } else
      return min(ra(a, b), ra(a, c));
  } else {
    if (b.x > c.x) swap(b, c);
    if (b.x <= a.x && c.x >= a.x) {
      return abs(b.y - a.y);
    } else
      return min(ra(a, b), ra(a, c));
  }
}
long double ra_li(Point a, Point b, Point c, Point d) {
  if (a.x == b.x) {
    if (c.x == d.x) {
      if (a.y > b.y) swap(a, b);
      if (c.y > d.y) swap(c, d);
      if (min(b.y, d.y) >= max(a.y, c.y)) {
        return abs(a.x - c.x);
      } else
        return min(min(ra(a, c), ra(a, d)), min(ra(b, c), ra(b, d)));
    } else {
      swap(a, c);
      swap(b, d);
    }
  }
  if (a.y == b.y) {
    if (c.y == d.y) {
      if (a.x > b.x) swap(a, b);
      if (c.x > d.x) swap(c, d);
      if (min(b.x, d.x) >= max(a.x, c.x)) {
        return abs(a.y - c.y);
      } else
        return min(min(ra(a, c), ra(a, d)), min(ra(b, c), ra(b, d)));
    } else {
      if (c.y > d.y) swap(c, d);
      if (a.x > b.x) swap(a, b);
      if (a.y >= c.y && a.y <= d.y) {
        return min(abs(c.x - a.x), abs(c.x - b.x));
      }
      if (a.x <= c.x && c.x <= b.x) {
        return min(abs(c.y - a.y), abs(d.y - a.y));
      }
      return min(min(ra(a, c), ra(a, d)), min(ra(b, c), ra(b, d)));
    }
  }
}
void bfs(long long now, vector<long long> *vec, long long *ves) {
  long long i;
  for (i = 0; i < vec[now].size(); ++i) {
    if (ves[vec[now][i]] > ves[now] + 1) {
      ves[vec[now][i]] = ves[now] + 1;
      bfs(vec[now][i], vec, ves);
    }
  }
}
void solve() {
  long long a, b, n, i, j;
  long double mini = (long double)(1e18);
  cin >> a >> b;
  Point start, finish, x, y;
  start.input();
  finish.input();
  cin >> n;
  vector<pair<Point, Point> > mas;
  vector<long long> vec[n + 1];
  long long ves[n + 1];
  for (i = 0; i <= n; ++i) ves[i] = (long long)(1e18);
  ves[0] = 0;
  for (i = 0; i < n; ++i) {
    x.input();
    y.input();
    mas.push_back({x, y});
  }
  if (ra(start, finish) <= (long double)a) {
    cout << ra(start, finish) << endl;
    return;
  }
  for (i = 0; i < n; ++i) {
    if (ra_po(start, mas[i].first, mas[i].second) <= (long double)a)
      vec[0].push_back(i + 1);
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if ((i != j) && (ra_li(mas[i].first, mas[i].second, mas[j].first,
                             mas[j].second) <= (long double)a))
        vec[i + 1].push_back(j + 1);
    }
  }
  bfs(0, vec, ves);
  for (i = 1; i <= n; ++i) {
    if ((ves[i] != (long long)(1e18)) &&
        (ra_po(finish, mas[i - 1].first, mas[i - 1].second) <=
         (long double)a)) {
      mini = min(mini, (long double)ves[i] * (long double)(a + b) +
                           ra_po(finish, mas[i - 1].first, mas[i - 1].second));
    }
  }
  if (mini == (long double)(1e18))
    cout << -1 << endl;
  else
    cout << fixed << setprecision(10) << mini << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
