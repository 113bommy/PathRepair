#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using llong = long long;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int,llong>>> graph(n);
  for(int i=0;i<m;++i){
    int a,b;
    llong c;
    cin >> a >> b >> c;
    graph[a-1].emplace_back(b-1,-c);
  }

  llong INF = 100000000000000000;
  vector<llong> dist(n,INF);
  dist[0] = 0;
  for(int cnt=0;cnt<n;++cnt){
    for(int i=0;i<n;++i){
      for(const auto &p:graph[i]){
        if(dist[p.first] > dist[i] + p.second){
          dist[p.first] = dist[i] + p.second;
          if(cnt == n-1&&p.first = n-1){
            cout << "inf" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << -dist[n-1] << endl;
  return 0;
}