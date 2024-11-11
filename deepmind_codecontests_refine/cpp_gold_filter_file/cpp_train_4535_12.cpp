#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long fact(long long n) {
  long long ret = 1;
  for (int i = 1; i <= n; i++) ret *= i;
  return ret;
}
bool is_vowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
    return 1;
  return 0;
}
long double getDistance(long double x1, long double y1, long double x2,
                        long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long long power(long long base, long long p) {
  if (p == 1) return base;
  if (!p) return 1ll;
  long long ret = power(base, p / 2);
  ret *= ret;
  ret %= 1000000007ll;
  if (p & 1) ret *= base;
  return ret % 1000000007ll;
}
const int N = 200001;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = (0); i <= (n - 1); ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  long long sum = 0, mn;
  int idx = v[0];
  for (int i = (1); i <= (n - 1); ++i) sum += v[i] - v[0];
  mn = sum;
  for (int i = (1); i <= (n - 1); ++i) {
    sum -= (n - i) * 1ll * (v[i] - v[i - 1]);
    sum += i * 1ll * (v[i] - v[i - 1]);
    if (sum < mn) idx = v[i];
    mn = min(mn, sum);
  }
  cout << idx;
  return 0;
}
