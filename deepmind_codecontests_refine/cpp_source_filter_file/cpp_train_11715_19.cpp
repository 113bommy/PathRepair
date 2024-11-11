#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
string s;
long long n, k;
const long long M = 26;
long long last[M], dp[M], sum, order[M];
void input() {
  cin >> n >> k >> s;
  memset(last, -1, sizeof last);
}
void append(long long c) {
  sum = (sum - dp[c] + MOD) % MOD;
  dp[c] = (dp[c] + sum + 1) % MOD;
  sum = (sum + dp[c]) % MOD;
}
bool com(long long a, long long b) { return last[a] < last[b]; }
void countS() {
  sum = 0;
  for (long long i = 0; i < s.size(); i++) {
    long long c = s[i] - 'a';
    last[c] = i;
    append(c);
  }
}
void greedy() {
  for (long long i = 1; i <= 25; i++) order[i] = order[i - 1] + 1;
  sort(order, order + 26, com);
  for (long long i = 0; i < n; i++) {
    long long c = order[i % k];
    append(c);
  }
  cout << (sum + 1) % MOD << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  input();
  countS();
  greedy();
}
