#include <bits/stdc++.h>
using namespace std;
long long factorial(long long x) {
  long long ans = 1;
  for (long long i = 1; i <= x; i++) {
    ans = (ans * i) % 1000000007;
  }
  return ans;
}
pair<long long, long long> euclid(long long a, long long b) {
  if (b == 0) {
    return {1, 0};
  }
  pair<long long, long long> ans = euclid(b, a % b);
  long long x = ans.first, y = ans.second;
  return {y, x - y * (a / b)};
}
long long modInv(long long num) {
  pair<long long, long long> bez = euclid(num, 1000000007);
  if (bez.first < 0) bez.first += 1000000007;
  return bez.first;
}
long long choose(long long x, long long y) {
  long long top = factorial(x);
  long long bot1 = factorial(y);
  long long bot2 = factorial(x - y);
  long long bot = (bot1 * bot2) % 1000000007;
  return (top * modInv(bot)) % 1000000007;
}
int n;
string s;
int dp[5005][5005];
bool used[26];
int lastApp[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> s;
  string delet(1, s[0]);
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      delet += s[i];
    }
  }
  memset(lastApp, -1, sizeof lastApp);
  int size = delet.length();
  lastApp[delet[0] - 'a'] = 0;
  for (int i = 0; i < size; i++) {
    dp[i][1] = 1;
  }
  for (int i = 1; i < size; i++) {
    lastApp[delet[i] - 'a'] = i;
    for (int j = 2; j <= i + 1; j++) {
      int sum = 0;
      for (int k = 0; k < 26; k++) {
        if ((delet[i] - 'a' == k) || lastApp[k] == -1) continue;
        sum = (sum + dp[lastApp[k]][j - 1]) % 1000000007;
      }
      dp[i][j] = sum;
    }
  }
  long long finalSum = 0;
  for (int i = 1; i <= size; i++) {
    long long total = 0;
    for (int j = 0; j < 26; j++) {
      if (lastApp[j] == -1) continue;
      total = (total + dp[lastApp[j]][i]) % 1000000007;
    }
    finalSum = (finalSum + (choose(n - 1, i - 1) * total)) % 1000000007;
  }
  cout << finalSum << "\n";
  return 0;
}
