#include<bits/stdc++.h>
using namespace std; 
#define int long long
int N,a[110000];
signed main(){
  cin>>N;
  int ans=0,m=INT_MAX,minus=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    ans+=abs(a[i]);
    m=min(m,abs(a[i]));
    minus+=(a[i]<0);
  }
  if(minus&1)ans-=m*2;
  cout<<ans<<endl;
}
