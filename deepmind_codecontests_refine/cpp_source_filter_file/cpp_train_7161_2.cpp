#include <bits/stdc++.h>
using namespace std;
const int MAX=6005;

int dp1[MAX][2];
int main(){
    int N,T;
    cin >> N >> T;
    int i,j;
    int ans=0;
    int tmp;
    int a,b;
    for(i=0;i<N;i++){
        cin >> a >> b;
        for(j=T-1;j>=0;j--){
            if(j+a<=T-1){
                dp[j+a][0]=max(dp[j+a][0],dp[j][0]+b);
                dp[j+a][1]=max(dp[j+a][1],dp[j][1]+b);
                }
            dp[j][1]=max(dp[j][1],dp[j][0]+b);
            }
        }
    for(i=0;i<MAX;i++)if(dp[i][1]>ans)ans=dp[i][1];
    cout << ans << endl;
}