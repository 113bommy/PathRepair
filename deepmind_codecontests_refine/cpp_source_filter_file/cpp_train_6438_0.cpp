#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,m,y,x;
vector<int>v[200001];
bool used[200001];
void dfs(int to,int depth){
  if(depth==2)return;
  rep(i,v[to].size()){
    int x=v[to][i];
    if(!used[x]){
      used[x]=1;
      dfs(x,d+1);
    }
  }
}
main(){
  cin>>n>>m;
  rep(i,m){
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1,0);
  if(used[n])cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}