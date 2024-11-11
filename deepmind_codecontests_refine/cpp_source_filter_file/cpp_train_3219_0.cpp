#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const ld eps = 1e-8, pi = acos(-1.0), inf = 1e20;

bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}

using Point = complex<ld>;
class Line {
public:
	Point a, b;
};
ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c) {
	b -= a, c -= a;
	if (cross(b, c) > eps) return 1;	// a,b,c??????????¨???¨???
	if (cross(b, c) < -eps) return -1;	// a,b,c???????¨???????
	if (dot(b, c) < 0) return 2;		// c,a,b????????§??´???
	if (norm(b) < norm(c)) return -2;	// a,b,c???????????´???
	return 0;							// a,c,b???????????´???
}

bool isis_ll(Line l, Line m) {
	return abs(cross(l.b - l.a, m.b - m.a)) > eps;
}

bool isis_ls(Line l, Line s) {
	return (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

bool isis_lp(Line l, Point p) {
	return abs(cross(l.b - p, l.a - p)) < eps;
}

bool isis_sp(Line s, Point p) {
	return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;
}

Point proj(Line l, Point p) {
	ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
	return l.a + t * (l.a - l.b);
}

Point is_ll(Line s, Line t) {
	Point sv = s.b - s.a, tv = t.b - t.a;
	assert(cross(sv, tv) != 0);
	return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}

bool isis_ss(Line s, Line t) {
	if (isis_ll(s, t)) return isis_ls(s, t) && isis_ls(t, s);
	return isis_sp(s, t.a) || isis_sp(s, t.b) || isis_sp(t, s.a);
}

ld dist_lp(Line l, Point p) {
	return abs(p - proj(l, p));
}

ld dist_ll(Line l, Line m) {
	return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls(Line l, Line s) {
	return isis_ls(l, s) ? 0 : min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp(Line s, Point p) {
	Point r = proj(s, p);
	return isis_sp(s, r) ? abs(r - p) : min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss(Line s, Line t) {
	if (isis_ss(s, t)) return 0;
	return min({ dist_sp(s, t.a), dist_sp(s, t.b), dist_sp(t, s.a), dist_sp(t, s.b) });
}


class Circle {
public:
	Point p;
	ld r;
};

int nct(Circle c1, Circle c2) {
	ld d = abs(c1.p - c2.p);
	ld r1 = max(c1.r, c2.r), r2 = min(c1.r, c2.r);
	if (d > r1 + r2 + eps) return 4;
	if (eq(d, r1 + r2)) return 3;
	if (d > r1 - r2 + eps) return 2;
	if (eq(d, r1 - r2)) return 1;
	return 0;
}

vector<Point> is_cc(Circle c1, Circle c2) {
	vector<Point> res;
	ld d = abs(c1.p - c2.p);
	assert(d != 0.0);
	ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	ld dfr = c1.r * c1.r - rc * rc;
	if (abs(dfr) < eps) dfr = 0.0;
	if (dfr < 0.0) return res;
	ld rs = sqrt(dfr);
	Point diff = (c2.p - c1.p) / d;
	res.push_back(c1.p + diff * Point(rc, rs));
	res.push_back(c1.p + diff * Point(rc, -rs));
	return res;
}

vector<Point> is_lc(Circle c, Line l) {
	vector<Point> res;
	ld d = dist_lp(l, c.p);
	if (d > c.r + eps) return res;
	ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d);
	Point nor = (l.a - l.b) / abs(l.a - l.b);
	res.push_back(proj(l, c.p) + len * nor);
	res.push_back(proj(l, c.p) - len * nor);
	return res;
}

vector<Point> is_sc(Circle c, Line s) {
	vector<Point> v = is_lc(c, s), res;
	for (size_t k = 0; k < v.size(); k++) {
		if (ccw(s.a, v[k], s.b) == -2) {
			res.push_back(v[k]);
		}
	}
	return res;
}

vector<Line> tangent_cp(Circle c, Point p) {
	vector<Line> res;
	Point v = c.p - p;
	ld d = abs(v);
	ld l = sqrt(norm(v) - c.r * c.r);
	if (isnan(l)) return res;
	Point v1 = v * Point(l / d, c.r / d);
	Point v2 = v * Point(l / d, -c.r / d);
	res.push_back((Line) { p, p + v1 });
	if (l < eps) return res;
	res.push_back((Line) { p, p + v2 });
	return res;
}

vector<Line> tangent_cc(Circle c1, Circle c2) {
	vector<Line> res;
	if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
		Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
		res = tangent_cp(c1, center);
	}
	if (abs(c1.r - c2.r) > eps) {
		Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
		vector<Line> nres = tangent_cp(c1, out);
		res.insert(res.end(), nres.begin(), nres.end());
	}
	else {
		Point v = c2.p - c1.p; v /= abs(v);
		Point q1 = c1.p + v * Point(0, 1) * c1.r;
		Point q2 = c1.p + v * Point(0, -1) * c1.r;
		res.push_back((Line) { q1, q1 + v });
		res.push_back((Line) { q2, q2 + v });
	}
	return res;
}


int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(5);
	int n;
	while (cin >> n, n) {
		vector<Circle> cs(n);
		for (int i = 0, x, y, r; i < n; i++) {
			cin >> x >> y >> r;
			cs[i] = (Circle) { Point(x, y), r };
		}
		vector<Point> pp(n * 2); pp[0] = cs[0].p; pp[n * 2 - 1] = cs[n - 1].p;
		for (int i = 1; i < n; i++) {
			auto v = is_cc(cs[i - 1], cs[i]);
			pp[i * 2 - 1] = v[0];
			pp[i * 2] = v[1];
		}
		vector<vector<ld>> dis(n * 2, vector<ld>(n * 2, inf));
		for (int i = 0; i < n * 2; i++) {
			dis[i][i] = 0;
		}
		for (int i = 0; i < n * 2; i++) {
			for (int j = i + 1; j < n * 2; j++) {
				bool can = true;
				for (int k = (i + 1) / 2 + 1; k <= (j + 1) / 2; k++) {
					if (!isis_ss((Line) { pp[i], pp[j] }, (Line) { pp[k * 2 - 1], pp[k * 2] })) {
						can = false;
						break;
					}
				}
				if (can) {
					dis[i][j] = dis[j][i] = abs(pp[i] - pp[j]);
				}
			}
		}
		for (int k = 0; k < n * 2; k++) {
			for (int i = 0; i < n * 2; i++) {
				for (int j = 0; j < n * 2; j++) {
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				}
			}
		}
		cout << dis[0][n * 2 - 1] << endl;
	}
	return 0;
}