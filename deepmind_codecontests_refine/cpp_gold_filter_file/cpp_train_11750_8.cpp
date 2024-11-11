#include<iostream>
#include<string>
typedef long long ll;
using namespace std;
int main(){
  string s;
  cin>>s;
  ll ans=0;
  int n=s.size();
  
  for(int bit=0;bit<(1<<n-1);bit++){
    string ss="";
    for(int i=0;i<n;i++){
      ss+=s[i];
      if(bit>>i&1){
        ans+=stoll(ss);
        ss="";
      }
    }
    ans+=stoll(ss);
    ss="";
  }
  cout<<ans<<endl;
  return 0;
}
