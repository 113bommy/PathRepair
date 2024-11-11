#include <bits/stdc++.h>
unsigned long long mulmod(unsigned long long a, unsigned long long b,
                          unsigned long long c) {
  unsigned long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}
unsigned long long pow(unsigned long long a, unsigned long long b,
                       unsigned long long c) {
  unsigned long long x = 1, y = a;
  while (b > 0) {
    if (b & 1) x = mulmod(x, y, c);
    y = mulmod(y, y, c);
    b >>= 1;
  }
  return x;
}
bool Miller(unsigned long long p, int iteration) {
  if (p < 2) {
    return false;
  }
  if (p != 2 && p % 2 == 0) {
    return false;
  }
  unsigned long long second = p - 1;
  while (second % 2 == 0) {
    second /= 2;
  }
  for (int i = 0; i < iteration; i++) {
    unsigned long long a = rand() % (p - 1) + 1, temp = second;
    unsigned long long mod = pow(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) {
      return false;
    }
  }
  return true;
}
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long ans = 0;
  sort(a.begin(), a.end(), greater<int>());
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int t = a[i];
    while (m[t] && t >= 0) {
      t--;
    }
    {
      ans += t;
      m[t] = 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
