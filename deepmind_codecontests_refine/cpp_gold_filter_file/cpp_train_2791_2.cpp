#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,i,j,k;
    cin >> n >> k;
    int h[n],dp[n]; 
    dp[0] = 0;
    for(i=0;i<n;++i) cin >> h[i];
    for(i=1;i<n;++i) {
     dp[i] = INT_MAX;
     for(j=1;j<=min(k,i);++j) dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    }
    cout << dp[n-1];
}