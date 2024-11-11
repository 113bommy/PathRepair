#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const int MAX_N = 1000005;
const int Mod = 1000000007;
int N, Ones, Twos, DP[MAX_N], Solution;
void Solve() {
  Solution = 1;
  for (; Twos > 0; --Twos, --N) Solution = (1LL * Solution * N) % Mod;
  DP[0] = 1;
  for (int i = 1; i <= N; ++i) {
    DP[i] = DP[i - 1];
    if (i >= 2) DP[i] = (DP[i] + 1LL * (i - 1) * DP[i - 2]) % Mod;
  }
  Solution = (1LL * Solution * DP[N]) % Mod;
}
void Read() {
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int capacity;
    cin >> capacity;
    if (capacity == 1)
      ++Ones;
    else
      ++Twos;
  }
}
void Print() { cout << Solution << "\n"; }
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
