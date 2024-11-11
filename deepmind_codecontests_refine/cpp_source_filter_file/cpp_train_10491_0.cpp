#include<bits/stdc++.h>
using namespace std;
long MOD=1e9+7,n,k,ans=1,l,r,flg=1,a[1<<18],x,y;
int main(){
  cin>>n>>k;
  r=n-1;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  if(k%2)ans=a[r],r--,k--,flg=(ans<0?-1:1);
  while(k){
    x=a[l]*a[l+1],y=a[r]*a[r-1];
    if(x*flg>y*flg)ans*=x%MOD,ans%=MOD,l+=2;
    else ans*=y%MOD,ans%=MOD,r-=2;
    k-=2;
  }
  cout<<(ans%MOD+MOD)%MOD)<<endl;
}
