#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i,n) for (int i=0;i<(n);i++)
using ll = long long;
using namespace std;
//using namespace atcoder;

int main() {
    int h,w,sy,sx,gy,gx;
    cin>>h>>w>>sy>>sx>>gy>>gx;
    sy--,sx--,gy--,gx--;
    string s[h];
    for (int i=0;i<h;i++)
        cin>>s[i];
    int dis[h][w];
    rep(i,h) rep(j,w) dis[i][j]=1e9;
    dis[sy][sx]=0;
    deque<pair<int,int>> q;
    q.push_back({sy,sx});
    int dy[]={0,0,-1,1},dx[]={-1,1,0,0};
    while (q.size()) {
        auto a=q.frons();q.pop_front();
        int y=a.first,x=a.second;
        rep(i,4) {
            int ny=y+dy[i],nx=x+dx[i];
            if (0<=ny&&ny<h&&0<=nx&&nx<w&&s[ny][nx]=='.'&&dis[y][x]<dis[ny][nx]) {
                dis[ny][nx]=dis[y][x];
                q.push_front({ny,nx});
            }
        }
        for (int i=-2;i<=2;i++) for (int j=-2;j<=2;j++) {
            int ny=y+i,nx=x+j;
            if (0<=ny&&ny<h&&0<=nx&&nx<w&&s[ny][nx]=='.'&&dis[y][x]+1<dis[ny][nx]) {
                dis[ny][nx]=dis[y][x]+1;
                q.push_back({ny,nx});
            }
        }
    }
    if (dis[gy][gx]==1e9)
        cout<<-1<<endl;
    else
        cout<<dis[gy][gx]<<endl;
    return 0;
}