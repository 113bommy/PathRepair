#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)
typedef pair< int , int > P;
typedef pair< int , P > Pi;
int m,n,k,d;
vector<int> cal;
struct Edge {
  int to,cost;
  Edge(){}
  Edge(int to,int cost):to(to),cost(cost){};
};
vector< Edge > Graph[110];
int min_cost[110][1<<6];
int Bellman_Ford(){
  int ret = INF;
  fill_n(*min_cost,110*(1<<6),INF);
  min_cost[0][(1<<m)-1] = true;
  queue<Pi> que;
  que.push(Pi(0,P(0,(1<<m)-1)));
  while(!que.empty()){
    Pi p = que.front();
    que.pop();
    //int cost = p.first;
    //int now = p.second.first;
    //int bit = p.second.second;
    if(p.second.first == 1) ret = min(ret,p.first);
    if(min_cost[p.second.first][p.second.second] < p.first) continue;
    for(int i=0;i<Graph[p.second.first].size();i++){
      Edge e = Graph[p.second.first][i];
      int nc = p.first + e.cost*k;
      int bit = p.second.second;
      if(e.to >= 2 && e.to < 2 + m){
	if((bit >> (e.to-2)) & 1){
	  nc -= cal[e.to-2];
	  bit &= ~(1 << (e.to-2));
	} else continue;
      }
      if(nc < min_cost[e.to][bit]){
	que.push(Pi(nc,P(e.to,bit)));
	min_cost[e.to][bit] = nc;
      }
    }
  }
  return ret;
}

int judge(string s){
  if(s == "H") return 0;
  else if(s == "D") return 1;
  else if(s[0] == 'C') return atoi(s.substr(1).c_str())+1;
  else if(s[0] == 'L') return atoi(s.substr(1).c_str())+m+1;
}

int main(){
  while(cin >> m >> n >> k >> d , m){
    cal.resize(m);
    for(int i=0;i<m;i++) cin >> cal[i];
    for(int i=0;i<d;i++){
      string s1,s2; int dis;
      cin >> s1 >> s2 >> dis;
      Graph[judge(s1)].push_back(Edge(judge(s2),dis));
      Graph[judge(s2)].push_back(Edge(judge(s1),dis));
    }
    cout << Bellman_Ford() << endl;
    for(int i=0;i<110;i++) Graph[i].clear();
  }
}