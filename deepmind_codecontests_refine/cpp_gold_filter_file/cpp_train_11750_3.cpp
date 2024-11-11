#include<iostream>
#include<string>
using namespace std;

int main(){
  string s; cin>>s;
  long long ans=0,t;
  for(int i=0;i<(1<<(s.size()-1));i++){
    t=s[0]-'0';
    for(int j=0;j<s.size();j++){
      if(j==s.size()-1||i&1<<j){
        ans+=t;
        t=0;
      }
      t*=10;
      t+=s[j+1]-'0';
    }
  }
  cout<<ans<<endl;
  return 0;
}
