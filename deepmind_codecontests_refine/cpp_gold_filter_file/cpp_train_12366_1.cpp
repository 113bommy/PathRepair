#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main(){
  int h,w,K,ans=1e9;cin>>h>>w>>K;
  vector<string> s(h);
  REP(i,h)cin>>s[i];
  REP(bit,1<<(h-1)){
    vector<int> v;
    REP(i,h-1)if((bit>>i)&1)v.push_back(i);
    int res=v.size(),n=v.size()+1;
    vector<int> cnt(n,0),tmp(n,0);
    REP(x,w){
      int now=0;
      REP(y,h){
        tmp[now]+=s[y][x]=='1';
        if(now<v.size()&&v[now]==y)now++;
      }
      REP(j,n)if(tmp[j]>K)x=res=1e9;
      bool f=true;
      REP(j,n)if(cnt[j]+tmp[j]>K)f=false;
      REP(j,n)cnt[j]=cnt[j]*f+tmp[j],tmp[j]=0;
      res+=!f;
    }
    if(ans>res)ans=res;
  }
  cout<<ans<<endl;
}