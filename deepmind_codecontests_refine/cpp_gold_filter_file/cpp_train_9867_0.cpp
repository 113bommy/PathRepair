#include <bits/stdc++.h>

using namespace std;

const int N = 3010;
const int P = 998244353;

int mult(int a, int b) {
    return a * 1ll * b % P;
}
void add(int &a, int b) {
    a += b;
    if(a >= P) a -= P;
}
void sub(int &a, int b) {
    a -= b;
    if(a < 0) a += P;
}

int dp[N][N];

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    dp[a][b] = 1;
    for (int i = a; i <= c; ++i) {
        for (int j = b; j <= d; ++j) {
            add(dp[i][j], mult(j, dp[i-1][j]));
            add(dp[i][j], mult(i, dp[i][j-1]));
            sub(dp[i][j], mult(mult(i - 1, j - 1), dp[i-1][j-1]));

        }
    }
    printf("%d\n", dp[c][d]);
}