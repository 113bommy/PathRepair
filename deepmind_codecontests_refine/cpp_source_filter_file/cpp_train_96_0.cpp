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

int N,M,A,B,P,Q;

void dfs(int k,int n,int s,vint &v,vint &latte){
    if(k==n){
        latte.pb(s);
        return;
    }
    dfs(k+1,n,s,v,latte);
    dfs(k+1,n,s+v[k],v,latte);
}

signed main(){
    cin>>N>>M>>A>>B>>P>>Q;

    if(A==1&&B==1){
        P+=Q;
        int ans=M;
        if(M/P>N)chmin(ans,abs(M-P*N));
        else{
            chmin(ans,abs(M-M/P*P));
            if(M/P+1<=N)chmin(ans,abs(M-M/P*P-P));
        }
        cout<<ans<<endl;
        return 0;
    }
    vector<int>v;
    int x=P,y=Q;
    for(int i=0;i<N;i++){
        v.pb(x+y);
        if(1.0*x*A>1e15||1.0*y*B>1e15)break;
        x*=A;y*=B;
    }

    int n=v.size()/2;
    vint latte,malta;
    dfs(0,n,0,v,latte);
    dfs(n,v.size(),0,v,malta);
    sort(all(latte));
    sort(all(malta));


    int ans=M;

    int cur=latte.size()-1;
    for(int i=0;i<malta.size();i++){
        while(cur&&latte[cur]+malta[i]>M)cur--;
        chmin(ans,abs(M-latte[cur]-malta[i]));
    }

    cur=0;
    for(int i=(int)malta.size()-1;i>=0;i--){
        while(cur+1!=latte.size()&&latte[cur]+malta[i]<M)cur++;
        chmin(ans,abs(M-latte[cur]-malta[i]));
    }

    cout<<ans<<endl;
    return 0;
}