#include <bits/stdc++.h>
using namespace std;
long long powe(long long a, long long b) {
  long long M = 1000000007;
  if (b == 0) return 1;
  if (b % 2 == 0) {
    return powe((a * a) % M, b / 2);
  } else {
    return (a * (powe(((a * a) % M), (b - 1) / 2)) % M);
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
const int mod = 1e9 + 7;
bool f(int x, int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    sum += a;
  }
  n = n + 1;
  int ans = 0;
  for (int i = 1; i <= 5; ++i) {
    if ((sum + i) % n != 1) ans++;
  }
  cout << ans;
  return 0;
}
