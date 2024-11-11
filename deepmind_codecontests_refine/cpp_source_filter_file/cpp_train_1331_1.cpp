##include<bits/stdc++.h>
using namespace std;
int main(void){
  int h,w; cin>>h>>w;
  vector<string> s(h);
  for(auto& i:s) cin>>i;
  queue<pair<int,pair<int,int>>> q;
  int res=0;
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    vector<vector<bool>> z(h,vector<bool>(w,false));
    if(s[i][j]=='.') q.push({i,{j,0}});
    while(!q.empty()){
      int x=q.front().first;
      int y=q.front().second.first;
      int cnt=q.front().second.second;
      q.pop();
      if(z[x][y]==true) continue; else z[x][y]=true;
      if(x>0) if(s[x-1][y]=='.') q.push({x-1,{y,cnt+1}});
      if(y>0) if(s[x][y-1]=='.') q.push({x,{y-1,cnt+1}});
      if(x<h-1) if(s[x+1][y]=='.') q.push({x+1,{y,cnt+1}});
      if(y<w-1) if(s[x][y+1]=='.') q.push({x,{y+1,cnt+1}});
      res=max(res,cnt);
    }
  }
  cout<<res;
  return 0;
}