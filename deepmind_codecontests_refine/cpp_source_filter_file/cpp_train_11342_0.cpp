
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    for(int C = 1; ; ++C) {
        int N, W;
        cin >> N >> W;
        if(!N && !W) break;

        vector<int> ws(N);
        for(int i = 0; i < N; ++i) cin >> ws[i];

        vector<vector<int> > sv(N, vector<int>(N, 0));
        for(int i = 0; i < N; ++i) {
            int sum = 0;
            for(int j = i; j < N; ++j) {
                sum += ws[j];
                sv[i][j] = sum;
            }
        }
        vector<vector<int> > cv(N, vector<int>(N, 0));
        for(int i = 0; i < N; ++i) {
            int sum = 0;
            for(int j = i; j < N; ++j) {
                sum += ws[j];
                cv[i][j] = abs(sum-W);
            }
        }

        vector<int> dp(N, INT_MAX);
        dp[0] = cv[0][0];
        for(int i = 1; i < N-1; ++i) {
            dp[i] = cv[0][i];
            for(int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j]+cv[j+1][i]);
            }
        }
        dp[i] = max(0, cv[0][N-1]-W);
        for(int i = 0; i < N-1; ++i) dp[N-1] = min(dp[N-1], dp[i] + max(0, sv[i+1][N-1]-W));

        cout << "Case " << C << ": " << dp[N-1] << endl;
    }
    return 0;
}