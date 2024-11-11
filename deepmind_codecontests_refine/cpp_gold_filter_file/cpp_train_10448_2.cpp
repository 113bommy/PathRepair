#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1073741824;
long long a, b, c;
long long dp[100 + 100][100 + 100], m[1000 * 1000 + 1];
long long sum;
vector<long long> prime;
bool mark[100 + 100];
void priming() {
  mark[1] = true;
  for (long long i = 2; i <= 100; i++)
    if (mark[i] == false) {
      prime.push_back(i);
      for (long long j = i + i; j <= 100; j += i) mark[j] = true;
    }
}
void input() { cin >> a >> b >> c; }
void proses() {
  for (long long j = 1; j <= 100; j++)
    for (long long i = 0; i < prime.size(); i++)
      if (j % prime[i] == 0) {
        long long y = 0, x = j;
        while (x % prime[i] == 0) {
          y++;
          x /= prime[i];
        }
        dp[j][prime[i]] += y;
      }
}
void calc() {
  for (long long i = 1; i <= a; i++)
    for (long long j = 1; j <= b; j++)
      for (long long k = 1; k <= c; k++) {
        if (m[j * i * k] != 0)
          sum += m[j * i * k];
        else {
          long long t[100 + 100], temp = 1;
          for (long long ii = 0; ii < prime.size(); ii++) t[prime[ii]] = 0;
          for (long long ii = 0; ii < prime.size(); ii++)
            t[prime[ii]] +=
                dp[i][prime[ii]] + dp[j][prime[ii]] + dp[k][prime[ii]];
          for (long long ii = 0; ii < prime.size(); ii++)
            temp *= (t[prime[ii]] + 1);
          sum += temp;
          m[j * i * k] = temp;
        }
        sum %= MOD;
      }
}
void output() { cout << sum; }
int main() {
  ios_base::sync_with_stdio(false);
  priming();
  input();
  proses();
  calc();
  output();
}
