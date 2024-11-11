#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=1000;
  for(int j=0;j<s.size()-3;j++){
    int k=100*(int)(s.at(i)-'0')+10*(int)(s.at(i+1)-'0')+(int)(s.at(i+2)-'0');
    ans=min(ans,abs(753-k));
  }
  cout<<ans;
}
