#include <bits/stdc++.h>
using namespace std;
unsigned long long dp[101][101];
unsigned long long nCr(unsigned long long n, unsigned long long r) {
  if (n == r) return dp[n][r] = 1;
  if (r == 1) return dp[n][r] = n;
  if (r == 0) return dp[n][r] = 1;
  if (dp[n][r]) return dp[n][r];
  return dp[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}
long long mod(long long x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long add(long long a, long long b) { return mod((mod(a) + mod(b))); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
bool cmp(const pair<long long, long long>& p1, pair<long long, long long>& p2) {
  if (p1.first > p2.first)
    return 1;
  else if (p1.first == p2.first)
    return (p1.second < p2.second);
  else
    return 0;
}
bool is_balanced(char first, char second) {
  return ((first == '(' && second == ')') || (first == '{' && second == '}') ||
          (first == '[' && second == ']'));
}
int main() {
  long long test = 1;
  while (test--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    queue<int> q;
    long long sum = 0;
    for (long long i = 0; i < n; i++) cin >> a[i], sum += a[i];
    if (sum % k) {
      cout << "No" << '\n';
      return 0;
    }
    long long per_part = sum / k;
    long long totall = 0;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
      totall += a[i];
      cnt++;
      if (totall == per_part) {
        q.push(cnt);
        totall = 0;
        cnt = 0;
      }
    }
    if (q.size() != k) {
      cout << "No" << '\n';
      return 0;
    }
    cout << "Yes" << '\n';
    while (!q.empty()) {
      cout << q.front() << " ";
      q.pop();
    }
    cout << '\n';
  }
}
