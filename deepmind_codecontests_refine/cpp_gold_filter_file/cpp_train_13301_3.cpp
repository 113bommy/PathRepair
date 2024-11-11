#include <bits/stdc++.h>
#define roop(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define chmax(x, y) { x = max(x, y); }

int a[3005][3005];
ll dp[3005][3005][4];

int main() {
    int R, C, K;
    cin >> R >> C >> K;
    roop(i, K){
        int r, c, v;
        cin >> r >> c >> v;
        a[r - 1][c - 1] = v; //各マスのアイテム
    }
    roop(i, R){
        roop(j, C){
            for(int k = 2; k >= 0; k--){
                chmax(dp[i][j][k + 1], dp[i][j][k] + a[i][j]);
            }
            roop(k, 4){
                chmax(dp[i + 1][j][0], dp[i][j][k]);
                chmax(dp[i][j + 1][k], dp[i][j][k]);
            }
        }
    }
    ll ans = 0;
    roop(k, 4){
        chmax(ans, dp[R - 1][C - 1][k]);
    }
    cout << ans << endl;
    return 0;
}