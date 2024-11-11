#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
const int mod = 998244353;
int power(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = 1LL * res * a % mod;
        }
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}
int main(){
    int n, m, a, b, c, ans = 1, flag = 1, tot[N] = {0}, bit[N][4], dp[2][2];
    map<pair<int, int>, int> tell;
    scanf("%d %d", &n, &m);
    memset(bit, -1, sizeof(bit));
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        if(abs(a - b) <= 1){
            bit[max(a, b)][2 - (a - b)] = c;
        }else{
            if(abs(a - b) > 2){
                if(tell[{b, a}] == 0){
                    tot[max(a, b)]++;
                }else if(tell[{b , a}] != c + 1){
                    flag = 0;
                }
            }
            tell[{a, b}] = c + 1;
        }
    }
    if(!flag){
        printf("0\n");
        return 0;
    }
    for(int i = 4; i <= n; i++){
        ans = 1LL * ans * power(2, (i - 3 - tot[i])) % mod;
    }
    for(int i = 1; i < n; i++){
        bit[i + 1][0] = bit[i][2];
    }
    b = 0;
    dp[1][0] = (bit[1][2] < 1);
    dp[1][1] = (bit[1][2] != 0);
    for(int i = 2; i <= n; i++){
        dp[b][0] = dp[b][1] = 0;
        int c1 = tell[{i, i - 2}], c2 = tell[{i - 2, i}];
        for(int j = 0; j < 16; j++){
            flag = 1;
            int cnt = 0;
            for(int k = 0; k < 4; k++){
                if(j & (1 << k)){
                    cnt ^= 1;
                    if(bit[i][k] == 0){
                        flag = 0;
                    }
                }else{
                    if(bit[i][k] == 1){
                        flag = 0;
                    }
                }
            }
            if(!flag || cnt) continue;
            int oneprev = (j & 1 ? 1 : 0);
            int onecurr = (j & 4 ? 1 : 0);
            int mul = 0;
            if(c1 + c2 == 0){
                mul = 2;
            }else if(c1 + c2 == 1){
                mul = 1; 
            }else if(c1 + c2 == 3){
                mul = (oneprev ? 1 : 0);
            }else if(c1 + c2 == 4){
                mul = (oneprev ? 0 : 1);
            }else{
                if(c1 == 1){
                    mul = (oneprev ? 0 : 1);
                }else{
                    mul = 1;
                }
            }
            if(i == 2) mul = 1;
            dp[b][onecurr] += 1LL * mul * dp[b ^ 1][oneprev] % mod;
            if(dp[b][onecurr] >= mod){
                dp[b][onecurr] -= mod;
            }
        }
        b ^= 1;
    }
    ans = 1LL * ans * ((dp[b ^ 1][0] + dp[b ^ 1][1]) % mod) % mod;
    printf("%d\n", ans);
    return 0;
}