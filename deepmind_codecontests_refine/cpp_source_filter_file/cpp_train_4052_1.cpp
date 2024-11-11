#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VEC;
typedef vector<VEC> MAT;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))
#define T1 first
#define T2 second.first
#define T3 second.second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define EPS 1e-7

typedef complex<double> P;
typedef struct segment{
	P p[2];
	segment(P p1, P p2){
		p[0]=p1;
		p[1]=p2;
	};
	segment(){};
};

segment seg[5];
int reflec[10];
int n;
P source,sinc;

inline double dot(P &p1,P &p2){
	return real(p1*conj(p2));
}
inline double cross(P &p1, P &p2){
	return imag(p1*conj(p2));
}
inline P mirror(P &p, segment &_seg){
	double t=dot(p-_seg.p[0], _seg.p[1]-_seg.p[0])/norm(_seg.p[1]-_seg.p[0]);
	P q=_seg.p[0]+t*(_seg.p[1]-_seg.p[0]);
	return 2.0*q-p;
}
int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}
bool intersectSS(const segment &s, const segment &t) {
  return ccw(s.p[0],s.p[1],t.p[0])*ccw(s.p[0],s.p[1],t.p[1]) <= 0 &&
         ccw(t.p[0],t.p[1],s.p[0])*ccw(t.p[0],t.p[1],s.p[1]) <= 0;
}

double intersectSS(const segment &s, const segment &t, P &p) {
	double t1, t2, t0;
	t0 = imag((t.p[1]-t.p[0])*conj(s.p[1]-s.p[0]));
	if(abs(t0) < EPS)return -1.0;
	t1 = imag((t.p[1]-t.p[0])*conj(t.p[1]-s.p[0]));
	t2 = -imag((s.p[1]-s.p[0])*conj(t.p[1]-s.p[0]));
	t1/=t0;
	t2/=t0;
	if(EPS<t1 && t1<1-EPS && EPS<t2 && t2<1-EPS){
		p = s.p[0] + t1*(s.p[1]-s.p[0]);
		return t1;
	}
	return -1.0;
}

P finalIntersect(P &ps, P &pe, int &idx){
	idx=-1;
	double tmax=0.0;
	P ret(0,0);
	REP(i,n){
		P tP;
		double tmp = intersectSS(segment(ps,pe), seg[i], tP);
		if(tmp>tmax){
			tmax = tmp;
			idx = i;
			ret=tP;
		}
	}
	return ret;
}

double check(list<int> &li){
	int p = li.size();
	P goal = sinc;
	P start = source;
	double ret =1e9;
	for(list<int>::iterator it = li.begin(); it!=li.end(); it++)start = mirror(start, seg[*it]);
	ret = sqrt(norm(start-goal));
	int cidx;
	for(list<int>::reverse_iterator it = li.rbegin(); it!=li.rend(); it++){
		goal=finalIntersect(start, goal, cidx);
		if(cidx!=(*it))return 1e9;
		start=mirror(start, seg[(*it)]);
	}
	finalIntersect(start, goal, cidx);
	if(cidx!=-1)return 1e9;
	return ret;
	
}

int main(){
	while(cin>>n, n){
		double x1, y1, x2, y2;
		REP(i,n){
			scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
			seg[i]=segment(P(x1,y1), P(x2,y2));
		}
		scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
		sinc=P(x1,y1);
		source=P(x2,y2);
		P t;
		list<int> ll;
		double ret=check(ll);
		REP(i1,n){
			ll.PB(i1);
			ret = min(ret, check(ll));
			REP(i2,n){
				if(i2==i1)continue;
				ll.PB(i2);
				ret = min(ret, check(ll));
				REP(i3,n){
					if(i3==i2)continue;
					ll.PB(i3);
					ret = min(ret, check(ll));
					REP(i4,n){
						if(i4==i3)continue;
						ll.PB(i4);
						ret = min(ret, check(ll));
						REP(i5,n){
							if(i5==i4)continue;
							ll.PB(i5);
							ret = min(ret, check(ll));
							ll.pop_back();
						}
						ll.pop_back();
					}
					ll.pop_back();
				}
				ll.pop_back();
			}
			ll.pop_back();
		}
		printf("%.8f\n", ret);
	}
}