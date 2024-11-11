#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll MOD=1000000007;

int main(){
	ll N;
    cin >> N;
    ll N2=sqrt(N);
    ll K;
    cin >> K;
    vector<vector<ll>> dp(K+1, vector<ll>(2*N2+2,0));
    for(ll i=1;i<=N2;i++){
        dp[1][i]=1
    ;}
    dp[1][N2+1]=N/N2-N2;
    for(ll i=N2+2;i<=2*N2;i++){
        dp[1][i]=N/(2*N2+1-i)-N/(2*N2+2-i)
    ;}
    for(ll i=2;i<=K;i++){
        ll sum=0;
        for(ll j=2*N2;j>=1;j--){
            sum+=dp[i-1][2*N2+1-j];
            dp[i][j]=(sum*dp[1][j])%MOD
        ;}
    ;}
    ll ans=0;
    for(ll i=1;i<=2*N2;i++){
        ans+=dp[K][i];
        ans%=MOD;
    ;}
    cout<<ans<<endl;
return 0;
}
