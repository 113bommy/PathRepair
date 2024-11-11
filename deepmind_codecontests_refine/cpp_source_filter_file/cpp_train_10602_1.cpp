#include<bit/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  int ans=1;
while(ans<=n){
  ans<<=1;
}
  ans>>=1;
  cout<<ans<<endl;
}