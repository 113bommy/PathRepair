#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
vector<bool> isPrime(1000005 + 1, true);
string tos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
void seive() {
  isPrime[0] = 0, isPrime[1] = 0;
  for (long long i = 2; i * i <= 1000005; i++)
    if (isPrime[i])
      for (long long j = i * i; j <= 1000005; j += i) isPrime[j] = 0;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, ans, mid;
int main() {
  cin >> n >> m;
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }
  mid = (n) / 2;
  ans = m;
  if (abs(mid - (m - 1)) < abs(mid - m))
    ans--;
  else if (abs(mid - (m + 1)) < abs(mid - m))
    ans++;
  else
    ans++;
  cout << ans << "\n";
  return 0;
}
