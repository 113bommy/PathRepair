#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int MOD = 1000000007;
vector<int> P, F;
int N, Solution;
vector<bool> Used;
inline int Pow(int value, int power) {
  int result = 1;
  for (; power > 0; power >>= 1) {
    if (power & 1) result = (1LL * result * value) % MOD;
    value = (1LL * value * value) % MOD;
  }
  return result;
}
inline int Inverse(const int value) { return Pow(value, MOD - 2); }
inline int Factorial(const int n) {
  if (n < 0) return 0;
  if (F.empty()) F.push_back(1);
  while (int(F.size()) <= n)
    F.push_back((1LL * F[int(F.size()) - 1] * int(F.size())) % MOD);
  return F[n];
}
inline int C(const int n, const int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return (1LL * Factorial(n) *
          Inverse((1LL * Factorial(k) * Factorial(n - k)) % MOD)) %
         MOD;
}
void Solve() {
  int fixed = 0, free = 0;
  for (int i = 0; i < N; ++i) {
    if (P[i] == -1) ++free;
    if (P[i] == -1 && !Used[i]) ++fixed;
  }
  for (int i = 0, sign = 1; i <= fixed; ++i, sign = -sign)
    Solution =
        (1LL * Solution +
         1LL * sign * ((Factorial(free - i) * C(fixed, i)) % MOD) + MOD) %
        MOD;
}
void Read() {
  cin >> N;
  P = vector<int>(N);
  Used = vector<bool>(N, false);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
    if (P[i] > 0) --P[i];
    if (P[i] >= 0) Used[P[i]] = true;
  }
}
void Print() { cout << Solution << "\n"; }
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
