#include <bits/stdc++.h>
using namespace std;

int main(){
  int w,h,n,l=0,d=0;
  cin>>w>>h>>n;
  for(int i=0; i<n; i++){
    int x,y,a;
    cin>>x>>y>>a;
    if(a==1) l=max(x,l);
    if(a==2) w=min(x,w);
    if(a==3) d=max(y,d);
    if(a==4) h=min(y,h);
  }
  if(w-l<=0 || h-d<=0) cout<<0;
  else cout<<(w-l)*(h-d);
}