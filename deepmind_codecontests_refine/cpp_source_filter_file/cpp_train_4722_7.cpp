#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
long long K, B, N, MOD;
long long A[MAX], psum[MAX];
map<int, int> ma;
long long C2(int a) { return a * (a - 1) / 2; }
long long zero() {
  A[N] = 10000000;
  int last = -1;
  long long res = 0;
  for (int i = 0; i <= N; i++) {
    if (A[i] != 0) {
      res += C2(i - last);
      last = i;
    }
  }
  return res;
}
int main() {
  cin >> K >> B >> N;
  MOD = K - 1;
  psum[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    psum[i + 1] = A[i] + psum[i];
  }
  long long z = zero();
  if (B == 0) {
    cout << z << endl;
    return 0;
  }
  long long res = 0;
  ma.clear();
  ma[0] = 1;
  for (int i = 1; i <= N; i++) {
    int c = psum[i] % MOD;
    int n = (c - B + MOD) % MOD;
    res += ma[n];
    ma[c]++;
  }
  if (B == MOD) {
    res -= z;
  }
  cout << res << endl;
}
