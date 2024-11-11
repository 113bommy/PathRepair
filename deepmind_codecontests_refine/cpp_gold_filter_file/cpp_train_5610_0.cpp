#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
static const double EPS = 1e-8;
static const int INF = (int)1e8;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FIND(m,w) ((m).find(w)!=(m).end())
struct P{
  int tx,ty,kx,ky;
  int t;
  P(int tx,int ty,int kx,int ky,int t) : tx(tx),ty(ty),kx(kx),ky(ky),t(t) {}
};
bool operator < (P p, P q){
  return p.t > q.t;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool memo[51][51][51][51];
int main(void){
  int w,h;
  while(cin>>w>>h,w){
    memset(memo,0,sizeof(memo));
    int grid[51][51];
    int tx,ty,kx,ky;
    cin>>tx>>ty>>kx>>ky;
    tx--;ty--;kx--;ky--;
    REP(y,h)REP(x,w)cin>>grid[y][x];
    priority_queue<P> que;
    que.push(P(tx,ty,kx,ky,0));
    int ans=-1;
    while(!que.empty()){
      P p = que.top(); que.pop();
      if(memo[p.tx][p.ty][p.kx][p.ky])continue;
      memo[p.tx][p.ty][p.kx][p.ky] = true;
      if(p.t>=100){
        ans = -1;
        break;
      }
      if(p.tx==p.kx&&p.ty==p.ky){
        ans = p.t;
        break;
      }
      REP(r,4){
        int ntx = p.tx + dx[r];
        int nty = p.ty + dy[r];
        int nkx = p.kx - dx[r];
        int nky = p.ky - dy[r];
        if(!(ntx>=0&&ntx<w&&nty>=0&&nty<h&&grid[nty][ntx]==0)){
          ntx = p.tx;
          nty = p.ty;
        }
        if(!(nkx>=0&&nkx<w&&nky>=0&&nky<h&&grid[nky][nkx]==0)){
          nkx = p.kx;
          nky = p.ky;
        }
        que.push(P(ntx,nty,nkx,nky,p.t+1));
      }
    }
    if(ans==-1) cout<<"NA"<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}