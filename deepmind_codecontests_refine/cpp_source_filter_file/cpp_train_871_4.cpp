#include <bits/stdc++.h>
using namespace std;
const int N = 200500;
map<long long, int> dp;
long long f(long long mask, int n) {
  if (mask == 0) return 0;
  if (dp.count(mask)) return dp[mask];
  set<long long> s;
  for (int j = 0, qwerty = n; j < qwerty; j++) {
    if ((mask & (1LL << j)) == 0) continue;
    long long mask2 = mask;
    for (long long k = j; k < n; k += j + 1)
      mask2 |= (1LL << k), mask2 ^= (1LL << k);
    s.insert(f(mask2, n));
  }
  long long g = 0;
  for (long long x : s) {
    if (x != g) break;
    g++;
  }
  return dp[mask] = g;
}
void gen() {
  for (int i = 0, qwerty = 30; i < qwerty; i++) {
    dp.clear();
    cout << f((1 << i) - 1, i) << ", ";
  }
  cout << "\n";
}
set<int> s;
int w[30] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
             9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int x = 1, C = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (!s.count(i)) {
      long long j = i;
      int cnt = 0;
      while (j <= n) cnt++, s.insert(j), j *= i;
      x ^= w[cnt];
      C += cnt;
    }
  }
  C = (n - C) % 2;
  if (C) x ^= 1;
  if (x)
    cout << "Vasya\n";
  else
    cout << "Petya\n";
}
