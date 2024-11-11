#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  using pii = pair<int,int>;
  int H, W;
  cin >> H >> W;
  char A[H][W];
  queue<pii> que;
  int d[H][W];
  rep(i, H) {
    rep(j, W) {
      cin >> A[i][j];
      if(A[i][j]=='#') que.push(pii(i,j));
      d[i][j]=0;
    }
  }
  int dy[4]={-1,0,1,0},dy[4]={0,1,0,-1};
  int ans=0;
  while(que.size()) {
    pii p=que.front();
    que.pop();
    rep(i,4) {
      int ny=p.first+dy[i], nx=p.second+dx[i];
      if(0<=ny&&ny<H&&0<=nx&&nx<W&&A[ny][nx]=='.'&&d[ny][nx]==0) {
        que.push(pii(ny,nx));
        d[ny][nx]=d[p.first][p.second]+1;
        ans=max(ans, d[ny][nx]);
      }
    }
  }
  cout << ans << endl;
}