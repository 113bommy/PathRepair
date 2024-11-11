#include <stdio.h>
#include <vector>
using namespace std;
const int N=2e5+10;
#define PB push_back
vector<int> graph[N];
int dep[N];
void dfs(int now){
  for(int i:graph[now])if(dep[i]==-1){
    dep[i]=dep[now]+1;
    dfs(i);
  }
  return ;
}
int max(int a,int b){return a>b?a:b;}
int main(){
  int n,l,r,root=1,ans=0;
  scanf("%d",&n);
  for(int i=1;i<n;i++){
	scanf("%d%d",&l,&r);
    graph[l].PB(r);
    graph[r].PB(l);
  }
  dep[1]=1;
  for(int i=2;i<=n;i++)dep[i]=-1;
  dfs(1);
  for(int i=1;i<=n;i++)if(dep[i]>dep[root])root=i;
  for(int i=1;i<=n;i++)dep[i]=-1;
  dep[root]=1;
  dfs(root);
  for(int i=1;i<=n;i++)ans=max(ans,dep[i]);
  if(ans%3==2)printf("Second\n");
  else printf("First\n");
}