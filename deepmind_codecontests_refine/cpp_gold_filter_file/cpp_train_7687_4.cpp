#include<cstdio>
#include<vector>

using namespace std;
vector<int> G[100];

int dfs(int n, int mask, int now) {
  int res = 0;
  if(mask == (1<<n)-1) return 1;
  
  for(auto v : G[now]) {
    if(~mask & (1<<v)) res += dfs(n, mask | (1<<v), v);
  }
  return res;
}

int main(void) {
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0; i<m; i++) {
    int a,b;
    scanf("%d%d",&a,&b);
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  printf("%d\n",dfs(n, 1, 0));
}