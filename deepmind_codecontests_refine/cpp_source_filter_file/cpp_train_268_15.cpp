#include <bits/stdc++.h>
long long int maxx(long long int a, long long int b) { return a > b ? a : b; }
long long int minn(long long int a, long long int b) { return a > b ? b : a; }
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int poww(long long int base, long long int exp) {
  base %= 1000000007;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
long long int sum(vector<int> a) {
  long long int ans = 0;
  for (int i = 0; i < a.size(); i++) ans += a[i];
  return ans;
}
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    long long int num = (long long int)(m - i * sum(a));
    if (num < 0) break;
    long long int score = (long long int)(i * (k + 1));
    for (int j = 0; j < k; j++) {
      score += min(num / a[j], n - i);
      num -= a[j] * min(num / a[j], n - i);
      if (num < 0) break;
    }
    ans = max(ans, score);
  }
  cout << ans;
}
