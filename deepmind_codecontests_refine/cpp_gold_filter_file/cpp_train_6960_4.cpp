#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int w,h,n,x,y,a;
  cin>>w>>h>>n;
  int xl=0,xr=w,yl=0,yr=h;
  for(int i=0;i<n;i++){
    cin>>x>>y>>a;
    if(a==1) xl=max(x,xl);
    else if(a==2) xr=min(x,xr);
    else if(a==3) yl=max(y,yl);
    else  yr=min(y,yr);
  }
  if(xl<xr&&yl<yr) cout<<(xr-xl)*(yr-yl)<<endl;
  else cout<<0<<endl;
  return 0;
}