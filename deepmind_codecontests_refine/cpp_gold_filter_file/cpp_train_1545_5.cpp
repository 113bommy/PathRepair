#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,ans=0;
  map<string,int>m;
  cin>>a;
  while(a--){
   string s;
    cin>>s;
    m[s]++;
  }
  cin>>b;
  while(b--){
   string s;
    cin>>s;
    m[s]--;
  }
  map<string,int>::iterator it=m.begin();
  for(;it!=m.end();it++){
    ans=max(ans,(*it).second);
  }
  cout<<ans<<endl;
}