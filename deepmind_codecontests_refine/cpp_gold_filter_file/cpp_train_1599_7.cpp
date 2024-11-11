#include <bits/stdc++.h>
using namespace std;
using natural = std::uint64_t;
constexpr natural M = 1e9 + 7;
int main() {
  natural n;
  cin >> n;
  std::vector<natural> A(n + 1), B(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      B[i] = 1;
      continue;
    }
    if (i % 2 == 0) {
      A[i] = (A[i - 2] + B[i - 1] + 1) % M;
      B[i] = B[i - 1];
    } else {
      A[i] = A[i - 1];
      B[i] = (B[i - 2] + A[i - 1] + 1) % M;
    }
  }
  cout << (A[n] + B[n]) % M;
  return false;
}
