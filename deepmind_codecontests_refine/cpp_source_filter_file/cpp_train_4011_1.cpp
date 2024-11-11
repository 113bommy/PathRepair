#include <bits/stdc++.h>
using namespace std;
long long f[3000][2];
long long a, b, A[3000], B[3000];
long long dp(int x, int c) {
  if (x > 12) return c == 0;
  if (f[x][c] != -1) return f[x][c];
  long long &ret = f[x][c];
  ret = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if ((i ^ j) == B[x]) {
        if ((i + j + c) % 2 != A[x]) continue;
        ret += dp(x + 1, (i + j + c) / 2);
      }
  return ret;
}
int main() {
  cin >> a >> b;
  memset(f, -1, sizeof(f));
  int k = (a == b) * 2;
  for (int i = 0; i < 13; i++) {
    A[i] = a % 2;
    a /= 2;
  }
  for (int i = 0; i < 13; i++) {
    B[i] = b % 2;
    b /= 2;
  }
  cout << dp(0, 0) - k;
  return 0;
}
