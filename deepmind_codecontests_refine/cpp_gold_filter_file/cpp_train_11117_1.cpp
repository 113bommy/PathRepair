#include <bits/stdc++.h>
using namespace std;

bool vis[100010];
int p[100010];

int main()
{
  ios::sync_with_stdio(false);
  int n,m,cnt=0,ans=0;
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    int x;string s;
    cin>>x>>s;
    if(vis[x]) continue;
    if(s=="AC"){
      vis[x]=1;
	  cnt++;
      ans+=p[x];
    }
    else{
      p[x]++;
    }
  }
  cout<<cnt<<" "<<ans<<endl;
  return 0;
}