#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll n,a[22][22],dp[(1<<18)];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++){
        if(((i>>j)&1)==1){
            dp[i]=dp[i-(1<<j)];
            for(int k=0;k<n;k++)if(((i>>k)&1)==1)dp[i]+=a[j][k];
        }
    }
    for(int i=0;i<(1<<n);i++)for(int j=i;j;j=(j-1)&i)dp[i]=max(dp[i],dp[j]+dp[i^j]);
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}