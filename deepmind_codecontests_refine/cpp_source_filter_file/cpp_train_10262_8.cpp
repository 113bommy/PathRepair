#include <bits/stdc++.h>
using namespace std;
const int N = 2222;
const long long INF = 1e9 + 19;
bool equalll(long double a, long double b) { return abs(a - b) < 1e-9; }
bool lesss(long double a, long double b) { return a < b && !equalll(a, b); }
bool lessE(long double a, long double b) { return a < b || equalll(a, b); }
bool equal3(long double a, long double b) { return abs(a - b) < 1e-3; }
bool less3(long double a, long double b) { return a < b && !equal3(a, b); }
bool lessE3(long double a, long double b) { return a < b || equal3(a, b); }
struct pt {
  long double x, y;
  pt() {}
  pt(long double xx, long double yy) : x(xx), y(yy) {}
  pt operator+(pt A) { return pt(x + A.x, y + A.y); }
  pt operator-(pt A) { return pt(x - A.x, y - A.y); }
  long double operator*(pt A) { return x * A.y - y * A.x; }
  long double operator%(pt A) { return x * A.x + y * A.y; }
  pt operator*(long double k) { return pt(x * k, y * k); }
  pt operator/(long double k) {
    assert(!equalll(k, 0));
    return pt(x / k, y / k);
  }
  bool operator==(pt A) { return equalll(x, A.x) && equalll(y, A.y); }
  bool operator!=(pt A) { return !equalll(x, A.x) && !equalll(y, A.y); }
  long double len() { return sqrt(x * x + y * y); }
  long double len2() { return x * x + y * y; }
  pt norm() { return (*this) / len(); }
  pt rotate() { return pt(-y, x); }
  void read() {
    double xx, yy;
    scanf("%lf%lf", &xx, &yy);
    x = xx;
    y = yy;
  }
  void Epr() { cerr << "x y " << x << " " << y << endl; }
};
struct Line {
  pt O, v;
  Line() {}
  Line(pt A, pt B) : O(A), v((B - A).norm()) {}
  pt operator*(Line l) {
    pt u = l.v.rotate();
    double k = (l.O - O) % u / (v % u);
    return O + v * k;
  }
};
int n, m;
pt red[N];
pt blue[N];
vector<pt> convexHull(vector<pt> p) {
  for (int i = 0; i < (int)p.size(); i++) {
    if (lesss(p[i].y, p[0].y) ||
        (equalll(p[i].y, p[0].y) && lesss(p[i].x, p[0].x)))
      swap(p[i], p[0]);
  }
  pt O = p[0];
  sort(p.begin() + 1, p.end(), [&](pt A, pt B) {
    pt v = A - O;
    pt u = B - O;
    return lesss(0, v * u) || (equalll(v * u, 0) && lesss(v.len(), u.len()));
  });
  vector<pt> st;
  for (auto A : p) {
    for (; st.size() >= 2 &&
           lessE((st[(int)st.size() - 1] - st[(int)st.size() - 2]) *
                     (A - st.back()),
                 0);
         st.pop_back())
      ;
    st.push_back(A);
  }
  return st;
}
bool onLine(pt A, pt B, pt C) { return (equalll((B - A) * (C - A), 0)); }
bool onSeg(pt A, pt B, pt C) {
  return onLine(A, B, C) && (C - A) % (C - B) < 0;
}
int checkInside(vector<pt> &ch, pt A, int &id1, int &id2) {
  if (lesss(0, (A - ch[0]) * (ch[1] - ch[0]))) return 0;
  if (lesss(0, (ch.back() - ch[0]) * (A - ch[0]))) return 0;
  if (onSeg(ch[0], ch[1], A)) {
    id1 = 0;
    id2 = 1;
    return 1;
  }
  if (onSeg(ch.back(), ch[0], A)) {
    id1 = (int)ch.size() - 1;
    id2 = 0;
    return 1;
  }
  int l = 1;
  int r = (int)ch.size() - 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if ((A - ch[0]) * (ch[mid] - ch[0]) > 0)
      r = mid;
    else
      l = mid;
  }
  if (equalll(0, (ch[r] - ch[l]) * (A - ch[l]))) {
    assert(onSeg(ch[l], ch[r], A));
    id1 = l;
    id2 = r;
    return 1;
  }
  if (lesss(0, (ch[r] - ch[l]) * (A - ch[l]))) return 2;
  return 0;
}
long double distToLine(pt A, pt B, pt C) {
  pt v = (B - A).norm();
  return abs((C - A) * v);
}
bool cmpAng(pt dir, pt v, pt u) {
  bool partV = lesss(dir * v, 0) || (equalll(dir * v, 0) && lesss(dir % v, 0));
  bool partU = lesss(dir * u, 0) || (equalll(dir * u, 0) && lesss(dir % u, 0));
  if (partV != partU) return partV < partU;
  return lesss(0, v * u);
}
void read() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    red[i].read();
  }
  for (int i = 0; i < m; i++) {
    blue[i].read();
  }
}
Line serPer(pt A, pt B) {
  pt C = (A + B) / 2;
  pt v = (B - A).rotate();
  return Line(C, C + v);
}
long double answer = INF;
const int T = 1000;
pt shift;
void updAnswer(pt A, pt B, pt C) {
  A = A + shift;
  B = B + shift;
  C = C + shift;
  long double cand = distToLine(A, B, C);
  answer = min(answer, cand);
  return;
  if (equalll(cand, 0)) {
    answer = min(answer, cand);
    return;
  }
  pt va = (A - C);
  pt vb = (B - C);
  va = va * T / va.len2();
  vb = vb * T / vb.len2();
  A = C + va;
  B = C + vb;
  Line ab = serPer(A, B);
  Line ac = serPer(A, C);
  pt O = ab * ac;
  long double R = (O - A).len();
  assert(equalll(R, (O - C).len()));
  assert(equalll(R, (O - B).len()));
  bool flagRed = 0;
  bool flagBlue = 1;
  for (int i = 0; i < m; i++) {
    flagBlue &= lessE3(R, (O - blue[i]).len());
  }
  for (int i = 0; i < n; i++) {
    flagRed |= lessE3((O - red[i]).len(), R);
  }
  assert(flagRed && flagBlue);
  answer = min(answer, cand);
}
double solve() {
  answer = INF;
  if (m <= 2) {
    return -1;
  }
  for (int i = 0; i < m; i++) {
    vector<pt> p;
    pt O = blue[i];
    shift = blue[i];
    for (int j = 0; j < m; j++) {
      if (i == j) {
        p.push_back(pt(0, 0));
        continue;
      }
      pt v = blue[j] - O;
      v = v / v.len2();
      p.push_back(v * T);
    }
    vector<pt> b;
    for (int j = 0; j < n; j++) {
      pt v = red[j] - O;
      b.push_back(v / v.len2() * T);
    }
    O = pt(0, 0);
    auto ch = convexHull(p);
    if ((int)ch.size() <= 2) {
      answer = 0;
      continue;
    }
    int g = 0;
    for (; (1ll << (g + 1)) < (int)ch.size(); g++)
      ;
    vector<int> cof((int)ch.size() + 1);
    for (auto A : b) {
      int id1, id2;
      int res = checkInside(ch, A, id1, id2);
      if (res == 1) {
        updAnswer(ch[id1], ch[id2], O);
      }
      if (res == 0) {
        int lt = 0;
        for (int j = g; j >= 0; j--) {
          int best = lt;
          for (int tt = -1; tt <= 1; tt += 2) {
            int np =
                ((lt + ((1ll << (j)) * tt)) + (int)ch.size()) % (int)ch.size();
            if ((ch[best] - A) * (ch[np] - A) > 0) {
              best = np;
            }
          }
          lt = best;
        }
        int rt = 0;
        for (int j = g; j >= 0; j--) {
          int best = rt;
          for (int tt = -1; tt <= 1; tt += 2) {
            int np =
                ((rt + ((1ll << (j)) * tt)) + (int)ch.size()) % (int)ch.size();
            if ((ch[best] - A) * (ch[np] - A) < 0) {
              best = np;
            }
          }
          rt = best;
        }
        updAnswer(ch[lt], A, O);
        updAnswer(ch[rt], A, O);
        assert(lt != rt);
        if (lt < rt) {
          cof[lt]++;
          cof[rt]--;
        } else {
          cof[lt]++;
          cof[(int)ch.size()]--;
          cof[0]++;
          cof[rt]--;
        }
      }
    }
    int bal = 0;
    for (int j = 0; j < (int)ch.size(); j++) {
      bal += cof[j];
      if (bal > 0) {
        updAnswer(ch[j], ch[(j + 1) % (int)ch.size()], O);
      }
    }
  }
  if (equalll(answer, 0)) {
    return -1;
  } else {
    return T * 1.0 / answer / 2;
  }
}
void genTest() {
  set<pair<int, int>> q;
  int C = 10;
  n = rand() % C + 1;
  m = rand() % C + 1;
  int BB = 10000;
  for (int i = 0; i < n; i++) {
    int x, y;
    for (;;) {
      x = rand() % BB;
      y = rand() % BB;
      if (q.count(make_pair(x, y)) == 0) {
        q.insert(make_pair(x, y));
        break;
      }
    }
    red[i] = pt(x, y);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    for (;;) {
      x = rand() % BB;
      y = rand() % BB;
      if (q.count(make_pair(x, y)) == 0) {
        q.insert(make_pair(x, y));
        break;
      }
    }
    blue[i] = pt(x, y);
  }
}
void printTest() {
  cout << n << " " << m << endl;
  for (int i = 0; i < n; i++) cerr << red[i].x << " " << red[i].y << endl;
  for (int i = 0; i < m; i++) cerr << blue[i].x << " " << blue[i].y << endl;
}
void stress() {
  for (int tt = 0;; tt++) {
    cerr << "tt"
         << " = " << tt << endl;
    genTest();
    printTest();
    solve();
  }
}
int main() {
  if (1) {
    read();
    printf("%.17f\n", solve());
  } else {
    stress();
  }
  return 0;
}
