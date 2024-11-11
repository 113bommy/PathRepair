#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  int h,w;
  cin>>h>>w;
  char s[h][w];
  int black=0;
  int ans[h][w];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++) {
      cin>>s[i][j];
      ans[i][j]=-1;
      if(s[i][j]=='#') black++;
    }
  }
  if(s[0][0]=='#') {
    cout<<-1<<endl;
    return 0;
  }
  ans[0][0]=0;
  queue<int> memo;
  memo.push(0);memo.push(0);
  while(!memo.empty()){
    int y=memo.front();memo.pop();
    int x=memo.front();memo.pop();
    int dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
    for(int i=0;i<4;i++){
      int ny=y+dy[i],nx=x+dx[i];
      if(ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#') continue;
      if(ans[ny][nx]!=-1) continue;
      ans[ny][nx]=ans[y][x]+1;
      memo.push(ny);memo.push(nx);
    }
  }
  if(ans[h-1][w-1]==-1) cout<<-1<<endl;
  else cout<<h*w-1-ans[h-1][w-1]-black<<endl;
  return 0;
}
