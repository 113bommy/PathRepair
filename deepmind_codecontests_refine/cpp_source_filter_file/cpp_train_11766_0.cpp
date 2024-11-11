#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

template<typename T>
ostream& operator << (ostream& os, vector<T>& v){
	rep(i,v.size()){ os << v[i] << (i == v.size() - 1 ? "" : " "); } return os;
}
template<typename T>
istream& operator >> (istream& is, vector<T>& v){
	for(T& x: v){ is >> x; } return is;
}

typedef complex<double> Point;
typedef Point Vector;
struct Segment{					//線分を表す構造体
	Point p1, p2;
	Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};
typedef Segment Line;			//直線を表す構造体
typedef vector<Point> Polygon;	//多角形を表す構造体

namespace std{
	bool operator < (const Point &a, const Point &b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
	bool operator == (const Point &a, const Point &b){
		return a.real() == b.real() && a.imag() == b.imag();
	}
}

class Circle{
	public:
		Point p;
		double r, m;
		Circle(Point p = Point(), double r = 0.0, double m = 0.0): p(p), r(r), m(m) {}
};

// 許容する誤差
#define EPS (1e-10)
#define INF (1e10)

// ベクトルaの絶対値を求める
//double length = abs(a);

// 2点a,b間の距離を求める
//double distance = abs(a-b);

/*
// ベクトルaの単位ベクトルを求める
Point b = a / abs(a);

// ベクトルaの法線ベクトルn1,n2を求める
Point n1 = a * Point(0, 1);
Point n2 = a * Point(0, -1);
*/

int ccw(Point, Point, Point);

// 2つのスカラーが等しいかどうか
bool EQ(double a, double b){
	return (abs(a - b) < EPS);
}

// 2つのベクトルが等しいかどうか
bool EQV(Vector a, Vector b){
	return ( EQ(a.real(), b.real()) && EQ(a.imag(), b.imag()) );
}

// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(Point a, Point b) {
	return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(Point a, Point b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}

// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
	return EQ( dot(a1-a2, b1-b2), 0.0 );
}
bool isOrthogonal(Line s1, Line s2) { return isOrthogonal(s1.p1, s1.p2, s2.p1, s2.p2); }

// 2直線の平行判定 : a//b <=> cross(a, b) = 0
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
	return EQ( cross(a1-a2, b1-b2), 0.0 );
}
bool isParallel(Line s1, Line s2) { return isParallel(s1.p1, s1.p2, s2.p1, s2.p2); }

// 点cが直線a,b上にあるかないか
bool isPointOnLine(Point a, Point b, Point c) {
	return EQ( cross(b-a, c-a), 0.0 );
}
bool isPointOnLine(Line s, Point c) { return isPointOnLine(s.p1, s.p2, c); }

// 点a,bを通る直線と点cとの距離
double distanceLPoint(Point a, Point b, Point c) {
	return abs(cross(b-a, c-a)) / abs(b-a);
}
double distanceLPoint(Line s, Point c) { return distanceLPoint(s.p1, s.p2, c); }

// 点a,bを端点とする線分と点cとの距離
double distanceLsPoint(Point a, Point b, Point c) {
	if ( dot(b-a, c-a) < EPS ) return abs(c-a);
	if ( dot(a-b, c-b) < EPS ) return abs(c-b);
	return abs(cross(b-a, c-a)) / abs(b-a);
}
double distanceLsPoint(Segment s, Point c) { return distanceLsPoint(s.p1, s.p2, c); }

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
// 端点が重なる場合も、線分が交差しているとみなす
bool isIntersectedLs(Point a1, Point a2, Point b1, Point b2) {
	return ( ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0 &&
			ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0 );
}
bool isIntersectedLs(Segment s1, Segment s2) { return isIntersectedLs(s1.p1, s1.p2, s2.p1, s2.p2); }

// 端点が重なっているかを検出する
bool isContainSamePoints(Segment s1, Segment s2){
	if(abs(s1.p1 - s2.p1) < EPS) return true;
	if(abs(s1.p1 - s2.p2) < EPS) return true;
	if(abs(s1.p2 - s2.p1) < EPS) return true;
	if(abs(s1.p2 - s2.p2) < EPS) return true;
	return false;
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算
Point intersectionLs(Point a1, Point a2, Point b1, Point b2) {
	Vector base = b2 - b1;
	double d1 = abs(cross(base, a1 - b1));
	double d2 = abs(cross(base, a2 - b1));
	double t = d1 / (d1 + d2);

	return Point(a1 + (a2 - a1) * t);
}
Point intersectionLs(Segment s1, Segment s2) { return intersectionLs(s1.p1, s1.p2, s2.p1, s2.p2); }

// a1,a2を通る直線とb1,b2を通る直線の交差判定
bool isIntersectedL(Point a1, Point a2, Point b1, Point b2) {
	return !EQ( cross(a1-a2, b1-b2), 0.0 );
}
bool isIntersectedL(Line l1, Line l2) { return isIntersectedL(l1.p1, l1.p2, l2.p1, l2.p2); }

// a1,a2を通る直線とb1,b2を通る直線の交点計算
Point intersectionL(Point a1, Point a2, Point b1, Point b2) {
	Point a = a2 - a1; Point b = b2 - b1;
	return a1 + a * cross(b, b1-a1) / cross(b, a);
}
Point intersectionL(Line l1, Line l2) { return intersectionL(l1.p1, l1.p2, l2.p1, l2.p2); }

// 線分s1と線分s2の距離
double distanceLL(Segment s1, Segment s2){
	if(isIntersectedLs(s1.p1, s1.p2, s2.p1, s2.p2) ) return 0.0;
	return min(
			min(distanceLsPoint(s1.p1, s1.p2, s2.p1),
				distanceLsPoint(s1.p1, s1.p2, s2.p2)),
			min(distanceLsPoint(s2.p1, s2.p2, s1.p1),
				distanceLsPoint(s2.p1, s2.p2, s1.p2)) );
}
double distanceLL(Point p0, Point p1, Point p2, Point p3){
	Segment s1 = Segment{p0, p1}, s2 = Segment{p2, p3};
	return distanceLL(s1, s2);
}

// 線分sに対する点pの射影
Point project(Segment s, Point p){
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / norm(base);
	return Point(s.p1 + base * r);
}

//線分sを対象軸とした点pの線対称の点
Point reflect(Segment s, Point p){
	return Point(p + (project(s, p) - p) * 2.0);
}

//点pをangle分だけ時計回りに回転
Point rotation(Point p, double angle){
	double x, y;
	x = p.real() * cos(angle) - p.imag() * sin(angle);
	y = p.real() * sin(angle) + p.imag() * cos(angle);
	return Point(x, y);
}

//円cと線分lの交点
pair<Point, Point> getCrossPoints(Circle c, Line l){
	Vector pr = project(l, c.p);
	Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
	double base = sqrt(c.r * c.r - norm(pr - c.p));
	return make_pair(pr + e * base, pr - e * base);
}

//円c1と円c2の交点
double arg(Vector p) { return atan2(p.imag(), p.real()); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) *a); }

pair<Point, Point> getCrossPoints(Circle c1, Circle c2){
	double d = abs(c1.p - c2.p);
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.p - c1.p);
	return make_pair(Point(c1.p + polar(c1.r, t + a)), Point(c1.p + polar(c1.r, t - a)));
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2){
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
	if( cross(a, b) < -EPS ) return CLOCKWISE;
	if( dot(a, b) < -EPS ) return ONLINE_BACK;
	if( abs(a) < abs(b) ) return ONLINE_FRONT;

	return ON_SEGMENT;
}

// 円と点の接線を求める
Line getTangentPointointCp(Circle c, Point p) {
	auto pow = [](double a) -> double {return a * a; };
	double x = p.real() - c.p.real(), y = p.imag() - c.p.imag();

	double sqt = sqrt((pow(x) + pow(y)) - pow(c.r));
	double denominator = pow(x) + pow(y);

	double x1 = c.r * (x * c.r + y * sqt) / denominator + c.p.real();
	double y1 = c.r * (y * c.r - x * sqt) / denominator + c.p.imag();
	double x2 = c.r * (x * c.r - y * sqt) / denominator + c.p.real();
	double y2 = c.r * (y * c.r + x * sqt) / denominator + c.p.imag();

	return Line(Point(x1, y1), Point(x2, y2));
}

// 円と円の接線を求める
vector<Line> getTangentPointointCc(Circle a, Circle b, bool x = 0) {
	if(x){
		a.r = a.m;
		b.r = b.m;
	}
	auto pow = [](double a) -> double {return a * a; };

	Circle c(Point(b.p.real() - a.p.real(), b.p.imag() - a.p.imag()), b.r);

	vector<Line> res;

	auto f = [&](double R) {
		double left = a.r + R;
		double right = sqrt((pow(c.p.real()) + pow(c.p.imag())) - pow(a.r + R));
		double denominator = pow(c.p.real()) + pow(c.p.imag());

		double x1 = a.r * (c.p.real() * left + c.p.imag() * right) / denominator + a.p.real();
		double y1 = a.r * (c.p.imag() * left - c.p.real() * right) / denominator + a.p.imag();

		double x2 = a.r * (c.p.real() * left - c.p.imag() * right) / denominator + a.p.real();
		double y2 = a.r * (c.p.imag() * left + c.p.real() * right) / denominator + a.p.imag();

		Line l = Line(Point(x1, y1), Point(x2, y2));
		if (not std::isnan(l.p1.real())) res.emplace_back(l);
	};

	f(c.r);		// 内接線
	f(-c.r);	// 外接線

	return res;
}

int getStones(vector<Circle>& c, Line l){
	int res = 0;
	//cout << l.p1 << ' ' << l.p2 << endl;
	for(auto i : c){
		double dis = distanceLPoint(l, i.p);
		cout << dis << ' ' << i.r << ' ' << i.m << endl;
		if(dis >= i.r and dis <= i.m) res++;
	}
	return res;
}

int main(){
	int n;
	Circle c[2];
	rep(i,2){
		double a, b, r;
		cin >> a >> b >> r;
		c[i] = Circle(Point(a,b), r);
	}
	vector<Line> l = getTangentPointointCc(c[0], c[1]);
	set<Point> p;
	for(auto i : l){
		p.emplace(i.p1);
		p.emplace(i.p2);
	}
	fixed << setprecision(10);
	for(auto i : p) cout << i.real() << ' ' << i.imag() << endl;
	return 0;
	while(cin >> n,n){
		vector<Circle> c(n);
		rep(i,n){
			double a, b, r, m;
			cin >> a >> b >> r >> m;
			c[i] = Circle{Point{a,b}, r, m};
		}

		vector<Line> ls;
		rep(i,n){
			range(j,i + 1,n){
				for(auto k : getTangentPointointCc(c[i], c[j])){
					if(k.p1 == k.p2) continue;
					//cout << k.p1 << ' ' << k.p2 << endl;
					ls.emplace_back(k);
				}
			}
		}
		rep(i,n){
			range(j,i + 1,n){
				for(auto k : getTangentPointointCc(c[i], c[j], 1)){
					if(k.p1 == k.p2) continue;
					//cout << k.p1 << ' ' << k.p2 << endl;
					ls.emplace_back(k);
				}
			}
		}

		int maxi = 1;
		for(auto i : ls){
			cout << i.p1 << ' ' << i.p2 << endl;
			maxi = max(maxi, getStones(c, i));
		}
		cout << maxi << endl;
	}
}

