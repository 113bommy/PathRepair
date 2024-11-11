#include <bits/stdc++.h>
using namespace std;

int main(){
  int D,r,ans;
  cin>>r>>D>>ans;
  for(int i=0;i<10;i++){
    ans=r*ans-D;
    cout<<ans<<endl;
  }
}