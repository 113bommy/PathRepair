#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0, i##_l = (n); i < i##_l; i++)
int dp[100001][13];
int main() {
    std::string s;STD::cin >> s;dp[0][0] = 1;REP(i, s.size())REP(j, 13) REP(k, 10)if(s[i] == '?' || s[i] - '0' == k)(dp[i + 1][(j * 10 + k) % 13] += dp[i][j]) %= 1000000007;std::cout << dp[s.size()][5];return 0;
}
