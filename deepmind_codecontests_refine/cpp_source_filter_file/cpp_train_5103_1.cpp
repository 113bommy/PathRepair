#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);++i)
using namespace std;

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) (sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg)),arg)
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)

template<class T>void reg(vector<T> &ary,const T &elem){ary.emplace_back(elem);}
template<class T>bool chmin(T &a, const T &b) {return (b<a)?(a=b,1):0;}
template<class T>bool chmax(T &a, const T &b) {return (a<b)?(a=b,1):0;}

using R=long double; // __float128
const R EPS = 1E-8; // [-100:100]->EPS=1e-9 [-1000:1000]->EPS=1e-8 [-10000:10000]->EPS=1e-7
const R INF = 1E40;
const R PI = acos(R(-1));
inline int sgn(const R& r){ return (r > EPS) - (r < -EPS);}
inline R sq(R x){return sqrt(max<R>(x,0.0));}

using P=complex<R>;
using VP=vector<P>;

namespace std{
	bool operator <  (const P& a,const P& b){ return sgn(real(a-b))?real(a-b)<0:sgn(imag(a-b))<0;}
	bool operator == (const P& a,const P& b){ return sgn(real(a-b))==0 && sgn(imag(a-b))==0;}
}

using L=struct{P s,t;};

inline R dot(P o,P a,P b){a-=o,b-=o; return real(conj(a)*b);}
inline R det(P o,P a,P b){a-=o,b-=o; return imag(conj(a)*b);}

enum CCW{ LEFT = 1,RIGHT = 2,BACK = 4,FRONT = 8,ON = 16};
inline int ccw(P o,P a, P b) {
	if (sgn(det(o,a,b)) > 0) return LEFT;
	if (sgn(det(o,a,b)) < 0) return RIGHT;
	if (sgn(dot(o,a,b)) < 0) return BACK;
	if (sgn(norm(a-o)-norm(b-o)) < 0) return FRONT;
	return ON;
}

// above prepared template

P proj(P o,P a,P b){ a-=o,b-=o; return a*real(b/a);}
P proj(L l,P p){l.t-=l.s,p-=l.s;return l.s+l.t*real(p/l.t);}
P refl(L l,P p){ return R(2.0)*proj(l,p)-p;}

bool iss(L a,L b,int end=0){
	int s1=ccw(a.s,a.t,b.s)|ccw(a.s,a.t,b.t);
	int s2=ccw(b.s,b.t,a.s)|ccw(b.s,b.t,a.t);
	if(end) return (s1&s2)==(LEFT|RIGHT);
	return (s1|s2)&ON || (s1&s2)==(LEFT|RIGHT);
}

P cross(L a,L b){
	R s1=det(a.s,b.s,b.t),s2=s1+det(a.t,b.t,b.s);
	return a.s+s1/s2*(a.t-a.s);
}

R dsp(L s,P p){
	if(sgn(dot(s.s,s.t,p))<=0) return abs(p-s.s);
	if(sgn(dot(s.t,s.s,p))<=0) return abs(p-s.t);
	return abs(det(s.s,s.t,p))/abs(s.t-s.s);
}

R dss(L a,L b){return iss(a,b)?0:min({dsp(a,b.s),dsp(a,b.t),dsp(b,a.s),dsp(b,a.t)});}


using C=struct{P c;R r;};
enum RCC{OUT=4,ON_OUT=3,ISC=2,ON_IN=1,IN=0};
int rcc(C a,C b){ R d=abs(a.c-b.c);return 2+sgn(d-a.r-b.r)+sgn(d-abs(a.r-b.r));}

bool icp(C c,P p,int end=0){return sgn(norm(p-c.c)-norm(c.r))<=-end;}
// dsp
bool ics(C c,L s,int end=0){return sgn(dsp(s,c.c)-c.r)<=-end;}
bool icsc(C c,L l,int end=0){return ics(c,l) && sgn(max(norm(l.s-c.c),norm(l.t-c.c))-norm(c.r))<=0;}

R cc_area(C a,C b){
	int r=rcc(a,b);
    if(r<=ON_OUT) return 0.0;  
    if(r>=ON_IN) return min(norm(a.r),norm(b.r))*PI;
    R d=abs(b.c-a.c),rc=(norm(d)+ norm(a.r) - norm(b.r))/(2.0*d),t=acos(rc/a.r),p=acos((d-rc)/b.r);
    return norm(a.r)*t+norm(b.r)*p-d*a.r*sin(t);
}

// proj
VP pcl(C c, L l){P h=proj(l,c.c),e=(l.t-l.s)/abs(l.t-l.s)*sq(norm(c.r)-norm(h-c.c));return VP{h-e,h+e};}
// pcl
VP pcc(C a,C b){P d=b.c-a.c,w=(norm(d)+norm(a.r)-norm(b.r))/(2.0*norm(d))*d,h=a.c+w,e=w*P(0,1);return pcl(a,{h-e,h+e});}

L tan(C c,P p){P d=(p-c.c)*P(0,1);return L{p-d,p+d};}

// reg sq
VP contact(C c,P p){
	VP ret; R d=abs(p-c.c); 
	rep(i,2) reg(ret,c.c+(c.r+P(0,2*i-1)*sq(norm(d)-norm(c.r)))*c.r*(p-c.c)/norm(d));
	return uniq(ret);
}

// reg sq rcc
VP contact(C a,C b){
	VP ret; R d=abs(a.c-b.c);
	rep(i,2) if(rcc(a,b)<=8-6*i) rep(j,2){
		R r=a.r+(2*i-1)*b.r;
		reg(ret,a.c+(r+P(0,2*j-1)*sq(norm(d)-norm(r)))*a.r*(b.c-a.c)/norm(d));
	}
	return uniq(ret);
}


int main(void){
	C a,b;
	{
		int x,y,r;
		cin >> x >> y >> r;
		a=C({P(x,y),r});
		cin >> x >> y >> r;
		b=C({P(x,y),r});
	}
	cout << rcc(a,b) << endl;
	return 0;
}