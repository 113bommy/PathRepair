#include <bits/stdc++.h>
using namespace std;
struct POINT {
  double x;
  double y;
  POINT(double a = 0, double b = 0) {
    x = a;
    y = b;
  }
};
bool operator<(const POINT& a, const POINT& b) {
  if (a.x != b.x) {
    return a.x < b.x;
  } else {
    return a.y < b.y;
  }
}
bool equal_point(const POINT& p1, const POINT& p2) {
  return ((fabs(p1.x - p2.x) < 1e-10) && (fabs(p1.y - p2.y) < 1e-10));
}
bool operator==(const POINT& a, const POINT& b) {
  return a.x == b.x && a.y == b.y;
}
struct LINESEG {
  POINT s;
  POINT e;
  LINESEG(POINT a, POINT b) {
    s = a;
    e = b;
  }
  LINESEG() {}
  void Swap() { swap(s, e); }
};
double dist(POINT p1, POINT p2) {
  return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}
double multiply(POINT sp, POINT ep, POINT op) {
  return ((sp.x - op.x) * (ep.y - op.y) - (ep.x - op.x) * (sp.y - op.y));
}
double dotmultiply(POINT p1, POINT p2, POINT p0) {
  return ((p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y));
}
bool online(const LINESEG& l, const POINT& p) {
  return ((multiply(l.e, p, l.s) == 0) &&
          (((p.x - l.s.x) * (p.x - l.e.x) <= 0) &&
           ((p.y - l.s.y) * (p.y - l.e.y) <= 0)));
}
POINT p[6];
LINESEG line[3];
void Solve() {
  for (int i = 0; i < 3; ++i) {
    line[i].s = p[i * 2];
    line[i].e = p[i * 2 + 1];
  }
  bool flag = false;
  int seq[10];
  memset(seq, 0, sizeof(seq));
  for (int i = 0; i < 1 << 3; ++i) {
    int cnt = 0;
    int mark = i;
    for (int j = 0; j < 3; ++j) {
      if (mark & (1 << j)) {
        seq[cnt++] = j;
      }
    }
    if (cnt != 2) {
      continue;
    }
    if (line[seq[0]].s == line[seq[1]].s) {
      line[seq[0]].Swap();
      flag = true;
    } else if (line[seq[0]].s == line[seq[1]].e) {
      swap(seq[0], seq[1]);
      flag = true;
    } else if (line[seq[0]].e == line[seq[1]].s) {
      flag = true;
    } else if (line[seq[0]].e == line[seq[1]].e) {
      line[seq[0]].Swap();
      swap(seq[0], seq[1]);
      flag = true;
    }
    if (flag) {
      break;
    }
  }
  if (flag == false) {
    cout << "NO" << endl;
    return;
  }
  LINESEG fi, se, th;
  fi = line[seq[0]];
  se = line[seq[1]];
  th = line[3 - seq[0] - seq[1]];
  if (fi.s == fi.e || se.s == se.e || th.s == th.e) {
    cout << "NO" << endl;
    return;
  }
  double ang = dotmultiply(fi.s, se.s, fi.e);
  if (ang > 0) {
    cout << "NO" << endl;
    return;
  }
  if (online(fi, th.s) == false) {
    th.Swap();
  }
  if (online(fi, th.s) == false || online(se, th.e) == false) {
    cout << "NO" << endl;
    return;
  }
  double d[10];
  d[0] = dist(fi.s, th.s);
  d[1] = dist(fi.e, th.s);
  d[2] = dist(se.s, th.e);
  d[3] = dist(se.e, th.e);
  for (int i = 0; i < 2; ++i) {
    if (d[i * 2 + 1] < d[i * 2]) {
      swap(d[i * 2], d[i * 2 + 1]);
    }
    if (d[i * 2] / d[i * 2 + 1] < 0.25) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}
int main() {
  int ncase;
  while (cin >> ncase) {
    for (int i = 0; i < ncase; ++i) {
      for (int j = 0; j < 3 * 2; ++j) {
        cin >> p[j].x >> p[j].y;
      }
      Solve();
    }
  }
  return 0;
}
