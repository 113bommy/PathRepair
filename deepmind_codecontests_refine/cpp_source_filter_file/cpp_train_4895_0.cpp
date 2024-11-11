#include<iostream>
using namespace std;
int main(){
  int n,a,mini,ans=;
  cin>>n>>mini;
  for(int i=0;i<n-1;i++){
    cin>>a;
    if(a-mini>ans)ans=a-mini;
    if(mini>a)mini=a;
  }
  cout<<ans<<endl;
  return 0;
}