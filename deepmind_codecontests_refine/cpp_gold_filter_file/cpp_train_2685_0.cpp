#include <bits/stdc++.h>

using namespace std;

int calc_gcd(int a, int b) { return b == 0 ? a : calc_gcd(b, a % b); }

long long calc_lcm(int a, int b) { return (long long)a * b / calc_gcd(a, b); }

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
    a /= 2;
  }
  long long lcm = A[0];
  for (int i = 1; i < N; i++) {
    lcm = calc_lcm(lcm, A[i]);
  }
  for (auto a : A) {
    if ((lcm / a) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  int x = M / lcm;
  int ans = (x + 1) / 2;
  cout << ans << endl;

  return 0;
}
