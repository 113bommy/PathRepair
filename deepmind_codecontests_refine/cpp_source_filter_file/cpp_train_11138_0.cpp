#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(){
  int n,a;
  cin>>n>>a;
  int memo;
  int ans=0;
  lp(i,n){
    cin>>memo;
    else if(memo>a) ans+=memo-a;
  }
  if(ans<=0) cout<<"kusoge"<<endl;
  else cout<<ans<<endl;
  return 0;
}

