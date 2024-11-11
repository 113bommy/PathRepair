#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)
  
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()
  
#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

double dot(P a,P b){return real(conj(a)*b);}
double cross(P a,P b){return imag(conj(a)*b);}

int main(){
  double a,b,c,d,e,f,g,h;
  while(~scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&a,&b,&c,&d,&e,&f,&g,&h)){
    P x[6];
    x[0] = P(a,b);
    x[1] = P(c,d);
    x[2] = P(e,f);
    x[3] = P(g,h);
    x[4] = x[0];
    x[5] = x[1];
    double ccw = cross(x[2]-x[0],x[1]-x[0])
    bool flag = true;
    REPR(i,4){
      double ccc = cross(x[2+i]-x[i],x[1+i]-x[i]);
      if(ccw*ccc <= 0){
        flag = false;
        break;
      }
    }
    if(flag){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  return 0;
}