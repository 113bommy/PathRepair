#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,K;
  cin>>n>>K;
  int x,ans;
  ans=0;
  for (int i=0;i<n;i++){
    cin>>x;
    ans+=min(2*x,2*(K-x));
  }
  cout<<ans<<endl
}
      