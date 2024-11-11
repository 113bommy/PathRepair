#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n = 20;
  int L;cin >> L;
  WeightedGraph G(n);
  vector<int> sum(n);
  int M = 0;
  int n2 = 19;
  for(int i = 1; i < n; ++i){
    G[i-1].push_back({i,0});
    int beki = (1<<(i-1));
    sum[i]=sum[i-1]+beki;
    if(sum[i]<L){
      G[i-1].push_back({i,beki});
      M = 2*beki;
      ++n2;
    }
  }
  for(int i = n-1; i >= 0; --i){
    if(sum[i]+M<L){
      G[i].push_back({N-1,M});
      M += sum[i]+1;
      ++n2;
    }
  }
  cout << n << " " << n2 << endl;
  for(int i = 0; i < n; ++i){
    for(auto e : G[i]){
      cout << i+1 << " " << e.first+1 << " " << e.second << endl;
    }
  }
}
