#include <bits/stdc++.h>
#define EPS (1e-10)
using namespace std;
 
typedef complex<double> P; //Point
typedef pair<P,P> L; //Line, Segment
 
 
namespace std {
  bool operator < (const P& a, const P& b){
    return fabs(real(a)-real(b)) < EPS ? imag(a) < imag(b) : real(a) < real(b);
  }
  bool operator ==(const P& a, const P& b){
    return abs(a.real()-b.real())<EPS&&abs(a.imag()-b.imag())<EPS;
  }
}
 
double dot(P a, P b){ return real(conj(a)*b); }
double cross(P a, P b){ return imag(conj(a)*b); }
 
int ccw(P a, P b, P c){
  b -= a;
  c -= a;
  if(cross(b,c) > EPS) return 1;   // ????????????(b-a)?????????´???????????????(c-a)?????????¨?????????
  if(cross(b,c) < -EPS) return -1; // ????????????(b-a)?????????´???????????????(c-a)?????????¨?????????
  if(dot(b,c) < -EPS) return 2;
  if(norm(b) < norm(c)) return -2;
  return 0;
}
 
bool isIntersect(L s1, L s2){  
  return ( ccw(s1.first,s1.second,s2.first) * ccw(s1.first,s1.second,s2.second) <= 0 &&
           ccw(s2.first,s2.second,s1.first) * ccw(s2.first,s2.second,s1.second) <= 0 );
}
 
P crossPoint(L l, L m){
  double A = cross(l.second - l.first, m.second - m.first);
  double B = cross(l.second - l.first, l.second - m.first);
  if(fabs(A) < EPS && fabs(B) < EPS) return m.first;
  else if(fabs(A) >= EPS) return m.first + B / A * (m.second - m.first);
}
 
bool onEdge(P a){return a.real()==-100||a.real()==100||a.imag()==-100||a.imag()==100;}
 
int Unique(vector<P> &p){
  int res=0;
  for(int i=0;i<(int)p.size();i++){
    int flg=1;
    for(int j=i+1;j<(int)p.size();j++) if(p[i]==p[j]) flg=0;
    res+=flg;
  }  
  return res;
}
 
int main(){
  int n;
  while(cin>>n,n){
    int ans=1;
    vector<L> v;
     
    for(int i=0;i<n;i++){
      int sx,sy,gx,gy;
      cin>>sx>>sy>>gx>>gy;
      L l=L(P(sx,sy),P(gx,gy));
       
      vector<P> p;
      for(int i=0;i<v.size();i++){
    if(!isIntersect(l,v[i]))continue;
    P cp=crossPoint(l,v[i]);
    if(!onEdge(cp))p.push_back(cp);
      }
      ans+=1+Unique(p);
      v.push_back(l);
    }  
    cout<<ans<<endl;
  }
  return 0;