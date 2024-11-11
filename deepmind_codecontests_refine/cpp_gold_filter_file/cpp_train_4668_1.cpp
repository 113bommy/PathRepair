#include<bits/stdc++.h>
using namespace std;
string st;
int dp[310][310][310],K;
int dfs(int l,int r,int x){
    if(r<l)return 0;
    if(l==r)return 1;
    if(dp[l][r][x]!=-1)return dp[l][r][x];
    int res=max(dfs(l+1,r,x),dfs(l,r-1,x));
    if(st[l]==st[r])res=max(res,dfs(l+1,r-1,x)+2);
    if(x)res=max(res,dfs(l+1,r-1,x-1)+2);
    return dp[l][r][x]=res;
}
int main(){
    cin>>st>>K;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,st.size()-1,K)<<endl;
    return 0;
}