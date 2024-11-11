#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

using D = double;
const D PI = acos(D(-1)), EPS = 1e-10;

int sgn(D a) { return (abs(a) <= EPS) ? 0 : (a < 0 ? -1 : 1); }
int sgn(D a, D b) { return sgn(a-b); }
//relative sign
// int rsgn(D a, D f) {
//     if (abs(a) <= f*EPS) return 0;
//     return (a < 0) ? -1 : 1;
// }
struct Pt2 {
    D x, y;
    Pt2() {}
    Pt2(D _x, D _y) : x(_x), y(_y) {}
    Pt2 operator+(const Pt2 &r) const { return Pt2(x+r.x, y+r.y); }
    Pt2 operator-(const Pt2 &r) const { return Pt2(x-r.x, y-r.y); }
    Pt2 operator*(const Pt2 &r) const { return Pt2(x*r.x-y*r.y, x*r.y+y*r.x); }

    Pt2 operator*(const D &r) const { return Pt2(x*r, y*r); }
    Pt2 operator/(const D &r) const { return Pt2(x/r, y/r); }

    Pt2& operator+=(const Pt2 &r) { return *this=*this+r; }
    Pt2& operator-=(const Pt2 &r) { return *this=*this-r; }
    Pt2& operator*=(const Pt2 &r) { return *this=*this*r; }
    Pt2& operator*=(const D &r) { return *this=*this*r; }
    Pt2& operator/=(const D &r) { return *this=*this/r; }
    
    Pt2 operator-() const { return Pt2(-x, -y); }

    bool operator<(const Pt2 &r) const { return 2*sgn(x, r.x)+sgn(y, r.y)<0; }
    bool operator==(const Pt2 &r) const { return sgn((*this-r).rabs()) == 0; }

    D abs() const { return sqrt(x*x + y*y); }
    D rabs() const { return max(std::abs(x), std::abs(y)); } // robust abs
    D arg() const { return atan2(y, x); }

    pair<D, D> to_pair() const { return make_pair(x, y); }
    static Pt2 polar(D le, D th) { return Pt2(le*cos(th), le*sin(th)); }
};
ostream& operator<<(ostream& os, const Pt2 &p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}
using P = Pt2;

struct L {
    P s, t;
    L() {}
    L(P _s, P _t) : s(_s), t(_t) {}
    P vec() const { return t-s; }
    D abs() const { return vec().abs(); }
    D arg() const { return vec().arg(); }
};

D cross(P a, P b) { return a.x*b.y - a.y*b.x; }
D dot(P a, P b) { return a.x*b.x + a.y*b.y; }
// cross(a, b) is too small?
int sgncrs(P a, P b) {
    D cr = cross(a, b);
    if (abs(cr) <= (a.rabs() + b.rabs()) * EPS) return 0;
    return (cr < 0) ? -1 : 1;
}

// -2, -1, 0, 1, 2 : front, clock, on, cclock, back
int ccw(P b, P c) {
    int s = sgncrs(b, c);
    if (s) return s;
    if (c == P(0, 0) || c == b) return 0;
    if (dot(b, c) < 0) return 2;
    if (dot(-b, c-b) < 0) return -2;
    return 0;
}
int ccw(P a, P b, P c) { return ccw(b-a, c-a); }
int ccw(L l, P p) { return ccw(l.s, l.t, p); }

int crossLL(const L &l, const L &m, P &r) {
    D cr1 = cross(l.vec(), m.vec()), cr2 = cross(l.vec(), l.t - m.s);
    if (sgncrs(l.vec(), m.vec()) == 0) {
        r = l.s;
        if (sgncrs(l.vec(), l.t - m.s)) return 0;
        return -1;
    }
    r = m.s + m.vec() * (cr2 / cr1);
    return 1;
}

int crossSS(L l, L m, P &r) {
    int u = crossLL(l, m, r);
    if (u == 0) return 0;
    if (u == -1) {
        r = max(min(l.s, l.t), min(m.s, m.t));
        P q = min(max(l.s, l.t), max(m.s, m.t));
        return (r == q) ? 1 : (q < r ? 0 : -1);
    }
    if (ccw(l, r) == 0 && ccw(m, r) == 0) return 1;
    return 0;
}






struct C {
    P p; D r;
    C() {}
    C(P p, D r) : p(p), r(r) {}
};


// pからcに接線を引く，交点はp1, p2
int tangent(const C &c, const P &p, P &p1, P &p2) {
    D di = (c.p - p).abs();
    int si = sgn(c.r, di);
    if (si == 1) return 0;
    D th = acos(min(D(1), c.r / di));
    D ar = (p - c.p).arg();
    p1 = c.p + P::polar(c.r, ar-th);
    p2 = c.p + P::polar(c.r, ar+th);
    if (si == 0) return 1;
    return 2;
}

//共通接線
int tangent(const C &c, const C &d, L &l, L &r, bool inter) {
    D di = (d.p - c.p).abs(), ar = (d.p - c.p).arg();
    if (sgn(di) == 0) {
        assert(sgn(c.r - d.r)); // prohibit same circles
        return 0;
    }
    D costh = (c.r + (inter ? d.r : -d.r)) / di;
    int si = sgn(abs(costh), 1);
    if (si == 1) return 0;
    D th = acos(min(D(1), max(D(-1), costh)));

    P base;
    base = P::polar(1, ar-th);
    l = L(c.p + base * c.r, d.p + base * d.r * (inter ? -1 : 1));
    base = P::polar(1, ar+th);
    r = L(c.p + base * c.r, d.p + base * d.r * (inter ? -1 : 1));
    if (si == 0) return 1;
    return 2;
}

P project(const L &l, const P &p) {
    P v = l.vec();
    return l.s + v * (dot(v, p-l.s) / (v.x*v.x + v.y*v.y));
}

D distLP(const L &l, const P &p) {
    return abs(cross(l.vec(), p-l.s)) / l.abs();
}

//need Intersect/distLP
int crossCL(const C &c, const L &l, L &r) {
    D u = distLP(l, c.p);
    int si = sgn(u, c.r);    
    if (si == 1) return 0;
    P v = project(l, c.p);
    P di = (si == 0) ? P(0, 0) : l.vec() * (sqrt(c.r*c.r - u*u) / l.abs());
    r = L(v+di, v-di);
    if (si == 0) return 1;
    return 2;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
 
    C c1, c2;
    D x, y, r;
    cin >> x >> y >> r; c1 = C(P(x, y), r);
    cin >> x >> y >> r; c2 = C(P(x, y), r);
 
    L l1, l2;
    int z;
    V<P> res;
    for (int f = 0; f <= 1; f++) {
        z = tangent(c2, c1, l1, l2, f);
        if (z >= 1) res.push_back(l1.t);
        if (z >= 2) res.push_back(l2.t);
    }
 
    sort(begin(res), end(res));
    for (auto p: res) {
        cout << p.x << " " << p.y << endl;
    }
    return 0;
}

