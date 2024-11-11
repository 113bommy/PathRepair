#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORR(i,a,b) for (int i=a; i>=b; i--)

typedef long long ll;

#define mod 100000

int dp[100][100][4]={};
// 0:rr 1:ru 2:ur 3:uu

int main(void) {
    int n,m;
    while(cin >> n >> m && n>0)
    REP(i,n){
        dp[i][0][0]=1;
    }
    REP(i,m){
        dp[0][i][3]=1;
    }
    FOR(i,1,n-1){
        FOR(j,1,m-1){
            dp[i][j][0]=dp[i-1][j][0]+dp[i-1][j][2];
            dp[i][j][3]=dp[i][j-1][1]+dp[i][j-1][3];
            dp[i][j][1]=dp[i][j-1][0];
            dp[i][j][2]=dp[i-1][j][3];
            REP(k,4){
                dp[i][j][k]%=mod;
            }
        }
    }
    
    int ans=0;
    REP(i,4){
        ans = ans+dp[n-1][m-1][i];
    }
    ans %= mod;
    
    cout << ans << endl;
}

    return 0;
}