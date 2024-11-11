#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  int n,m,a,b;
  cin>>n>>m;
  vector<int> to[100005];
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--;
    b--;
   to[a].push_back(b);
    to[b].push_back(a);
  }
  queue<int> q;
  vector<int> dist(n,100005);
  vector<int> pre(n,-1);
  dist[0]=0;
  q.push(0);
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int u:to[v]){
      if(dist[u]!=100005) continue;
      dist[u]=dist[v]+1;
      pre[u]=v;
      q.push(u);
    }
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<n;i++){
    int ans=pre[i];
    ans++;
    cout<<ans<<endl;
  }
  return 0;
}
