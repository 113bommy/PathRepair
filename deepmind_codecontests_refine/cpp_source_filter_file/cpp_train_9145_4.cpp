#include<iostream>
#include<vector>
using namespace std;
int main(){
  int k,t;
  cin>>k>>t;
  int MAX=0;
  for(int i=0;i<t;i++){
    int a;cin>>a;
    if(MAX<a) MAX=a;
  }
  int ans=2*MAX-K-1;
  if(ans<0) cout<<0<<endl;
  else cout<<ans<<endl;
}