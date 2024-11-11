
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef complex<ld> PT;
typedef vector<PT> Poly;
typedef pair<PT, PT> LS;
#define F first
#define S second
#define X real()
#define Y imag()
#define pb push_back

inline int in(){int x, y; y = scanf("%d", &x); return x; }

const int N = -1;
const ld EPS = 1e-12;

const int LEFT = 0, RIGHT = 1, BACK = 2, FRONT = 3, ON = 4, IN = 5, OUT = 6;

inline bool Geq(ld a, ld b){ return a + EPS > b; }
inline bool Grt(ld a, ld b){ return a > b + EPS; }
inline bool Leq(ld a, ld b){ return a < b + EPS; }
inline bool Lss(ld a, ld b){ return a + EPS < b; }
inline bool Equ(ld a, ld b){ return Geq(a, b) && Geq(b, a); }

istream& operator>> (istream& is, complex<ld>& p){
	ld val;
	is >> val;
	p.real(val);
	is >> val;
	p.imag(val);
	return is;
}

ld dot(PT a, PT b){ return real(conj(a)*b); }
ld cross(PT a, PT b){ return imag(conj(a)*b); }
ld sqlen(PT a){ return dot(a, a); }
ld len(PT a){ return sqrt(sqlen(a)); }

PT proj(PT a, PT b, PT c){
	b -= a, c -= a;
	return a + b*real(c/b);
}

PT reflect(PT a, PT b, PT c){
	b -= a, c -= a;
	return a + conj(c/b)*b;
}

PT rotate(PT a, PT b, ld theta){
	return (b-a)*polar<ld>(1, theta) + a;
}

int relpos(PT a, PT b, PT c){
	b -= a, c -= a;
	c /= b;
	if (Grt(c.imag(), 0)) return LEFT;
	if (Lss(c.imag(), 0)) return RIGHT;
	if (Lss(c.real(), 0)) return BACK;
	if (Grt(c.real(), 1)) return FRONT;
	return ON;
}

int side(PT a, PT b, PT c){
	b -= a, c -= a;
	ld cr = (c/b).Y;
	return Grt(cr, 0) ? 1 : (Lss(cr, 0) ? -1 : 0);
}

//If LineSegments Intersect
bool intersect(PT a, PT b, PT c, PT d){
	int as = side(c, d, a), bs = side(c, d, b), cs = side(a, b, c), ds = side(a, b, d);
	if (as && as == bs || cs && cs == ds) return false;
	else if (as || bs || cs || ds) return true;
	for (int j = 0; j < 2; j++, swap(a, c), swap(b, d)){
		ld mx = min(a.X, b.X), Mx = max(a.X, b.X), my = min(a.Y, b.Y), My = max(a.Y, b.Y);
		for (int k = 0; k < 2; k++, swap(c, d))
			if (Geq(c.X, mx) && Leq(c.X, Mx) && Geq(c.Y, my) && Leq(c.Y, My))
				return true;
	}
	return false;
}

//LineSegments Intersection (intersect is true)
PT intersection(PT a, PT b, PT c, PT d){
	ld c1 = cross(b-a, c-a), c2 = cross(b-a, d-a);
	return (c1*d - c2*c)/(c1-c2);
}

ld distLSP(PT a, PT b, PT c){
	int rpos = relpos(a, b, proj(a, b, c));
	if (rpos == BACK) return len(c-a);
	if (rpos == FRONT) return len(c-b);
	b -= a, c -= a;
	return abs(cross(b, c)/len(b));
}

ld distLS(PT a, PT b, PT c, PT d){
	if (intersect(a, b, c, d)) return 0;
	return min(min(distLSP(a, b, c), distLSP(a, b, d)), min(distLSP(c, d, a), distLSP(c, d, b)));
}

ld signedArea(Poly &po){
	int n = po.size();
	ld res = 0;
	for (int i = 0; i < n; i++)
		res += cross(po[i], po[(i+1)%n]);
	return res/2;
}

ld area(Poly &poly){
	return abs(signedArea(poly));
}

bool isConvex(Poly &po){
	int n = po.size();
	bool neg = false, pos = false;
	for (int i = 0; i < n; i++){
		int rpos = relpos(po[i], po[(i+1)%n], po[(i+2)%n]);
		if (rpos == LEFT) pos = true;
		if (rpos == RIGHT) neg = true;
	}	
	return (neg&pos) == false;
}

int crossingN(Poly &po, PT a){
	int n = po.size();
	PT b = a;
	for (int i = 0; i < n; i++)
		b.real(max(b.X, po[i].X));
	int cn = 0;
	for (int i = 0; i < n; i++){
		PT p = po[i], q = po[(i+1)%n];
		if (intersect(a, b, p, q) && (side(a, b, p) == 1 || side(a, b, q) == 1))
			cn++;
	}
	return cn;
}

int pointInPoly(Poly &po, PT a){
	int n = po.size();
	for (int i = 0; i < n; i++)
		if (relpos(po[i], po[(i+1)%n], a) == ON)
			return ON;	
	return (crossingN(po, a)%2 ? IN : OUT);
}

int main(){	
	Poly poly;
	for (int i = in(); i; i--){
		PT p;
		cin >> p;
		poly.pb(p);
	}
	for (int i = in(); i; i--){
		PT p;
		cin >> p;
		int s = pointInPoly(poly, p);
		cout << (s == IN ? 2 : (s == ON ? 1 : 0)) << endl;
	}
	return 0;
}
