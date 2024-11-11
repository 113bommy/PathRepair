#include <bits/stdc++.h>
using namespace std;

int N,M,ans;
vector<int> visit;
vector<set<int> > adj;

void dfs(int i){
  visit[i]=1;
  for(int a:adj[i]) if(visit[a]==0) dfs(a);
}

int main(){
  cin >> N >> M;
  visit.resize(n+1);
  adj.resize(n+1);
  for(int i=0; i<M; ++i){
    int x,y,z; cin >> x >> y >> z;
    adj[x].insert(y);
    adj[y].insert(x);
  }

  for(int i=1; i<=N; ++i){
    if(visit[i]==0){
      ++ans;
      dfs(i);
    }
  }

  cout<<ans<<endl;
}
