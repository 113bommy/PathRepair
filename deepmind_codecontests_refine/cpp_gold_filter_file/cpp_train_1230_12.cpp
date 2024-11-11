#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int ans = 0;
  for(auto a:s){
    if(a == '+')ans++;
    else ans--;
  }
  cout<<ans<<endl;
  return 0;
}
