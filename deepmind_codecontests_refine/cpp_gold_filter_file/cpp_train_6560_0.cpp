#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;
typedef vector<P> vec;

double eps=1e-5;
bool eq(double a,double b){return (b-a<eps&&a-b<eps);}
double dot(P a,P b){return real(b*conj(a));}
double cross(P a,P b){return imag(b*conj(a));}
P project(P a,P b,P c){b-=a;c-=a;return a+b*real(c/b);}
P reflect(P a,P b,P c){b-=a;c-=a;return a+conj(c/b)*b;}
int ccw(P a,P b,P c){
  b-=a,c-=a,a=c*conj(b);
  if(a.imag()>eps)return 1;//ccw
  if(a.imag()<-eps)return -1;//cw
  if(a.real()<-eps)return 2;//ob
  if(abs(b)+eps<abs(c))return -2;//of
  return 0;//os
}

//segment ab , point c
double dist(P a,P b,P c){
  if(dot(b-a,c-a)<0)return abs(c-a);
  if(dot(a-b,c-b)<0)return abs(c-b);
  return abs(cross(b-a,c-a))/abs(b-a);
}

bool isintersect(P a,P b,P c,P d){
  return ((ccw(a,b,c)*ccw(a,b,d)<=0)&&(ccw(c,d,a)*ccw(c,d,b)<=0));
}

//segment ab , segment cd
P intersect(P a,P b,P c,P d){
  a-=d;b-=d;c-=d;
  return d+a+(b-a)*imag(a/c)/imag(a/c-b/c);
}

double dist(P a,P b,P c,P d){
  if(isintersect(a,b,c,d))return 0;
  double ab=min(dist(a,b,c),dist(a,b,d));
  double cd=min(dist(c,d,a),dist(c,d,b));
  return min(ab,cd);
}

double calcArea(vec &t){
  double res=0;
  int n=t.size();
  for(int i=0;i<n;i++)res+=cross(t[i],t[(i+1==n?0:i+1)]);
  return abs(res/2.0);
}


double Arg(P a,P b,P c){
  b-=a,c-=a;
  double res=acos( max(-1.0,min(1.0,dot(b,c)/abs(b)/abs(c))) );
  if(cross(b,c)<0)res*=-1.0;
  return res;
}

int inPolygon(vec &t,P p){
  int n=t.size();
  double sum=0;
  for(int i=0;i<n;i++){
    P a=t[i],b=t[(i+1==n?0:i+1)];
    if( ccw(a,b,p) == 0 )return 1;
    sum+= Arg(p,a,b);
  }
  if( abs(sum) < 0.5 )return 0;
  else  return 2;
}

int main(){
  int n;
  cin>>n;
  vec t;
  double x,y;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    t.push_back(P(x,y));
  }
  int q;
  cin>>q;
  while(q--){
    cin>>x>>y;
    cout<<inPolygon(t,P(x,y))<<endl;
  }

  return 0;
}