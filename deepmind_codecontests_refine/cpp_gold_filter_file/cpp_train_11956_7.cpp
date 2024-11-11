#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k; cin>>n >>k;
  int ans=0;
  for(int i=0;i<n;i++){
    int x; cin>>x;
    ans+=min(2*abs(x-k),2*x);
  }
  cout<<ans<<endl;
}