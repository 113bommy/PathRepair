#include<bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  string ans;
  for(int i=0;i<s.size();i++){
    if(s[i]=='B'){
      if(!ans.empty())ans.pop_back();
    }else ans.push_back(s[i]);
  }
  cout<<ans<<endl;
}
