#include <iostream>
#include <cstring>
using namespace std;
char s[200005];
int nxt[2000005][30],n,dp[200005];
int main()
{
    cin.getline(s+1,200005);
    n=strlen(s+1);
    for(int i=0;i<26;++i) nxt[n+1][i]=n+1;
    dp[n+1]=1;
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<26;++j) nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]-'a']=i;
        dp[i]=n+1;
        for(int j=0;j<26;++j) dp[i]=min(dp[i],dp[nxt[i][j]+1]);
        ++dp[i];
    }
    int poz=1;
    while(poz<=n)
    {
        for(int i=0;i<26;++i)
        {
            if(nxt[poz][i]>n||dp[nxt[poz][i]+1]<dp[poz])
            {
                cout<<(char)('a'+i);
                poz=nxt[poz][i]+1;
                break;
            }
        }
    }
    return 0;
}
