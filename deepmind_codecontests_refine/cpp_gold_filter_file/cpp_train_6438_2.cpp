#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int> a;
  pair<int,int> pe[M];
  map<int,int> mp;
  for(int i=0;i<M;i++){
    int p,q;
    cin >> p >> q;
    pe[i]=make_pair(p,q);
    if(p==1)mp[q]++;
  }
  for(int i=0;i<M;i++){
    if(pe[i].second==N)mp[pe[i].first]++;
  }
  bool ans=false;
  for(auto x:mp){
    if(x.second==2)ans=true;
  }
  if(ans)cout << "POSSIBLE";
  else cout << "IMPOSSIBLE";
}




