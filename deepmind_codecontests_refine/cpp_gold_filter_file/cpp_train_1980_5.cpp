#include <iostream>

using namespace std;

int fib(int n);

int main() {
int n;
int dp[45];

dp[0] = 1;
dp[1] = 1;

cin >> n;

for(int i = 2; i <= n; i++) {
dp[i] = dp[i-1] + dp[i-2];
}

cout << dp[n] << endl;
return 0;
}
