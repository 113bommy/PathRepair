#include<iostream>
using namespace std;
int main(){
  int n,t;
  cin>>n>>t;
  int c[1010],a[1010],ans=1010;
  for(int i=0;i<n;i++){
    cin>>c[i]>>a[i];
    if(a[i]<=t){
      if(c[i]<ans)ans=c[i];
    }
  }
  if(ans==1010)cout<<"TLE"<<endl;
  else cout<<ans<<endl;
}