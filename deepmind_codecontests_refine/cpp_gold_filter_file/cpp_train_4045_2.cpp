#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin>>s;
  string ans="yes";
  for(int i=1;i<s.size();i++){
    for(int j=0;j<i;j++){
      if(s[i]==s[j]){
        ans="no";
      }
    }
  }
  cout<<ans<<endl;
}