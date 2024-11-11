#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <iterator>

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;

const double EPS = 1e-8;
const double PI=acos(-1.0);

template<class T>
struct point{
    T x,y;
    point() : x(0), y(0) {}
    point(const T& x,const T& y) : x(x), y(y) {}
    point operator+(const point &a)const{ return point(x+a.x,y+a.y); }
    point& operator+=(const point &a){x += a.x; y += a.y; return *this;}
    point operator-(const point &a)const{ return point(x-a.x,y-a.y); }
    point& operator-=(const point &a){x -= a.x; y -= a.y; return *this;}
    point operator*(const double a)const{ return point(a*x,a*y); }
    point& operator*=(const double a){ x *= a; y *= a; return *this;}
    point operator/(const double a)const{ return point(x/a,y/a); }
    point& operator/=(const double a){ x /= a; y /= a; return *this;}
	
	//比較用
	bool operator<(const point &a)const{return (x != a.x) ? (x < a.x) : (y < a.y);}
 
};

template<class T> T SQ(T x){ return x*x; }
template<class T> T dist2(const point<T> &a,const point<T> &b){return SQ(a.x-b.x)+SQ(a.y-b.y);}
template<class T> T abs(const point<T>& p){return sqrt(SQ(p.x) + SQ(p.y));}
template<class T> T dot(const point<T>& a,const point<T>& b)
{return a.x*b.x + a.y*b.y;}
template<class T> T cross(const point<T>& a,const point<T>& b)
{return a.x*b.y - a.y*b.x;}
template<class T> point<T> rot(const point<T>& a,const double theta){
        return point<T>(a.x*cos(theta)-a.y*sin(theta),
			a.x*sin(theta)+a.y*cos(theta));
}
template<class T>
double arg(const point<T> &a){	double t=atan2(a.y,a.x); return t<0?t+2*PI:t; }

enum{CCW=1,CW=-1,ON=0};
template<class T>
int ccw(const point<T> &a,const point<T> &b,const point<T> &c){
    double rdir=cross(b-a,c-a);
    if(rdir> EPS) return CCW; //cがabより上(反時計周り)
    if(rdir<-EPS) return CW; // cがabより下(時計周り)
    return ON; // a,b,cが一直線上
}

//多角形の面積
template<class T>
T area(const vector<point<T> >& v){
	T ans = 0;
	for (int i = 2; i < (int)v.size(); i++){
		ans += cross(v[i-1] - v[0],v[i] - v[0]);
	}
	return abs(ans) / 2;
}

template<class T>
struct segment{
    point<T> a,b;
    segment() : a(point<T>()), b(point<T>()) {}
    segment(const point<T>& a,const point<T>& b) : a(a), b(b) {}
};

template<class T>
struct line{
    point<T> a,b;
    line() : a(point<T>()), b(point<T>()) {}
    line(const point<T>& a,const point<T>& b) : a(a), b(b) {}
};

bool intersect(const segment<double> &S1,const segment<double> &S2){
    if(max(S1.a.x,S1.b.x)+EPS<min(S2.a.x,S2.b.x)
    || max(S1.a.y,S1.b.y)+EPS<min(S2.a.y,S2.b.y)
    || max(S2.a.x,S2.b.x)+EPS<min(S1.a.x,S1.b.x)
    || max(S2.a.y,S2.b.y)+EPS<min(S1.a.y,S1.b.y)) return false;
    return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
        && ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}

template<class T>
double dist2(const segment<T> &S,const point<T> &p){
    if(dot(S.b-S.a,p-S.a)<=0) return dist2(p,S.a);
    if(dot(S.a-S.b,p-S.b)<=0) return dist2(p,S.b);
    return (double)SQ(cross(S.b-S.a,p-S.a)) / dist2(S.a,S.b);
}

template<class T>
double dist(const segment<T> &S,const point<T> &p){ return sqrt(dist2(S,p)); }

template<class T>
double dist(const segment<T> &S1,const segment<T> &S2){
    if(intersect(S1,S2)) return 0;
    return sqrt(min(min(dist2(S1,S2.a),dist2(S1,S2.b)),
                    min(dist2(S2,S1.a),dist2(S2,S1.b))));
}

template<class T>
double dist(const line<T> &L,const point<T> &p){
    return sqrt((double)SQ(cross(L.b-L.a,p-L.a)) / dist2(L.a,L.b));
}


//凸包
template<class T>
vector< point<T> > convex_hull(vector< point<T> >& ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector< point<T> > ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;

  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;

  ch.resize(k-1);

  return ch;
}


template<class T>
struct circle{
	point<T> c;
	T r;
	circle(){}
	circle(const point<T> &c, T& r) : c(c),r(r) {}
};

//a -- bの間の円が入った時の、a - b間の距離
//円の間に
template<class T>
double geodist(point<T> a,point<T> b,const circle<T> &C){
	double r=C.r;
	segment<T> s(a,b);
	if(dist(s,C.c)>r) 
		return abs(a-b);

	a-=C.c;
	b-=C.c;

	double L1=abs(a);
	double t1=arg(a)+acos(r/L1); if(t1<0) t1+=2*PI;
	double t2=arg(a)-acos(r/L1); if(t2<0) t2+=2*PI;

	double L2=abs(b);
	double t3=arg(b)+acos(r/L2); if(t3<0) t3+=2*PI;
	double t4=arg(b)-acos(r/L2); if(t4<0) t4+=2*PI;

	double theta=2*PI;
	theta=min(theta,min(abs(t1-t4),2*PI-abs(t1-t4)));
	theta=min(theta,min(abs(t2-t3),2*PI-abs(t2-t3)));
	return sqrt(L1*L1-r*r)+sqrt(L2*L2-r*r)+r*theta;
}

//円の接点
template<class T>
vector< point<T> > GetContact(const point<T>& p,const point<T>& q,const double r){
	point<T> a = p-q;
	double s = SQ(a.x) + SQ(a.y);
	double D = sqrt(s - SQ(r));
	double dx = r * D * a.y / s;
	double dy = r * D * a.x / s;
	double bx = SQ(r) * a.x / s;
	double by = SQ(r) * a.y / s;
	point<T> ans(2);
	ans[0].x = bx + dx;
	ans[0].y = by - dy;
	ans[1].x = bx - dx;
	ans[1].y = by + dy;

	ans[0] += q;
	ans[1] += q;

	return ans;
}



//todo : verifyしてないので、そのうち。
// 円が交差しているか 「=」は問によって変更する
template<class T>
int CircleCross(const circle<T> &c1,const circle<T> &c2){
	double l = abs(c1.c - c2.c);
	if(l >= c1.r + c2.r) return 3; //外部にある
	if(l + c1.r <= c2.r) return 2; //c1 ⊃ c2
	if(l + c2.r <= c1.r) return 1; //c1 ⊂ c2
	return 0; //交差している
}


template<class T>
std::ostream& operator<<(std::ostream& os, const point<T>& point){return ( os << '(' << point.x << ',' << point.y << ')' );}
template<class T>
std::ostream& operator<<(std::ostream& os, const segment<T>& seg){return ( os << '{' << seg.a << ',' << seg.b << '}' );}
 
typedef point<double> P;
typedef segment<double> S;
typedef line<double> L;
typedef circle<double> C;

int n;
P pt[300];

int getCnt(const P &o){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if(abs(pt[i] - o) <= 1.0 + EPS)
            cnt++;
    }
    return cnt;
}

int solve()
{
    for (int i = 0; i < n; i++) scanf("%lf,%lf",&(pt[i].x),&(pt[i].y));
    int ans = 1;
 
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            P e = pt[j] - pt[i];
            double len = abs(e);
            if(len > 2.0 + EPS) continue;
            P md = pt[i] + e / 2.0;
            e /= len;
            e = rot(e,PI/2);
            double o_dis = sqrt(1.0 - SQ(len / 2));
            e *= o_dis;
            static int dir[] = {1,-1};
            for (int k = 0; k < 2; k++){
                e *= -1;
                ans = max(ans,getCnt(md + e));
            }
        }
    }
 
    return ans;
 
}
 
int main(){
    while(cin>>n,n){
        cout << solve() << endl;
    }
    return 0;
}