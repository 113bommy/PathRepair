#include<bits/stdc++.h>
using namespace std;
typedef pair<int,long long> PA;
int main(){
  int n,m,k,s,p,q;
  int a,b,c[100001];
  cin >> n >> m >> k >> s;
  cin >> p >> q;
  int town[100001];
  bool zo[100001] = {false};
  fill(town,town+100001,p);
  town[1] = 0;
  town[n] = 0;
  for(int i=0;i<k;i++){
    cin >> c[i];
    zo[ c[i] ] = true;
  }
  vector<int> vec[100001];
  for(int i=0;i<m;i++){
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  queue<PA> que;
  for(int i=0;i<k;i++){
    bool now[100001] = {false};
    now[ c[i] ] = true;
    que.push(PA(c[i],0));
    while(!que.empty()){
      PA pa = que.front();
      que.pop();
      if(pa.second >= s) continue;
      for(int j=0;j<vec[pa.first].size();j++){
	if(now[vec[pa.first][j]] == true || zo[vec[pa.first][j]] == true || vec[pa.first][j] == 1 || vec[pa.first][j] == n)
	  continue;
	town[ vec[pa.first][j] ] = q;
	now[ vec[pa.first][j] ] = true;
	que.push(PA(vec[pa.first][j],pa.second+1));
      }
    }
  }
  priority_queue<PA,vector<PA>,greater<PA> > pq;
  long long min_cost[100001];
  fill(min_cost,min_cost+100001,LLONG_MAX);
  min_cost[1] = 0;
  pq.push(PA(1,0));
  while(!pq.empty()){
    PA pa = pq.top();
    pq.pop();
    for(int i=0;i<vec[pa.first].size();i++){
      int next = vec[pa.first][i];
      int next_cost = pa.second + town[pa.first];
      if(min_cost[next] > next_cost && zo[next] == false){
	min_cost[next] = next_cost;
	pq.push(PA(next,next_cost));
      }
    }
  }
  cout << min_cost[n] << endl;
  return (0);
}