#include <iostream>
#include <cstring>
using namespace std;
char s[200005];
int next[2000005][30],n,dp[200005];
int main()
{
    cin.getline(s+1,200005);
    n=strlen(s+1);
    for(int i=0;i<26;++i) next[n+1][i]=n+1;
    dp[n+1]=1;
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<26;++j) next[i][j]=next[i+1][j];
        next[i][s[i]-'a']=i;
        dp[i]=n+1;
        for(int j=0;j<26;++j) dp[i]=min(dp[i],dp[next[i][j]+1]);
        ++dp[i];
    }
    int poz=1;
    while(poz<=n)
    {
        for(int i=0;i<26;++i)
        {
            if(next[poz][i]>n||dp[next[poz][i]+1]<dp[poz])
            {
                cout<<(char)('a'+i);
                poz=next[poz][i]+1;
                break;
            }
        }
    }
    return 0;
}
