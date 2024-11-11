#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
int n,m,k;
int a[N],b[N];
LL s[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=m;i++)cin>>b[i],s[i]=s[i-1]+b[i];
  int ans=0;
  for(int i=0;i<=n;i++){
    k-=a[i];
    if(k<0)break;
    auto x=upper_bound(s+1,s+1+m,k)-s-1;
    ans=max(ans,i+x);
  }
  cout<<ans<<'\n';
  return 0;
}