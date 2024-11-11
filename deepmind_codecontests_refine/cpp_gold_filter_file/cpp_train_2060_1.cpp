#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
string a;
int ans, n, dp[N][2];
 
int f(int i, int carry) {
    int digit = ((a[i] - '0')) + carry;
    if (i == 0) return digit;
    if (dp[i][carry]) return dp[i][carry];
    return dp[i][carry] = (min(f(i-1, 1) + (10-digit), f(i-1, 0) + digit));
}
 
int main() {
    cin >> a;
    n = a.length();
    a = '0' + a;
    cout << f(n, 0) << '\n';
}