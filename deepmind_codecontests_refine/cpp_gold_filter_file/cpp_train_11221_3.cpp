#include <bits/stdc++.h>
using namespace std;
 
void chmin(int& a, int b){
    a = min(a, b);
}
 
int main(){
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++) cin >> A[i] >> B[i];
 
    vector<int> dp(100000, 1e9);
    dp[0] = 0;
    for(int h=0; h<H; h++) for(int i=0; i<N; i++){
        chmin(dp[min(h+A[i], H)], dp[h] + B[i]);
    }
    cout << dp[H] << endl;
    return 0;}