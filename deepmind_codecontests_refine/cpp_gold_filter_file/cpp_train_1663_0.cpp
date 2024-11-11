#include<bits/stdc++.h>
using namespace std;
#define INF 100100100

int main(){

    int n, m; cin >> n >> m;
    int dp[55][10][55];
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 8; j++){
            for(int k = 0; k <= m; k++){
                dp[i][j][k] = -INF;
            }
        }
    }

    dp[0][0][m] = 0;


    for(int i = 0; i < n; i++) cin >> A[i] >> B[i] >> C[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 8; j++){
            for(int k = 0; k <= m; k++){

                for(int a = 0; a <= 8; a++){
                    
                    //残ってない
                    if(k - a < 0) continue;
        
                    int value = -INF;
                    //振らない
                    value = max(value, C[i]);

                    if(a != 0) value = max(value, A[i] * a);

                    if(j != 0) value = max(value, B[i] * j);

                    if(a + j >= 9){
                        if(A[i] > B[i]){
                            value = max(value, A[i] * a + B[i] * (8 - a));
                        }else{
                            value = max(value, A[i] * (8 - j) + B[i] * j);
                        }
                    }else{
                        if(a + j != 0) value = max(value, A[i] * a + B[i] * j);
                    }

                    if(a >= 1) value = max(value, A[i]);

                    if(j >= 1) value = max(value, B[i]);

                    dp[i + 1][a][k - a] = max(dp[i + 1][a][k - a], dp[i][j][k] + value);

                }
            }
        }
    }

    /*for(int i = 0; i <= n; i++){
        cout << i << endl;
        for(int j = 0; j <= 8; j++){
            for(int k = 0; k <= m; k++){
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
    }*/

    int ans = -INF;
    for(int j = 0; j <= 8; j++){
        for(int k = 0; k <= m; k++){
            ans = max(ans, dp[n][j][k]);
        }
    }

    cout << ans << endl;
    return 0;
}
