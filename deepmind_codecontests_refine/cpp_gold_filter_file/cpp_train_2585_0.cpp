#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

struct UnionFind{
   vector<int> par;
   UnionFind(int n):par(n,-1){}
   int find(int x){
       if(par[x]<0)return x;
       return par[x]=find(par[x]);
   }
   bool unite(int x,int y){
       x=find(x);
       y=find(y);
       if(x==y)return false;
       if(par[x]>par[y]){
           par[y]+=par[x];
           par[x]=y;
       }
       else{
           par[x]+=par[y];
           par[y]=x;
       }
       return true;
   }

   bool same(int x,int y){
       return find(x)==find(y);
   }
   int size(int x){
       return -par[find(x)];
   }
};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int c[n];
    int cnt=0;
    vector<int> cost;
    UnionFind uf(n+k);
    rep(i,n){
        cin>>c[i];
        --c[i];
        if(c[i]==-1)++cnt;
        else {
            uf.unite(i,c[i]+n);
            cost.push_back(0);
        }
    }
    int a[m],b[m],z[m];
    rep(i,m){
        cin>>a[i]>>b[i]>>z[i];
        --a[i];
        --b[i];
    }
    vector<int> ord(m);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return z[x]<z[y];
    });
    for(auto i : ord){
        if(uf.unite(a[i],b[i])){
            cost.push_back(z[i]);
        }
    }
    int s=cost.size();
    if(s+cnt<n+k-1){
        cout<<-1<<endl;
        return 0;
    }
    else {
        ll sum=0;
        rep(i,n+k-1-cnt){
            sum+=cost[i];
        }
        cout<<sum<<endl;
    }

    return 0;
}