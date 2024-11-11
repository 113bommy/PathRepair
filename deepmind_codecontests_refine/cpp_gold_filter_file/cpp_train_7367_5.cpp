#include<bits/stdc++.h>
using namespace std;
int main(){
  int l,r,d,ans=0;
  cin>>l>>r>>d;
  for(int i=l;i<=r;i++){
    if(i%d==0)ans++;
  }
  cout<<ans;
}
