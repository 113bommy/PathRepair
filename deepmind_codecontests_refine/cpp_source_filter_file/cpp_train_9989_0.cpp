#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <cassert>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> PI;
typedef vector<int> vi;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define F first
#define S second


int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

bool app[50][50][50][50];
char lr[53][53],rr[53][53]
string ans;

main(){
  int w,h;
  while(cin>>w>>h,w|h){
    memset(app,0,6250000);
    rep(i,h)scanf(" %s %s ",lr[i],rr[i]);

    int rsx,rsy,lsx,lsy;
    rep(i,h)rep(j,w){
      if(lr[i][j]=='L')lsx=i,lsy=j;
      if(rr[i][j]=='R')rsx=i,rsy=j;
    }
    ans="No";
    queue<pair<PI,PI> > Q;
    Q.push(mp(mp(lsx,lsy),mp(rsx,rsy)));

    while(!Q.empty()){
      PI tp=Q.front().F;
      int clx,cly,crx,cry;
      clx=tp.F,cly=tp.S;
      tp=Q.front().S;Q.pop();
      crx=tp.F,cry=tp.S;
      if(lr[clx][cly]=='%' && rr[crx][cry]=='%'){
        ans="Yes";
        break;
      }
      if(lr[clx][cly]=='%' || rr[crx][cry]=='%')continue;
      app[clx][cly][crx][cry]=true;

      rep(i,4){
        int nrx=crx+dx[i],nlx=clx+dx[i],nry=cry+dy[i],nly=cly-dy[i];
        if(nrx<0 || nry<0 || nrx>=h || nry>=w || rr[nrx][nry]=='#')nrx=crx,nry=cry;
        if(nlx<0 || nly<0 || nlx>=h || nly>=w || lr[nlx][nly]=='#')nlx=clx,nly=cly;
        if(app[nlx][nly][nrx][nry])continue;
        app[nlx][nly][nrx][nry]=true;
        Q.push(mp(mp(nlx,nly),mp(nrx,nry)));
      }
/*      
      rep(i,h){
        rep(j,w){
          if(clx==i && cly==j)cout<<'L';
          else if(lr[i][j]=='L')cout<<'.';
          else cout<<lr[i][j];
        }
        cout<<" ";
        rep(j,w){
          if(crx==i && cry==j)cout<<'R';
          else if(rr[i][j]=='R')cout<<'.';
          else cout<<rr[i][j];
        }
        cout<<endl;
      }
      cout<<endl;
*/
    }
    cout<<ans<<endl;
  }
}