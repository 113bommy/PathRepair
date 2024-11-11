#include <bits/stdc++.h>
using namespace std;
int dblcmp(double n) { return n < -1e-10 ? -1 : n > 1e-10; }
struct Point {
  double x, y;
  void scan() { scanf("%lf %lf", &x, &y); }
};
double getDist(Point a, Point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}
double getCross(Point o, Point a, Point b) {
  double x1 = a.x - o.x;
  double y1 = a.y - o.y;
  double x2 = b.x - o.x;
  double y2 = b.y - o.y;
  return x1 * y2 - x2 * y1;
}
double getDot(Point o, Point a, Point b) {
  double x1 = a.x - o.x;
  double y1 = a.y - o.y;
  double x2 = b.x - o.x;
  double y2 = b.y - o.y;
  return x1 * x2 + y1 * y2;
}
double POINTvSEG(Point p, Point a, Point b) {
  double dist = fabs(0.5 * getCross(p, a, b)) / getDist(a, b);
  double dot1 = getDot(a, b, p);
  double dot2 = getDot(b, a, p);
  if (dblcmp(dot1) > 0 && dblcmp(dot2) > 0) {
    return dist;
  } else {
    return min(getDist(p, a), getDist(p, b));
  }
}
double SEGvSEG(Point a, Point b, Point c, Point d) {
  double d1 = POINTvSEG(a, c, d);
  double d2 = POINTvSEG(b, c, d);
  double d3 = POINTvSEG(c, a, b);
  double d4 = POINTvSEG(d, a, b);
  return min(min(d1, d2), min(d3, d4));
}
double a, b;
Point p[1010], q[1010];
double dd[1010][1010];
double dist[1010];
bool vis[1010];
struct Node {
  int index;
  double dist;
  Node(int i, double d) {
    index = i;
    dist = d;
  }
  bool operator<(Node o) const { return dist > o.dist; }
};
double dijkstra(int s, int t, int n) {
  for (int i = 0; i < n; i++) {
    dist[i] = 1e30;
    vis[i] = false;
  }
  dist[s] = 0;
  priority_queue<Node> que;
  que.push(Node(s, 0.0));
  while (que.empty() == false) {
    Node p = que.top();
    que.pop();
    if (vis[p.index] == false && dist[p.index] == p.dist) {
      vis[p.index] = true;
      for (int i = 0; i < n; i++) {
        if (dist[i] > dist[p.index] + dd[p.index][i]) {
          dist[i] = dist[p.index] + dd[p.index][i];
          que.push(Node(i, dist[i]));
        }
      }
    }
  }
  return dist[t];
}
double gao(int n) {
  for (int i = 0; i < 1010; i++) {
    for (int j = 0; j < 1010; j++) {
      dd[i][j] = 1e30;
    }
    dd[i][i] = 0.0;
  }
  double t = getDist(p[0], p[1]);
  if (dblcmp(t - a) <= 0) {
    dd[0][1] = dd[1][0] = t;
  }
  for (int j = 2; j < n; j++) {
    t = POINTvSEG(p[0], p[j], q[j]);
    if (dblcmp(t - a) <= 0) {
      dd[0][j] = dd[j][0] = a + b;
    }
  }
  for (int j = 2; j < n; j++) {
    t = POINTvSEG(p[1], p[j], q[j]);
    if (dblcmp(t - a) <= 0) {
      dd[1][j] = dd[j][1] = t;
    }
  }
  for (int i = 2; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      t = SEGvSEG(p[i], q[i], p[j], q[j]);
      if (dblcmp(t - a) <= 0) {
        dd[i][j] = dd[j][i] = a + b;
      }
    }
  }
  return dijkstra(0, 1, n);
}
int main() {
  while (scanf("%lf %lf", &a, &b) != EOF) {
    p[0].scan();
    p[1].scan();
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n + 2; i++) {
      p[i].scan();
      q[i].scan();
    }
    double ans = gao(n + 2);
    if (ans == 1e30) {
      puts("-1");
    } else {
      printf("%.8f\n", ans);
    }
  }
  return 0;
}
