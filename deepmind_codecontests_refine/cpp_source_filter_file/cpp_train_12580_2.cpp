#include<bits/stdc++.h>
using namespace std;
int main(){
  int l[60];
  int n,k,l[i],ans=0;cin>>n>>k;
  for(int i=0;i<n;i++)cin>>l[i];
  sort(l,l+n,greater<int>());
  for(int j=0;j<k;j++){
    ans+=l[j];
  }
  cout<<ans;
}