#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;cin>>n>>m;
  vector<int> edge[n],ans(n,-1);
  while(m--){
    int u,v;cin>>u>>v;u--;v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  queue<int>que;
  que.push(0);
  while(que.size()){
    int p=que.front();que.pop();
    for(int q:edge[p])
      if(!~ans[q]){
        ans[q]=p;
        que.push(q);
      }
  }
  cout<<"Yes"<<endl;
  for(int i=1;i<n;i++)cout<<ans[i]+1<<endl;
}
