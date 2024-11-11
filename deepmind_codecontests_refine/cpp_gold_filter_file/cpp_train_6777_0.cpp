#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
map<long long, int> test;
long long a[110000];
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    long long p = sqrt(a[i]);
    if (p * p == a[i]) {
      long long tmp = sqrt(p);
      if (pow(tmp, 4) == a[i]) {
        test[tmp] += 4;
      } else {
        test[p] += 2;
      }
      continue;
    }
    p = cbrtl(a[i]);
    if (pow(p, 3) == a[i]) {
      test[p] += 3;
      continue;
    }
    bool lazy = false;
    for (int j = 1; j <= n && !lazy; j++) {
      if (a[i] != a[j]) {
        long long g = gcd(a[i], a[j]);
        if (g != 1) {
          test[g]++;
          test[a[i] / g]++;
          lazy = true;
          break;
        }
      }
    }
    if (!lazy) {
      test[a[i]] = sqrt(test[a[i]] + 1) + 1;
      test[a[i]] = test[a[i]] * test[a[i]] - 1;
    }
  }
  long long sum = 1;
  for (auto i : test) {
    sum = sum * (i.second + 1) % 998244353;
  }
  cout << sum << endl;
}
