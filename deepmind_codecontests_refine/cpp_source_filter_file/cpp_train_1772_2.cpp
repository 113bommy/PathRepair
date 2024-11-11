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

// Problem Specific Parameter:

// Description: ????????????
// Verifyed: various problem 
const R INF = 1E40L;
const R PI = acos(-1.0L);
using P=complex<R>;
const P O=0.0L;
using L=struct{P s,t;};
using VP=vector<P>;
using C=struct{P p;R c;};

istream& operator >> (istream& is,P& p){ R x,y;is >> x >> y; p=P(x,y); return is;}
ostream& operator << (ostream& os,P& p){ os << real(p) << " " << imag(p); return os;}

inline R dot(P o,P a,P b){return real(conj(a-o)*(b-o));}
inline R det(P o,P a,P b){return imag(conj(a-o)*(b-o));}
inline int sdot(P o,P a,P b){return sgn(dot(o,a,b));}
inline int sdet(P o,P a,P b){return sgn(det(o,a,b));}

//projection verify AOJ CGL_1_A
P proj(L l,P p){ R u=real((p-l.s)/(l.t-l.s)); return (1-u)*l.s+u*l.t;}

// convex_hull Verify AOJ CGL_4_A
VP convex_hull(VP pol){
	int n=pol.size(),k=0;
	sort(begin(pol),end(pol),[](P a,P b)->bool{return sgn(real(a)-real(b))?sgn(rael(a)-real(b))<0:sgn(imag(a)-imag(b)<0);});
	VP res(2*n);

	// down
	rep(i,n){
		while(k>1&&sdet(O,res[k-1]-res[k-2],pol[i]-res[k-1])>=1) k--;
		res[k++]=pol[i];
	}
	
	// up
	int t=k;
	rrep(i,n-1){
		while(k>t&&sdet(O,res[k-1]-res[k-2],pol[i]-res[k-1])>=1) k--;
		res[k++]=pol[i];
	}
	res.resize(k-1);
	return res;
}

int main(void){
	int n;
	cin >> n;
	VP pol;
	rep(i,n){
		P p;
		cin >> p;
		pol.push_back(p); 
	}
	VP res=convex_hull(pol);
	int m=res.size(),idx=0;
	rep(i,m){
		if(imag(res[i])<imag(res[idx])) idx=i;
		if(imag(res[i])==imag(res[idx])&&real(res[i])<real(res[idx])) idx=i;
	}
	cout << m << endl;
	rep(i,m) cout << res[(idx-i+m)%m] << endl;
	return 0;
}