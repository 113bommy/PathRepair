#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}
int main(){
  int n;
  cin>>n;
  int a[100002];
  lp(i,100002){
    a[i]=1;
  }
  lp(i,n){
    int x,y;
    cin>>x>>y;
    for(int i=x;i<=y && i<=n;i++){
      a[i]+=1;
    }
  }
  int ans=0;
  lp(i,n+2){
    if(a[i]>=i) ans=i;
  }
  if(ans==0) cout<<0<<endl;
  else 
  cout<<ans-1<<endl;
  return 0;
    
}
}
