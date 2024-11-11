#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  string cur="";
  string pre="";
  int ans=0;
  for(int i=0;i<s.length();i++){
    cur+=s[i];
    if(prev!=cur){
       prev=cur;
       cur="";
       ans++;
    }
  }
  cout<<ans;
}
     