#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct RQ {
 using RQV = LL;
 using RQRV = LL;
 static RQV Zero(){ return 0; }
 static RQRV RZero(){ return 0; }
 // addition
 static RQV f(RQV a,RQV b){ return max(a,b); }
 // update function
 static void uf(RQV& a,RQV b){ a = b; }
 // effect of range queries n-sized
 static void ef(RQV& a,RQRV b,int n){  }
 // range query update
 static void ruf(RQRV& a,RQRV b){  }
 // comparation
 static bool cmp(RQV l,RQV r){ return l<=r; }
 struct Node{
  RQV v; RQRV r;
 };
 int N;
 vector<Node> V;

 void init(int n){
  N=1; while (N<n) N*=2;
  V.assign(N*2,{Zero(),RZero()});
 }

 void spread(int i,int z){
  if (z!=1) {
   ef(V[i*2].v,V[i].r,z/2);
   ruf(V[i*2].r,V[i].r);
   ef(V[i*2+1].v,V[i].r,z/2);
   ruf(V[i*2+1].r,V[i].r);
  }
  V[i].r = RZero();
 }

 void upd(int p,RQV v){
  for(int d=N; d>=1; d/=2) spread(p/d,d);
  p+=N; uf(V[p].v,v);
  int z=1;
  while(p!=1){
   p/=2; z*=2;
   V[p].v = f(V[p*2].v,V[p*2+1].v);
   ef(V[p].v,V[p].r,z);
  }
 }

 void updr(int l,int r,RQRV v,int a=0,int b=0,int i=-1){
  if(i==-1){ a=0; b=N; i=1; }
  spread(i,b-a);
  if(r<=a || b<=l) return;
  if(l<=a && b<=r){
   ruf(V[i].r,v);
   ef(V[i].v,V[i].r,b-a);
   return;
  }
  updr(l,r,v,a,(a+b)/2,i*2);
  updr(l,r,v,(a+b)/2,b,i*2+1);
  V[i].v = f(V[i*2].v,V[i*2+1].v);
  ef(V[i].v,V[i].r,b-a);
 }

 RQV query(int l,int r,int a=0,int b=0,int i=-1){
  if(i==-1){ a=0; b=N; i=1; }
  if(r<=a || b<=l) return Zero();
  if(l<=a && b<=r) return V[i].v;
  RQV q1 = query(l,r,a,(a+b)/2,i*2);
  RQV q2 = query(l,r,(a+b)/2,b,i*2+1);
  q1 = f(q1,q2);
  ef(q1,V[i].r,min(r,b)-max(l,a));
  return q1;
 }

 int find(int l,RQV v,int a=0,int b=0,int i=-1){
  static RQV x;
  if(i==-1){ a=0; b=N; i=1; x=Zero(); }
  spread(i,b-a);
  if(b<=l) return N;
  if(l<=a && !cmp(v,f(x,V[i].v))){ x=f(x,V[i].v); return N; }
  if(b-a==1) return a;
  int q1 = find(l,v,a,(a+b)/2,i*2);
  if(q1!=N) return q1;
  return find(l,v,(a+b)/2,b,i*2+1);
 }
};

int N,Q;
RQ G;

int main(){
 scanf("%d%d",&N,&Q);
 G.init(N);
 rep(i,N){
  int a; scanf("%d",&a);
  G.upd(i,a);
 }
 rep(q,Q){
  int c; scanf("%d",&c);
  if(c==1){
   int x,v; scanf("%d%d",&x,&v); x--;
   G.upd(x,v);
  }
  if(c==2){
   int l,r; scanf("%d%d",&l,&r); l--;
   printf("%lld\n",G.query(l,r));
  }
  if(c==3){
   int x,v; scanf("%d%d",&x,&v); x--;
   printf("%d\n",min(G.find(x,v),N)+1);
  }
 }
 
 return 0;
}
