#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
#define INF 1<<28
#define F first
#define S second
using namespace std;
 
int sx, sy, gx, gy;
typedef pair < int, int > P;
vector < P > p[5];
int memo[5][5][1111];

int dist(P a, P b){
  return abs(a.F - b.F) + abs(a.S - b.S);
}


int solve(int k, int t, int q){
 
  if(k == 4) return abs(p[t][q].F-gx) + abs(p[t][q].S-gy);
  if(memo[k][t][q]) return memo[k][t][q];
 
  int ans = INF, d = (t+1)%5, c;
  for(int i=0;i<p[d].size();i++){
    if(!k) c = abs(sx-p[d][i].F) + abs(sy-p[d][i].S);
    else c = abs(p[t][q].F-p[d][i].F) + abs(p[t][q].S-p[d][i].S);
    ans = min(ans, solve(k+1, d, i) + c);
  }
 
  return memo[k][t][q] = ans;
}
 
int main(){
 
  int w, h;
  char c;
 
  while(scanf("%d %d", &w, &h), w){
    
    for(int i=0;i<5;i++) p[i].clear();
    
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	scanf(" %c", &c);
	if(c == '.') continue;
	else if(c == 'S') sx = j, sy = i;
	else if(c == 'G') gx = j, gy = i;
	else p[c-'1'].push_back(P(j,i));
      }
    }
    
    int a, b = INF;
    for(int i=0;i<5;i++){
      memset(memo, 0, sizeof(memo));
      if(b > solve(0,i,0)) a = i+1, b = solve(0,i,0);
    }
 
    if(b == INF) puts("NA");
    else printf("%d %d\n", a, b);
 
  }
}