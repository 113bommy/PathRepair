#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<pair<int,int>> mp;
  vector<pair<int,int>> pe(N);
  for(int i=0;i<N;i++){
    int x,y;
    cin >> x >> y;
    pe[i]=make_pair(x,y);
  }
  sort(pe.begin(),pe.end());
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      pair<int,int> p=make_pair(pe[i].first-pe[j].first,pe[i].second-pe[j].second);
      mp[p]++;
    }
  }
  int mc=0;
  for(auto p:mp){
    if(p.second>mc)mc=p.second;
  }
  cout << N-mc;
}




