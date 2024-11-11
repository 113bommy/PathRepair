#include <cstdio>
#include <algorithm>
#include <vector>

#define int long long
using namespace std;
const int N=100005;

int n,m;
int x[N],a[N],poi[N],cf[N],cnt;
long long k;
int block[N],num[N],vis[N];

vector<int>q[N];

void dfs(int x,int dep)
{
    num[x]=dep;vis[x]=1;block[x]=cnt;
    q[cnt].push_back(x);
    if(!vis[poi[x]]) dfs(poi[x],dep+1);
}
signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i) scanf("%lld",&x[i]);
    for(int i=1;i<n;++i) cf[i]=x[i+1]-x[i];
    scanf("%lld%lld",&m,&k);
    for(int i=1;i<n;++i)poi[i]=i;
    for(int i=1;i<=m;++i) {scanf("%lld",&a[i]);swap(poi[a[i]],poi[a[i]-1]);}
    for(int i=1;i<n;++i) if(!vicf[i]) cnt++,dfs(i,0);
    
    printf("%lld\n",x[1]);
    int now=x[1];
    for(int i=1;i<n;i++)
    {
        now+=cf[q[block[i]][(num[i]+k)%q[block[i]].size()]];
        printf("%lld\n",now);
    }
}