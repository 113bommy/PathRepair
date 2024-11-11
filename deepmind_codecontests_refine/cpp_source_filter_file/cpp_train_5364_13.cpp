#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b, a % b);
}
long long int power(long long int x, long long int n) {
  if (n == 0) return 1;
  if (n % 2) return x * power(x * x, (n - 1) / 2);
  return power(x * x, n / 2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, p;
  cin >> n >> p;
  vector<long long int> v;
  string s, h = "halfplus";
  for (int i = 0; i < n; i++) {
    cin >> s;
    if (s == h) {
      v.push_back(1);
    } else {
      v.push_back(0);
    }
  }
  unsigned long long int N = 0;
  for (long long int i = 0; i < v.size(); i++) {
    N += v[i] * (1 << i);
  }
  unsigned long long int ans = 0;
  while (N > 0) {
    ans += ((N / 2) * p) + (N % 2) * (p / 2);
    N /= 2;
  }
  cout << ans;
  return 0;
}
