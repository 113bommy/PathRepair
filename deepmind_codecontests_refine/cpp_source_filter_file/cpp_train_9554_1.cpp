#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int H,W,M;
  cin >> H >> W >> M;

  vector<int> g(H),r(W);
  map<pair<int,int>,int> mp;
  int gm = 0,rm = 0;
  
  for(int i = 0;i < M;i++) {
    int h,w;
    cin >> h >> w;
    g[h-1]++;
    r[w-1]++;
    mp[make_pair(h-1,w-1)]++;
    gm = max(gm,g[h-1]);
    rm = max(rm,r[w-1]);
  }
  
  vector<int> cg(0),cr(0);
  for(int i = 0;i < H;i++) {
    if(g[i] == gm) cg.push_back(i);
  }


  for(int i = 0;i < W;i++) {
    if(r[i] == rm) cr.push_back(i);
  }
  
  

  int ans = 0;
  for(int G:cg) {
    for(int R:cr) {
      ans = max(ans,gm+rm-mp[make_pair(G,R)]);
      if(mp[make_pair(G,R) == 0]) break;
    }
  }

  cout << ans << endl;



}
