g#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int H,W;
  while(cin>>H>>W){
    if(H==0) break;
    vector<string> grid(H);
    int sum[501][501] = {0};
    REP(i,H){
      cin>>grid[i];
    }
    REP(y,H)REP(x,W){
      sum[y+1][x+1] = sum[y+1][x] + sum[y][x+1] - sum[y][x];
      sum[y+1][x+1] += (grid[y][x]=='*')?1:0;
    }
    int ans=0;
    /*
    REP(y1,H)REP(x1,W)FOR(y2,y1+1,H)FOR(x2,x1+1,W){
      if(sum[x2+1][y2+1]-sum[x1][y2+1]
          -sum[x2+1][y1]+sum[x1][y1]==0){
        ans = max((x2-x1+1)*(y2-y1+1),ans);
      }
    }
    */
    bool f = false;
    FOR(dy,1,H+1){
      FOR(dx,1,W+1){
        f = false;
        FOR(y,dy-1,H){
          FOR(x,dx-1,W){
            if(sum[y+1][x+1]-sum[y+1-dy][x+1]
                -sum[y+1][x+1-dx] + sum[y+1-dy][x+1-dx]==0){
              f = true;
              break;
            }
          }
          if(f) break;
        }
        if(f) ans = max(ans,dx*dy);
        else break;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}