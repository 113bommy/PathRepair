#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; string s; cin>>n>>s;

  int ans=1; char t=s[0];
  for(int i=1; i<n; ++i){
    if(t!=s[i]){t=s[i]; ++ans;}
  }
  cout<<ans<<endl;
}
