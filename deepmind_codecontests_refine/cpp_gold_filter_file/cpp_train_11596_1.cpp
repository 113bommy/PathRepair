#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y);
long long gcd(long long a, long long b);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long k;
  cin >> k;
  if (k == 1) {
    cout << n << "\n";
    return 0;
  }
  set<long long> s;
  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    s.insert(temp);
  }
  auto it = s.begin();
  while (it != s.end()) {
    long long val = (*it);
    if (s.find(val * k) != s.end()) s.erase(val * k);
    it++;
  }
  cout << s.size() << "\n";
  return 0;
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % 10;
  while (y > 0) {
    if (y & 1) res = (res * x) % 10;
    y = y >> 1;
    x = (x * x) % 10;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
