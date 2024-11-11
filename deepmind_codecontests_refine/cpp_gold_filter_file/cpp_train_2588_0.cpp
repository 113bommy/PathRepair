#include <bits/stdc++.h>
using namespace std;

int64_t a,b,H,W;
int64_t cnt[10];
map<pair<int64_t, int64_t>, int64_t> mp;
int N,i,j,k;
int64_t sm;
int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // ifstream in("input.txt");
  // cin.rdbuf(in.rdbuf());

  cin>>H>>W>>N;
  for(i=0;i<N;i++){
    cin>>a>>b;
    a--;b--;
    for(j=-2;j<=0;j++){
      for(k=-2;k<=0;k++){
        if(a+j<0 || a+j+2>H-1 || b+k<0 || b+k+2>W-1)continue;
        mp[make_pair(a+j, b+k)]++;
      }
    }
  }
  sm = (H - 2) * (W - 2);
  for(auto itr=mp.begin(); itr!=mp.end();++itr){
    for(i=1;i<=9;i++){
      if((itr->second)==i)cnt[i]++;
    }
  }
  for(i=1;i<=9;i++){
    sm-=cnt[i];
  }
  cnt[0]=sm;
  for(i=0;i<=9;i++)cout<<cnt[i]<<endl;
  return 0;
}