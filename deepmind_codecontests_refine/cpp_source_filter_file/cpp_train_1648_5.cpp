#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin>>s>>t;
  bool ad=false;
  for(int i=0;i<s.size();i++){
    if(s==t){
      ad=true;
    }
    s=s.back()+s.substr(0.s.size()-1);
  }
  if(ad) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}