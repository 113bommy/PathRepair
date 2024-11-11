#include <bits/stdc++.h>
using namespace std;
long long t;
string s;
long long dp[2505][105];
long long modul(long long a) {
  return ((a % 1000000007) + 1000000007) % 1000000007;
}
long long rez(string S) {
  long long sum = 0;
  for (long long j = 0; j < S.size(); j++) {
    sum += S[j] - 'a';
  }
  return sum;
}
int main() {
  scanf("%I64d\n", &t);
  dp[0][0] = 1;
  for (long long i = 1; i <= 100; i++) {
    for (long long j = 0; j <= 2500; j++) {
      for (long long k = 0; k <= min((long long)25, j); k++) {
        dp[j][i] += dp[j - k][i - 1];
        dp[j][i] %= 1000000007;
      }
    }
  }
  for (long long i = 0; i < t; i++) {
    getline(cin, s);
    long long a = rez(s);
    if (a == 0) {
      cout << "0" << endl;
    } else {
      cout << modul(dp[a][s.size()] - 1) << endl;
    }
  }
}
