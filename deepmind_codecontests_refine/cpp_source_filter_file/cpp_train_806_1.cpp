#include <iostream>
using namespace std;
typedef long long int ll;
int main(){
  int n;cin>>n;
  ll a[n] , ma =0 , ans =0;
  for (int i=0;i<n;++i){cin>>a[i];ans+=max(0ll,ma-a[i]);ma = max(ma,ans[i]);}
  cout<<ans;
  
}