#include <bits/stdc++.h>
using namespace std;
const int T = 1001;
int C[T], DP[T], KP[T][T];
int main() {
  long long k, j = -1, mod = 1000000007, tmp = 1, th = 0;
  for (int i = 0; i < T; i++) {
    KP[i][0] = 1;
    for (int j = 1; j < i + 1; j++) {
      KP[i][j] = (KP[i - 1][j] + KP[i - 1][j - 1]) % mod;
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> C[i];
    j += C[i];
  }
  for (int i = 0; i < k; i++) {
    th += C[i];
    tmp *= KP[th - 1][C[i] - 1];
    tmp %= mod;
  }
  cout << tmp;
}
