#include <bits/stdc++.h>
using namespace std;
long long modulo(long long base, long long exp, long long m);
long long powerr(long long base, long long exp, long long m);
long long inverse(long long a, long long m);
void display(long long i) { cout << "Case #" << i << ": "; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "0";
    return 0;
  }
  long long s = 0, f = n, ans = 0;
  while (s <= f) {
    long long mid = (s + f) / 2;
    long long x = n - mid;
    x = (x * (x + 1)) / 2;
    if (x - mid == k) {
      ans = mid;
      break;
    } else if (x - mid < k)
      f = mid - 1;
    else
      s = mid + 1;
  }
  cout << ans;
  return 0;
}
long long modulo(long long base, long long exp, long long m) {
  long long answer = 1;
  while (exp > 0) {
    if (exp % 2 == 1) answer = (answer * base) % m;
    exp = exp / 2;
    base = (base * base) % m;
  }
  return answer;
}
long long powerr(long long base, long long exp, long long m) {
  base = base % m;
  if (exp == 0)
    return 1;
  else {
    if (exp % 2 == 0) {
      long long x = powerr(base, exp / 2, m);
      return (x * x) % m;
    } else {
      long long x = powerr(base, (exp - 1) / 2, m);
      return (base * ((x * x) % m)) % m;
    }
  }
}
void EE(long long a, long long b, long long &co1, long long &co2) {
  if (a % b == 0) {
    co1 = 0;
    co2 = 1;
    return;
  }
  EE(b, a % b, co1, co2);
  long long temp = co1;
  co1 = co2;
  co2 = temp - co2 * (a / b);
}
long long inverse(long long a, long long m) {
  long long x, y;
  EE(a, m, x, y);
  if (x < 0) x += m;
  return x;
}
