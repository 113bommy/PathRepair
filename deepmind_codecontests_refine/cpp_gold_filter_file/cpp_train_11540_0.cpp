#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i =1; i <= (int)(n);++i)
int par[60];
void init(int n){
   rep1(i,n)
     par[i]=i;  
}
int find(int x){
   if(par[x]==x)
     return x;
   else
     return par[x]=find(par[x]); 
}
void unite(int x,int y){
   x=find(x);
   y=find(y);
   if(x==y)
     return;
   par[x]=y; 
}
bool same(int x,int y){
   return find(x)==find(y);
}
int main(){
  int n,m,c=0;
  cin>>n>>m;
  int p[m][2];
  rep(i,m)
     cin>>p[i][0]>>p[i][1];
  rep(i,m){
    init(n);
    rep(j,m)
      if(i!=j)
        unite(p[j][0],p[j][1]);
    rep1(j,n)
      if(!same(1,j)){
         c++;
         break; 
      }
  }
  cout<<c;
  return 0;
}