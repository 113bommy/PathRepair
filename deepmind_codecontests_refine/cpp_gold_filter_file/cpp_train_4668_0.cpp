#include<bits/stdc++.h>
using namespace std;
const int N=305;
string s;
int dp[305][305][305],K;
int dfs(int l,int r,int x)
{
    if(r<l)return 0;
    if(l==r)return 1;
    if(dp[l][r][x]!=-1)return dp[l][r][x];//记忆化思想，减少搜索次数
    int t=max(dfs(l+1,r,x),dfs(l,r-1,x));//向左或右扩展一个
    if(s[l]==s[r])t=max(t,dfs(l+1,r-1,x)+2);//相等，进行扩展
    if(x)t=max(t,dfs(l+1,r-1,x-1)+2);//改变一个字符，向内扩展
    return dp[l][r][x]=t;
}
int main()
{
    cin>>s>>K;
    memset(dp,-1,sizeof(dp));
    cout<<dfs(0,s.size()-1,K)<<endl;
    return 0;
}
