#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
int n, k, d;
int mem[105][2];
int solve(int N, bool flag) {
  if (N == 0 && flag) return 1;
  if (N == 0 && !flag) return 0;
  if (N < 0) return 0;
  if (mem[N][flag] != -1) return mem[N][flag];
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    if (i >= d) {
      sum = (sum % m + solve(N - i, 1) % m) % m;
      mem[N][flag] = sum;
    } else {
      sum = (sum % m + solve(N - i, flag) % m) % m;
      mem[N][flag] = sum;
    }
  }
  return mem[N][flag] = sum % m;
}
int main() {
  memset(mem, -1, sizeof mem);
  cin >> n >> k >> d;
  cout << solve(n, 0) << endl;
  return 0;
}
