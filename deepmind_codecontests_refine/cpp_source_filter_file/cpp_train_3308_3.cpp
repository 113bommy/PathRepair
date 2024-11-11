#include<bits/stdc++.h>
using namespace std;
typedef int I;
#define REP(i,n) for(I i=0;i<(I)(n);i++)

I n,dp[1024][100001],v[323456],w[323456];

void dfs(I i){
    I j=i/2;
    if(i>1){
        for(I k=1024;k+1;k--){
            if(dp[j-1][k]or!k){
                I ne=k+w[i-1];
                if(ne<=100000)dp[i-1][ne]=max(dp[j-1][k]+v[i-1],dp[i-1][ne]);
            }
            dp[i-1][k]=dp[j-1][k];
        }
    }
    if(i*2<=min(1024,n))dfs(i*2);
    if(i*2+1<=min(1024,n))dfs(i*2+1);
}

signed main(){
    cin>>n;
    REP(i,n){I x,y;cin>>v[i]>>w[i];}
    dp[0][w[0]]=v[0];
    dfs(1);
    REP(i,1024)REP(j,100000)dp[i][j+1]=max(dp[i][j],dp[i][j+1]);
    I q;cin>>q;
    REP(i,q){
        I u,l;cin>>u>>l;
        vector<I> cand;
        while(u>c1){
            cand.push_back(u);
            u=u/2;
        }
        I r=cand.size();
        I ans=0;
        REP(j,1<<r){
            I v_sub=0;I w_sub=0;
            REP(k,r){
                if(j>>k&1){
                    v_sub+=v[cand[k]-1];
                    w_sub+=w[cand[k]-1];
                }
            }
            if(w_sub<=l)ans=max(ans,dp[u-1][l-w_sub]+v_sub);
        }
        cout<<ans<<endl;
    }
}
