#include <cstdio>
#include <complex>
#include <vector>

using namespace std;
typedef complex<double> P;

bool eq(double d,double e){return abs(d-e)<1e-10;};
bool eqv(P p,P q){return eq(p.real(),q.real()) && eq(p.imag(),q.imag());}

const P nowhere(200,200);
double cross_product(P a, P b) { 
  return (conj(a)*b).imag();
}

P crosspoint(const P& l0, const P& l1,
	     const P& r0, const P& r1) {
    double n = cross_product(r1-r0, r0-l0);
    double d = cross_product(r1-r0, l1-l0);
    return l0 + (l1-l0)*n/d;
}

P ok(P p){
  if(abs(p.real()) > 100-1e-10 || abs(p.imag()) > 100-1e-10)
    return nowhere;
  else
    return p;
}

int n,nl;


int main(){
  while(scanf("%d",&n),n){
    vector<P> ps,qs;
    int ans=1;

    for(int i=0; i<n; i++){
      double x1,y1,x2,y2;
      scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
      ps.push_back(P(x1,y1)); qs.push_back(P(x2,y2));
    }

    for(int i=0; i<n; i++){
      int count=1;
      vector<P> cs;
      for(int j=0; j<i; j++){
	if(eq(cross_product(ps[i]-qs[i],ps[j]-qs[j]),0)) continue;
	P c = crosspoint(ps[i],qs[i],ps[j],qs[j]);
	if(ok(c)==nowhere) continue;

	bool duplicate=false;
	for(int k=0; k<cs.size(); k++)
	  if(eqv(cs[k],c))
	    duplicate=true;
	if(!duplicate){
	  count++;
	  cs.push_back(c);
	}
      }
      ans += count;
    }

    printf("%d\n",ans);
  }
}