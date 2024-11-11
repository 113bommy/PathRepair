////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <regex>
using namespace std;

//// MACRO ////
#define countof(a) (sizeof(a)/sizeof(a[0]))

#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define RFOR(i,s,n) for (int i = (n)-1; i >= (s); i--)
#define pos(c,i) c.being() + (i)
#define allof(c) c.begin(), c.end()
#define aallof(a) a, countof(a)
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)
#define apartof(a,i,n) a + (i), a + (i) + (n)
#define long long long

#define EPS 1e-9
#define INF (1L << 30)
#define LINF (1LL << 60)

#define PREDICATE(t,a,exp) [&](const t & a) -> bool { return exp; }
#define COMPARISON_T(t) bool(*)(const t &, const t &)
#define COMPARISON(t,a,b,exp) [&](const t & a, const t & b) -> bool { return exp; }
#define CONVERTER(TSrc,t,TDest,exp) [&](const TSrc &t)->TDest { return exp; }

inline int sign(double x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }
inline bool inRange(double val, double min, double max) { return val - min > -EPS && val - max < EPS; }

//// i/o helper ////

struct _Reader { template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
struct _Writer { bool f; _Writer() : f(false) { } template <class T> _Writer operator ,(const T &rhs) { cout << (f ? " " : "") << rhs; f = true; return *this; } };
#define READ(t,...) t __VA_ARGS__; _Reader(), __VA_ARGS__
#define WRITE(...) _Writer(), __VA_ARGS__; cout << endl

template <class T> struct vevector : public vector<vector<T>> { vevector(int n = 0, int m = 0, const T &initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };
template <class T> struct vevevector : public vector<vevector<T>> { vevevector(int n = 0, int m = 0, int l = 0, const T &initial = T()) : vector<vevector<T>>(n, vevector<T>(m, l, initial)) { } };
template <class T> struct vevevevector : public vector<vevevector<T>> { vevevevector(int n = 0, int m = 0, int l = 0, int k = 0, const T &initial = T()) : vector<vevevector<T>>(n, vevevector<T>(m, l, k, initial)) { } };
template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vevector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T1, class T2> inline istream & operator >> (istream & in, pair<T1, T2> &p) { in >> p.first >> p.second; return in; }
template <class T1, class T2> inline ostream & operator << (ostream &out, pair<T1, T2> &p) { out << p.first << p.second; return out; }
template <class T> inline ostream & operator << (ostream &out, vector<T> &v)
{
	ostringstream ss;
	for (auto x : v) ss << x << ' ';
	auto s = ss.str();
	out << s.substr(0, s.length() - 1) << endl;
	return out;
}

/// 2次元
struct P2
{
	double x, y;
	P2(double x = 0, double y = 0) : x(x), y(y) { }
	P2(complex<double> c) : x(c.real()), y(c.imag()) { }
	P2 operator +() const { return *this; }
	P2 operator +(const P2 &_) const { return P2(x + _.x, y + _.y); }
	P2 operator -() const { return P2(-x, -y); }
	P2 operator -(const P2 &_) const { return *this + -_; }
	P2 operator *(double _) const { return P2(x*_, y*_); }
	P2 operator /(double _) const { return P2(x / _, y / _); }
	double dot(const P2 &_) const { return x*_.x + y*_.y; } // 内積
	double cross(const P2 &_) const { return x*_.y - y*_.x; } // 外積
	double sqlength() const { return x*x + y*y; } // 二乗長さ
	double length() const { return sqrt(sqlength()); } // 長さ
	P2 orthogonal() const { return P2(y, -x); }
	P2 direction() const { return *this / length(); } // 方向ベクトル
	double arg() const { return atan2(y, x); }
	static P2 polar(double length, double theta) { return P2(std::polar(length, theta)); }
};
inline istream & operator>>(istream & in, P2 & p) { in >> p.x >> p.y; return in; }
inline ostream & operator<<(ostream & out, const P2 & p) { out << p.x << ' ' << p.y; return out; }
inline double abs(P2 p2) { return p2.length(); }
inline P2 orthogonal(P2 p) { return p.orthogonal(); }
inline complex<double> orthogonal(complex<double> c) { return  c * complex<double>(0, 1); }

// a,b から ちょうど d だけ離れた点。aとbを円周に持つ円の半径。
inline pair<P2, P2> get_same_distance_points(P2 a, P2 b, double d)
{
	assert(abs(a - b) <= 2 * d + EPS);
	auto v = (a + b) / 2.0 - a; // a から aとbの中点
	auto vl = abs(v);
	auto wl = sqrt(d*d - vl*vl); // 直行Vの大きさ
	auto w = orthogonal(v) * (wl / vl); // 直行V
	return make_pair(a + v + w, a + v - w);
}

// a から b に向かって、cが右手か左手か。
inline int clockwise(P2 a, P2 b, P2 c)
{
	const P2 u = b - a, v = c - a;
	if (u.cross(v) > EPS) { return 1; }
	if (u.cross(v) < -EPS) { return -1; }
	if (u.dot(v) < -EPS) { return -1; }
	if (u.sqlength() < v.sqlength() - EPS) { return 1; }
	return 0;
}

/// 直線
struct Line
{
	P2 p, d;
	explicit Line(P2 pos = P2(), P2 dir = P2()) : p(pos), d(dir) { }
	static Line FromPD(P2 pos, P2 dir) { return Line(pos, dir); }
	static Line From2Point(P2 a, P2 b) { return Line(a, b - a); }
};

/// 線分
struct LineSeg
{
	P2 p, d;
	explicit LineSeg(P2 pos = P2(), P2 dir = P2()) : p(pos), d(dir) { }
	static LineSeg FromPD(P2 pos, P2 dir) { return LineSeg(pos, dir); }
	static LineSeg From2Point(P2 a, P2 b) { return LineSeg(a, b - a); }
	operator Line() { return Line(p, d); }
};

inline P2 projective(P2 a, P2 b) { return b * (a.dot(b) / b.sqlength()); }
inline P2 perpendicular_foot(P2 a, Line b) { Line l = Line(b.p - a, b.d); return a + l.p - projective(l.p, l.d); }
inline LineSeg projective(LineSeg a, Line b) { return LineSeg(perpendicular_foot(a.p, b), projective(a.d, b.d)); }

// 交点
inline P2 crossPoint(Line a, Line b) { return a.p + a.d * (b.d.cross(b.p - a.p) / b.d.cross(a.d)); }

// 包括判定
inline bool contains(LineSeg a, P2 p) { return abs(a.p - p) + abs(a.p + a.d - p) - abs(a.d) < EPS; }

// 交差判定
inline bool isCross(Line a, Line b) { return abs(a.d.cross(b.d)) > EPS; }
inline bool isCross(Line a, LineSeg b) { return sign(a.d.cross(b.p - a.p)) * sign(a.d.cross(b.p + b.d - a.d)) <= 0; }
inline bool isCross(LineSeg a, Line b) { return isCross(b, a); }
inline bool isCross(LineSeg a, LineSeg b)
{
	P2 ae = a.p + a.d, be = b.p + b.d;
	return clockwise(a.p, ae, b.p) * clockwise(a.p, ae, be) <= 0
		&& clockwise(b.p, be, a.p) * clockwise(b.p, be, ae) <= 0;
}

// 重なり判定
inline bool isOverlap(Line a, Line b) { return abs(a.d.cross(b.p - a.p)) < EPS; }
inline bool isOverlap(Line a, LineSeg b) { return isOverlap(a, Line(b.p, b.d)); }
inline bool isOverlap(LineSeg a, Line b) { return isOverlap(b, a); }
inline bool isOverlap(LineSeg a, LineSeg b)
{
	return 0 + contains(a, b.p) + contains(a, b.p + b.d)
		+ contains(b, a.p) + contains(b, a.p + a.d) >= 2;
}

// 距離
inline double getDistance(P2 a, P2 b) { return (a - b).length(); }
inline double getDistance(P2 a, Line b) { return abs(b.d.cross(a - b.p) / b.d.length()); }
inline double getDistance(P2 a, LineSeg b) {
	P2 h = perpendicular_foot(a, (Line)b);
	return contains(b, h) ? getDistance(h, a)
		: min(getDistance(b.p, a), getDistance(b.p + b.d, a));
}
inline double getDistance(Line a, P2 b) { return getDistance(b, a); }
inline double getDistance(Line a, Line b) { return isCross(a, b) ? 0 : getDistance(a, b.p); }
inline double getDistance(Line a, LineSeg b) { return isCross(a, b) ? 0 : min(getDistance(a, b.p), getDistance(a, b.p + b.d)); }
inline double getDistance(LineSeg a, P2 b) { return getDistance(b, a); }
inline double getDistance(LineSeg a, Line b) { return getDistance(b, a); }
inline double getDistance(LineSeg a, LineSeg b)
{
	return isCross(a, b) ? 0 : 
	min(min(getDistance(a, b.p), getDistance(a, b.p + b.d)), 
	min(getDistance(a.p, b), getDistance(a.p + a.d, b))); }

// a から ta, bから tb だけ離れた点。ta=tb=r なら aとbに内接する円
inline pair<pair<P2, P2>, pair<P2, P2>> get_distance_points(Line a, double ta, Line b, double tb)
{
	assert(isCross(a, b));

	P2 va = a.d.orthogonal().direction() * ta;
	P2 vb = b.d.orthogonal().direction() * tb;
	return make_pair(
		make_pair(
			crossPoint(Line(a.p + va, a.d), Line(b.p + vb, b.d)),
			crossPoint(Line(a.p + va, a.d), Line(b.p - vb, b.d))
		), make_pair(
			crossPoint(Line(a.p - va, a.d), Line(b.p + vb, b.d)),
			crossPoint(Line(a.p - va, a.d), Line(b.p - vb, b.d))
		));
}

/// 円
struct Circle
{
	P2 c;
	double r;
	Circle() : c(), r() { }
	Circle(double x, double y, double r) : c(x, y), r(r) { }
	Circle(P2 c, double r) : c(c), r(r) { }
	bool IntersectWith(const Circle &rhs) const { return abs(c - rhs.c) - (r + rhs.r) < EPS; } // 接してても真。
	bool Contains(const P2 &p) const { return abs(p - c) - r < EPS; } // 接してても真。
};
inline istream & operator>>(istream & in, Circle & c) { in >> c.c >> c.r; return in; }

// 交差している2円の交点を求める。角度の小さい方から出る(右下方向が正なら時計回り)
inline pair<P2, P2> crossPoint(Circle A, Circle B)
{
	P2 v = B.c - A.c;
	P2 dir = v.direction(); // 他方の中心への方向
	double d = v.length(); // 他方の中心への距離
	double lh = (A.r*A.r + d*d - B.r*B.r) / (2 * d); // 垂線の足までの距離
	P2 h = A.c + dir * lh; // 垂線の足
	double lp = sqrt(A.r*A.r - lh*lh); // 垂線の足から交点までの距離
	P2 p = dir.orthogonal() * lp; // 垂線の足から交点へのベクトル
	return make_pair(h + p, h - p); // 交点の組。
}

// 2円の接線を求める。
vector<Line> getTangentialLine(Circle a, Circle b)
{
	vector<Line> ret;
	P2 v = b.c - a.c;
	double d = v.length();
	double bt = v.arg();

	if (d - abs(a.r - b.r) > EPS) // 外接線2本
	{
		double dt = acos((a.r - b.r) / d);
		double t1 = bt - dt, t2 = bt + dt;
		ret.push_back(Line::From2Point(a.c + P2::polar(a.r, t1), b.c + P2::polar(b.r, t1)));
		ret.push_back(Line::From2Point(a.c + P2::polar(a.r, t2), b.c + P2::polar(b.r, t2)));
	}
	else if (d - abs(a.r - b.r) > -EPS) // 外接線1本 (内接)
	{
		ret.push_back(Line(a.c + v.direction() * a.r, v.orthogonal()));
	}

	if (d - (a.r + b.r) > EPS) // 内接線2本 (離れている)
	{
		double dt = acos((a.r + b.r) / d);
		double t1 = bt - dt, t2 = bt + dt;
		ret.push_back(Line::From2Point(a.c + P2::polar(a.r, t1), b.c - P2::polar(b.r, t1)));
		ret.push_back(Line::From2Point(a.c + P2::polar(a.r, t2), b.c - P2::polar(b.r, t2)));
	}
	else if (d - (a.r + b.r) > -EPS) // 内接線1本 (接している)
	{
		ret.push_back(Line(a.c + v.direction() * a.r, v.orthogonal()));
	}

	return ret;
}


/// 長方形
struct Rect
{
	P2 l, s;
	Rect() : l(), s() { }
	Rect(double x, double y, double w, double h) : l(x, y), s(w, h) { }
	Rect(P2 location, P2 size) : l(location), s(size) { }
	bool Contains(const P2 &p) const { return p.x - l.x > -EPS && p.y - l.y > -EPS && p.x - (l.x + s.x) < EPS && p.y - (l.y + s.y) < EPS; } // 接してても真。
};


//// graph ////

template <class TCost = double>
struct Path
{
	typedef TCost COST;
	int from;
	int to;
	TCost cost;
	Path(int from = 0, int to = 0, TCost cost = 0)
		: from(from), to(to), cost(cost) { }
	bool operator < (const Path &rhs) const { return cost < rhs.cost; }
	bool operator >(const Path &rhs) const { return cost > rhs.cost; }
};

// dijkstra //
template <class COST>
pair<vector<COST>, vector<int>> dijkstra(const vector<vector<Path<COST>>> &routes, int start = 0, int goal = -1)
{
	typedef Path<COST> P;
	int N = routes.size();
	priority_queue<P, vector<P>, greater<P>> q;
	q.push(P(start, start, 0));

	vector<int> prev(N, -1);
	vector<COST> cost(N, INF);
	while (!q.empty())
	{
		P cur = q.top(); q.pop();
		int i = cur.to;
		if (prev[i] != -1) continue;
		prev[i] = cur.from;
		cost[i] = cur.cost;
		if (i == goal) { break; }
		REP(j, routes[i].size())
		{
			P next = P(i, routes[i][j].to, cur.cost + routes[i][j].cost);
			if (prev[i] != -1)
				q.push(next);
		}
	}
	return make_pair(cost, prev);
}

//// start up ////
void solve();
int main()
{
	solve();
	return 0;
}

////////////////////
/// template end ///
////////////////////

#define M_PI       3.14159265358979323846

void solve()
{
	int cases = INF;
	REP(_, cases)
	{
		READ(int, N);
		if (!N) { break; }

		struct xyrm{ P2 p; double r, m; int i; };
		vector<xyrm> gems;
		REP(_, N)
		{
			READ(double, x, y, r, m);
			gems.push_back({ P2(x, y), r, m, _ });
		}
		int result = 1;
		for (auto i : gems) for (auto j : gems)
		{
			//WRITE("i:", i.i, "j:", j.i);
			auto cand = getTangentialLine(Circle(i.p, i.r), Circle(j.p, j.r));
			auto cand2 = getTangentialLine(Circle(i.p, i.r + i.m), Circle(j.p, j.r));
			auto cand3 = getTangentialLine(Circle(i.p, i.r), Circle(j.p, j.r + j.m));
			auto cand4 = getTangentialLine(Circle(i.p, i.r + i.m), Circle(j.p, j.r + j.m));

			vector<Line> lines;
			copy(allof(cand), back_inserter(lines));
			copy(allof(cand2), back_inserter(lines));
			copy(allof(cand3), back_inserter(lines));
			copy(allof(cand4), back_inserter(lines));

			for (auto l : lines)
			{
				//WRITE(l.p, l.d);
				result = max<int>(result, count_if(allof(gems), PREDICATE(xyrm, g, inRange(getDistance(l, g.p), g.r, g.r + g.m))));
			}
		}
		WRITE(result);
	}
}