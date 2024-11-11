#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h,w;
char s[400][400];
bool used[400][400];
ll dcnt = 0;
ll dx[] = {1,0,-1,0}, dy[] = {0, 1, 0 ,-1};
ll dfs(ll x, ll y){
  if(used[x][y]) return 0;
  ll ret = 0;
  used[x][y] = true;
  if(s[x][y] == '.') ret++;
  else dcnt++;
  for(ll i=0;i<4;i++){
    if(x+dx[i] < 0 || y+dy[i] < 0 || x+dx[i] >=h || y+dy[i] >= w) continue;
    if(s[x+dx[i]][y+dy[i]] != s[x][y])
      ret += dfs(x+dx[i], y+dy[i]);
  }
  return ret;
}

ll main(){
  cin >> h >> w;
  
  for(ll x=0;x<h;x++){
    for(ll y=0;y<w;y++){
      cin >> s[x][y];
      used[x][y] = false;
    }
  }
  ll ans = 0;
  for(ll x=0;x<h;x++){
    for(ll y=0;y<w;y++){
      if(s[x][y] == '#'){
        // cout << "x: " << x << " y: " << y << " start" << endl;
        dcnt = 0;
        ll tmp = dfs(x,y);
        ans += tmp*dcnt;
      }
    }
  }

  cout << ans << endl;

}