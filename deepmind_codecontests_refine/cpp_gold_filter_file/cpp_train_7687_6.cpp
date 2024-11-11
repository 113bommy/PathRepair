#include<bits/stdc++.h>
using namespace std;
bool flag[10];
int N,M;
vector<vector<int>>G;
int rec(int now){
  flag[now]=true;
  int cnt=0;
  for(int i=1;i<=N;i++){
    if(!flag[i])break;
    cnt++;
  }
  if(cnt==N)return 1;
  int ans=0;
  for(auto e:G[now]){
    if(!flag[e]){
      ans+=rec(e);
      flag[e]=false;
    }
  }
  return ans;
}
int main(){
  cin>>N>>M;
  G.resize(N+1);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cout<<rec(1)<<endl;
}
