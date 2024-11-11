#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long eulerfi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) result -= result / i;
    while (n % i == 0) n /= i;
  }
  if (n > 1) result -= result / n;
  return result;
}
int countdigits(long long n) { return floor(log10(n) + 1); }
long long modexpo(long long x, long long n, long long m) {
  if (n == 0) {
    return 1;
  }
  long long ans = modexpo(x, n / 2, m);
  ans = (ans * ans) % m;
  if (n % 2 == 1) ans = (x * ans) % m;
  return ans;
}
int main() {
  int t = 1, flag = 0;
  while (t--) {
    int n, m, a, b, s = 0, k = 0;
    cin >> n;
    vector<int> v(2 * n - 1);
    for (int i = 0; i < v.size(); i++) {
      cin >> a;
      v[i] = abs(a);
      s = s + v[i];
      if (a < 0) {
        k++;
      }
    }
    if (k % 2 == 1 and n % 2 == 0) {
      sort(v.begin(), v.end());
      cout << s - 2 * v[0];
    } else {
      cout << s;
    }
  }
}
