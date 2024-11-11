#include <bits/stdc++.h>
using namespace std;
vector<int> factorize(int n) {
  vector<int> res;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    res.push_back(n);
  }
  return res;
}
long long int multiple(long long int a, long long int b, long long int c) {
  if (b == 0) return 0;
  long long int ret = multiple(a, b >> 1, c);
  ret = (ret + ret) % c;
  if (b & 1) ret = (ret + a) % c;
  return ret;
}
long int GCD(int A, int B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
long int Log2(long int x) {
  long int ans = 0;
  while (x >>= 1) ans++;
  return ans;
}
long long int mini(long long int a, long long int b) {
  if (a <= b)
    return a;
  else
    return b;
}
long long int maxe(long long int a, long long int b) {
  if (a >= b)
    return a;
  else
    return b;
}
int main() {
  int n;
  cin >> n;
  long int p = 0, ne = 0, a, b;
  for (long int i = 1; i <= n; i++) {
    cin >> a >> b;
    if (a >= 0)
      p++;
    else
      ne++;
  }
  if (p == 1 || ne == 1 || (ne == 0) || (p == 0))
    cout << "Yes\n";
  else
    cout << "No\n";
}
