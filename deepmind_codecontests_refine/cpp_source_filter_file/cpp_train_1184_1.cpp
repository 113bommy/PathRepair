#include <bits/stdc++.h>
using namespace std;
long long n = 0, k = 0, count_ = 0;
long long factorial(long long h) { return (h * (h + 1) / 2); }
long long sum(long long s, long long e) {
  if (s < 1) return factorial(e);
  return factorial(e) - factorial(s - 1);
}
long long search_B() {
  long long s = 1, e = k, m = 0, sum_ = 0;
  while (s < e) {
    m = (s + e) / 2;
    sum_ = sum(m, k);
    if (sum_ == n) return k - m + 1;
    if (sum_ > n)
      s = m + 1;
    else if (sum_ < n)
      e = m;
  }
  return k - s + 2;
}
int main() {
  cin >> n >> k;
  n--;
  k--;
  if (n <= k)
    cout << 1;
  else if (n == 0)
    cout << 0;
  else {
    if (factorial(k) < n)
      cout << -1;
    else
      cout << search_B();
  }
  return 0;
}
