#include<bits/stc++.h>
#define int long long
using namespace std;

signed main(){
  int n,k,x,y,cnt=0;
  cin>>n>>k;
  k*=k;
  while(n--){
    cin>>x>>y;
    x*=x;
    y*=y;
    if(k>=x+y) cnt++;
  }
  cout<<cnt<<endl;
}