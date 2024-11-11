#include <bits/stdc++.h>
using namespace std;
typedef struct circ {
  int readx, ready, readrad;
  double x, y;
  double radius;
};
double PI = (4.0 * atan(1.0));
circ circle[100001];
bool useless[100001];
double R;
double ans;
int N;
priority_queue<pair<double, bool>, vector<pair<double, bool> >,
               greater<pair<double, bool> > >
    pq;
int noactive;
double prevang;
double dist(pair<double, double> a, pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
double fix(double q) {
  if (q < 0) {
    while (q < 0) {
      q += 2 * PI;
    }
  } else if (q >= 2 * PI) {
    while (q >= 2 * PI) {
      q -= 2 * PI;
    }
  }
  return q;
}
int main() {
  ios_base::sync_with_stdio(false);
  if (fopen("cf681e.in", "r")) {
    freopen("cf681e.in", "r", stdin);
    freopen("cf681e.out", "w", stdout);
  }
  pair<double, double> origin;
  double temp1, temp2;
  cin >> origin.first >> origin.second >> temp1 >> temp2;
  R = temp1 * temp2;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> circle[i].readx >> circle[i].ready >> circle[i].readrad;
    circle[i].readx -= origin.first;
    circle[i].ready -= origin.second;
    circle[i].x = 1.0 * circle[i].readx;
    circle[i].y = 1.0 * circle[i].ready;
    circle[i].radius = 1.0 * circle[i].readrad;
  }
  origin = make_pair(0.0, 0.0);
  for (int i = 0; i < N; i++) {
    double distto = dist(origin, make_pair(circle[i].x, circle[i].y));
    if (distto <= circle[i].radius) {
      cout << "1\n";
      return 0;
    } else if (distto >= circle[i].radius + R || circle[i].radius == 0.0) {
      useless[i] = true;
    }
  }
  if (R == 0.0) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (useless[i]) {
      continue;
    }
    double ang = atan2(circle[i].y, circle[i].x);
    double d, r;
    d = dist(origin, make_pair(circle[i].x, circle[i].y));
    r = circle[i].radius;
    double possrng = asin(r / d), rng;
    if (r + d < R) {
      rng = possrng;
    } else {
      rng = acos((((R * R + d * d - r * r) / 2.0) / R) / d);
      if (possrng > rng) {
        double pdist = cos(possrng) * d;
        if (pdist <= R) {
          rng = possrng;
        }
      }
    }
    pair<double, double> angles;
    angles = make_pair(ang - rng, ang + rng);
    angles.first = fix(angles.first);
    angles.second = fix(angles.second);
    if (angles.first < angles.second) {
      pq.push(make_pair(angles.first, 0));
      pq.push(make_pair(angles.second, 1));
    } else {
      pq.push(make_pair(angles.first, 0));
      pq.push(make_pair(2.0 * PI, 1));
      pq.push(make_pair(0.0, 0));
      pq.push(make_pair(angles.second, 1));
    }
  }
  while (!pq.empty()) {
    pair<double, bool> plb = pq.top();
    pq.pop();
    if (plb.second) {
      noactive--;
      if (noactive == 0) {
        ans += (plb.first - prevang);
      }
    } else {
      if (noactive == 0) {
        prevang = plb.first;
      }
      noactive++;
    }
  }
  cout << fixed << setprecision(14) << ans / (2 * PI) << '\n';
  return 0;
}
