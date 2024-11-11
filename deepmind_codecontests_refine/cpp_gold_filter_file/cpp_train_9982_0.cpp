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
vector < P > v[5];
int memo[5][5][1111];

int dist(P a, P b){
  return abs(a.F - b.F) + abs(a.S - b.S);
}


int solve(int cnt, int now, int p){
 
  if(cnt == 4) return dist(v[now][p], P(gx, gy));
  if(memo[cnt][now][p]) return memo[cnt][now][p];
 
  int ans = INF, next = (now+1)%5, cost;
  for(int i=0;i<v[next].size();i++){
    if(!cnt) cost = dist(P(sx, sy), v[next][i]);
    else cost = dist(v[now][p], v[next][i]);
    ans = min(ans, solve(cnt+1, next, i) + cost);
  }
 
  return memo[cnt][now][p] = ans;
}
 
int main(){
 
  int w, h;
  char c;
 
  while(scanf("%d %d", &w, &h), w){
    
    for(int i=0;i<5;i++) v[i].clear();
    
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	scanf(" %c", &c);
	if(c == '.') continue;
	else if(c == 'S') sx = j, sy = i;
	else if(c == 'G') gx = j, gy = i;
	else v[c-'1'].push_back( P(j,i) );
      }
    }
    
    int a, b = INF;
    for(int i=0;i<5;i++){
      memset(memo, 0, sizeof(memo));
      if(b > solve(0,i,0)) a = i+1, b = solve(0,i,0);
    }
 
    b == INF?puts("NA"):printf("%d %d\n", a, b);
 
  }
}