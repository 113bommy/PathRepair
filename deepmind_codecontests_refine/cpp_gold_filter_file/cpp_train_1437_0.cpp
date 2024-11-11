// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=110,mod=998244353;
const ll inf=1e18;

int a[maxn][maxn], b[maxn][maxn], f[maxn], n, m;
bool adj[maxn][maxn], is[maxn][maxn], mark[maxn];

bool dfs(int u){
    mark[u]=1;
    for(int i=0;i<n;i++){
	if(adj[u][i]==0) continue;
	if(f[i]==-1){
	    f[i]=u;
	    return 1;
	}
	if(mark[ f[i] ]==0 && dfs( f[i] ) ){
	    f[i]=u;
	    return 1;
	}
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n>>m;

    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
	    cin>>a[i][j], a[i][j]--;
    }
    for(int col=0;col<m;col++){
	memset(adj,0,sizeof adj);
	for(int i=0;i<n;i++){
	    for(int j=col;j<m;j++){
		adj[ a[i][j]/m ][i]=1;
	    }
	}
	memset(f,-1,sizeof f);
	for(int k=0;k<n;k++)
	    memset(mark,0,sizeof mark), assert(dfs(k));
	for(int i=0;i<n;i++){
	    int id=-1;
	    for(int j=col;j<m;j++)
		if(a[i][j]/m==f[i]) id=j;
	    assert(id!=-1);
	    swap(a[i][col], a[i][id]);
	}
    }
    for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	    cout<<a[i][j]+1<<" \n"[j==m-1], b[i][j]=a[i][j];
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    a[ b[i][j]/m ][j]= b[i][j];
	}
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
	    cout<<a[i][j]+1<<" \n"[j==m-1];
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
