#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7 , mod  =998244353; 
int n ,m; 
long long dp[N]; 
 
int main(){
   // freopen("in.in" , "r" , stdin); 
    cin>>n>>m; 
    dp[0] = 1ll;
    long long ans = 0ll;  
    for(int i = 0 ; i< n ;i++){
        int t ; 
        cin>>t ; 
        for(int j = m ; j>0 ; j--){
            dp[j+t]+=dp[j];
            dp[j+t]%=mod;
        }
        dp[t]+=i+1;
        dp[t]%=mod ;    
        ans+=dp[m];
        ans%=mod;
    }
    cout<<ans ; 
    return 0 ;
}