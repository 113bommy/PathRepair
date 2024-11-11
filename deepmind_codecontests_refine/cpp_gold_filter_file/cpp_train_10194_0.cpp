#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int N,X,Y;

int par[1111];
int cntx[1111],cnty[1111];

void init(){
    for(int i=0;i<2*(X+Y);i++){
        par[i]=i;
        cntx[i]=i%2==0;
        cnty[i]=i%2==1;
    }
}
int find(int x){
    return x==par[x]?x:par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    cntx[x]+=cntx[y];
    cnty[x]+=cnty[y];

    par[y]=x;
}

int dp[1111][1111];
void solve(){
    int M=X+Y;

    init();
    rep(i,N){
        int a,b;
        string s;
        cin>>a>>b>>s;
        a--;b--;

        a*=2;b*=2;
        if(s=="no")b++;
        unite(a,b);
        unite(a^1,b^1);
    }

    set<int>rs;

    vpint lis;

    rep(i,M){
        int r1=find(i*2);
        int r2=find(i*2+1);
        if(rs.find(r1)!=rs.end())continue;
        lis.pb({r1,r2});
        rs.insert(r1);rs.insert(r2);
    }

    memset(dp,0,sizeof(dp));
    dp[0][0]=1;

    for(int k=0;k<lis.size();k++){
        auto &p=lis[k];
        for(int i=0;i<=M;i++){
            if(i-cntx[p.fi]>=0)add(dp[k+1][i],dp[k][i-cntx[p.fi]]);
            if(i-cntx[p.se]>=0)add(dp[k+1][i],dp[k][i-cntx[p.se]]);
        }
    }

    if(dp[lis.size()][X]!=1){
        puts("no");
        return;
    }

    set<int>crs;

    for(int k=lis.size()-1;k>=0;k--){
        auto &p=lis[k];
        if(X-cntx[p.fi]>=0&&dp[k][X-cntx[p.fi]]){
            crs.insert(p.fi);
            X-=cntx[p.fi];
        }
        else{
            crs.insert(p.se);
            X-=cntx[p.se];
        }
    }

    rep(i,M){
        if(crs.find(find(i*2))!=crs.end())printf("%lld\n",i+1);
    }
    puts("end");
}

signed main(){
    while(cin>>N>>X>>Y,N||X||Y)solve();
    return 0;
}