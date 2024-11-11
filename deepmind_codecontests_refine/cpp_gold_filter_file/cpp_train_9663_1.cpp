#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
long long dp[100010][5];
int main(){
    string s;
    cin >> s;
    for(int i = s.length(); i >= 0; --i){
        for(int j = 3; j >= 0; --j){
            if(i == s.length()){
                dp[i][j] = (j == 3 ? 1 : 0);
            }
            else{
                dp[i][j] = dp[i+1][j] * (s[i] == '?' ? (long long)3 : (long long)1);
                if(j < 3 && (s[i] == '?' || s[i] == "ABC"[j])){
                    dp[i][j] += dp[i+1][j+1];
                }
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[0][0] << endl;
}
