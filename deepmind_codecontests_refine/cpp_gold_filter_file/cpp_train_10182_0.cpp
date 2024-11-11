#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<tuple>
#include <string.h>

using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
const ll mod=1e9+7;

int main(void){
    ll N;
    cin>>N;
    ll A[3],B[3];
    cin>>A[0]>>A[1]>>A[2]>>B[0]>>B[1]>>B[2];
    //重さ制限N,重さga,sa,ba 価値gb,sb,bbのナップザック
    ll dp[4][N+1];
    memset(dp,0,sizeof(dp));
    rep(i,3){
        rep(j,N+1){
            if(j<A[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=max(dp[i][j],dp[i+1][j-A[i]]+(B[i]-A[i]));
        }
    }
    
    ll M=dp[3][N]+N;
    ll dpa[M+1];
    rep(i,M+1) dpa[i]=0;
    rep(i,3){
        for(ll j=B[i];j<=M;j++){
            dpa[j]=max(dpa[j],dpa[j-B[i]]+(A[i]-B[i]));
        }
    }
    cout<<dpa[M]+M<<endl;
}
