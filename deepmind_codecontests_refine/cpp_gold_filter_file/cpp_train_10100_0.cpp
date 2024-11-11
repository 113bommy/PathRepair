#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Description: ????????????
// Verifyed: various problem 
const R INF = 1E40L;
const R PI = acos(-1.0L);
using P=complex<R>;
const P O=0.0L;
using L=struct{P s,t;};
using VP=vector<P>;
using C=struct{P c;R r;};

istream& operator >> (istream& is,P& p){ R x,y;is >> x >> y; p=P(x,y); return is;}
ostream& operator << (ostream& os,P& p){ os << real(p) << " " << imag(p); return os;}

inline R dot(P o,P a,P b){return real(conj(a-o)*(b-o));}
inline R det(P o,P a,P b){return imag(conj(a-o)*(b-o));}
inline int sdot(P o,P a,P b){return sgn(dot(o,a,b));}
inline int sdet(P o,P a,P b){return sgn(det(o,a,b));}

//projection verify AOJ CGL_1_A
P proj(L l,P p){ R u=real((p-l.s)/(l.t-l.s)); return (1-u)*l.s+u*l.t;}


// Circle // verified: AOJ 1183 
enum RCC{OUT=2,ON_OUT=1,ISC=0,ON_IN=-1,IN=-2};
int rcc(C a,C b){ R d=abs(a.c-b.c);return sgn(d-a.r-b.r)+sgn(d-abs(a.r-b.r));}


// cross point between circle and line 
// verified: AOJ CGL_7_D
P cir(C c,R t){return c.c+polar(c.r,t);}
VP cross(C c, L l){
	P h=proj(l,c.c),e=polar(sq(norm(c.r)-norm(h-c.c)),arg(l.t-l.s));
	return VP{h-e,h+e};
}

int main(void){
	int q;
	C c;
	cin >> c.c >> c.r;
		
	cin >> q;
	cout.precision(20);
	rep(i,q){
		P a,b;
		cin >> a >> b;
		L l={a,b};
		VP res=cross(c,l);
		if(sgn(real(res[0])-real(res[1])>0)) swap(res[0],res[1]);
		if(sgn(real(res[0])-real(res[1]))==0 and sgn(imag(res[0])-imag(res[1]))>0) swap(res[0],res[1]);
		cout << fixed << res[0] << " " << res[1] << endl;
	}
	return 0;
}