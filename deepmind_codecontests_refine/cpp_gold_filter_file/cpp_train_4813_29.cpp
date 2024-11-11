#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long b, long long c, long long a_n, long long b_n,
            long long c_n) {
  return abs(a - a_n) + abs(b - b_n) + abs(c - c_n);
}
void solve() {
  int a, b, c;
  long long mini = 1E15, An, Bn, Cn;
  cin >> a >> b >> c;
  for (int A = 1; A <= 2E4; A++) {
    for (int B = A; B <= 2E4; B += A) {
      for (int C = B; C <= 2E4; C += B) {
        if (f(a, b, c, A, B, C) < mini) {
          mini = f(a, b, c, A, B, C);
          An = A;
          Bn = B;
          Cn = C;
        }
      }
    }
  }
  cout << mini << endl;
  cout << An << " " << Bn << " " << Cn << endl;
  return;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
