#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)

int main(){
  int n,t,ans,mo=0,me=0,co,ce;cin>>n;
  vector<int> ve(100001,0),vo(100001,0);
  REP(i,n){
    cin>>t;
    if(i%2){
      vo.at(t)++;
      if(vo.at(t)>mo) mo=vo.at(t),co=t;
    }else{
      ve.at(t)++;
      if(ve.at(t)>me) me=ve.at(t),ce=t;
    }
  if(co!=ce) ans=n-mo-me;
  else{
    sort(ve.begin(),ve.end(),greater<int>());
    sort(vo.begin(),vo.end(),greater<int>());
    ans=n-max(mo+ve.at(1),me+vo.at(1));
  }  
  cout<<ans;
}