#include <bits/stdc++.h>
using namespace std;

signed main(){
  int n;cin>>n;
  string s;cin>>s;
  int tmp=0;
  for(char p:s)tmp+=p=='R';
  int ans=0;
  for(int i=0;i<tmp;i++)ans+=p=='W';
  cout<<ans<<endl;
}
