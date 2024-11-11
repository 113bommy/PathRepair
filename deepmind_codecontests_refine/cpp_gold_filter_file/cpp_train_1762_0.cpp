#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P; //Point
typedef pair<P,P> L; //Line, Segment

const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
namespace std {
  bool operator < (const P& a, const P& b){
    return fabs(real(a)-real(b)) < EPS ? imag(a) < imag(b) : real(a) < real(b);
  }
}

double dot(P a, P b){ return real(conj(a)*b); }
double cross(P a, P b){ return imag(conj(a)*b); }
int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1;   // ????????????(b-a)????????´???????????????(c-a)????????¨?????????
  if(cross(b,c) < -EPS) return -1; // ????????????(b-a)????????´???????????????(c-a)????????¨?????????
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}

P crossPoint(L l, L m){
  double A = cross(l.second - l.first, m.second - m.first);
  double B = cross(l.second - l.first, l.second - m.first);
  if(fabs(A) < EPS && fabs(B) < EPS) return m.first;
  else if(fabs(A) >= EPS) return m.first + B / A * (m.second - m.first);
}

vector<P> convex_cut(vector<P> G, L l){
  vector<P> res;
  for(int i=0;i<G.size();i++){
    P A = G[i];
    P B = G[(i+1)%G.size()];
    if(ccw(l.first, l.second, A) != -1) res.push_back(A);
    if(ccw(l.first, l.second, A) * ccw(l.first, l.second, B) < 0)
      res.push_back(crossPoint(L(A,B), l));
  }
  return res;
}

bool check(vector<P> G,double d){
  vector<P> pol=G;
  int n=G.size();
  for(int i=0;i<n;i++){
    P a=G[i],b=G[(i+1)%n],c=(b-a);
    b=P(abs(c),d)*(c/abs(c))+a;
    a=b-c;
    pol=convex_cut(pol,L(a,b));
    if(pol.size()<3)return 0;
  }
  return  1;
}


int main(){
  int n;
  while(cin>>n,n){
    vector<P> pol(n);
    for(int i=0,x,y;i<n;i++){
      cin>>x>>y;
      pol[i]=P(x,y);
    }
    double L=0,M,R=1e4;
    while(L<R){
      M=(L+R)/2;
      if(!check(pol,M)) R=M-EPS;
      else L=M+EPS;
    }
    printf("%lf\n",L);
  }
  return 0;
}