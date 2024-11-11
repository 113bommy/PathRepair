#include <bits/stdc++.h>
using namespace std;
int Max(int a, int b) { return (((b - a) >> (32 - 1)) & (a ^ b)) ^ b; }
int Min(int a, int b) { return (((b - a) >> (32 - 1)) & (a ^ b)) ^ a; }
long long GCD(long long a, long long b) { return b != 0 ? GCD(b, a % b) : a; }
long long LCM(long long a, long long b) { return a * (b / GCD(a, b)); }
long long Pow(long long n, long long e) {
  if (e == 0) return 1;
  if (e == 1)
    return n;
  else if (e & 1) {
    long long t = Pow(n, e / 2);
    return n * t * t;
  } else {
    long long t = Pow(n, e / 2);
    return t * t;
  }
}
int K, M;
set<int> m;
void Solve(int base, int rem, int number) {
  if (rem == 0) {
    int d = abs(K - abs(number));
    if (d < 10000) {
      m.insert(10000 * base + d);
      m.insert(10000 * d + base);
    }
    return;
  }
  Solve(base, rem / 10, number + (rem % 10));
  Solve(base, rem / 10, number - (rem % 10));
  Solve(base, rem / 10, number * (rem % 10));
}
int main() {
  scanf("%d %d", &K, &M);
  for (int i = 0, max_ = (1000); i < max_; ++i) {
    if ((int)(m).size() >= M) break;
    Solve(i, i / 10, i % 10);
  }
  auto it = m.begin();
  for (int i = 0, max_ = (M); i < max_; ++i) {
    if (it == m.end()) break;
    printf("%08d\n", *it);
    ++it;
  }
  return 0;
}
