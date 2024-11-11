#include <bits/stdc++.h>
using namespace std;
int K;
long long A, B;
long long dp[1010][1010];
long long inv[2000010];
long long func(int a, int ab) {
  if (ab >= K) return ab;
  if (dp[a][ab] != -1) return dp[a][ab];
  if (a == 0) return dp[a][ab] = func(1, ab);
  if (a < K) {
    long long ans = (func(a + 1, ab) * A + func(a, ab + a) * B) % 1000000007ll *
                    inv[A + B] % 1000000007ll;
    return dp[a][ab] = ans;
  }
  long long p = A * inv[A + B] % 1000000007ll;
  long long q = (A + B) * inv[B] % 1000000007ll;
  return dp[a][ab] = (ab + a + p * q) % 1000000007ll;
}
int main(void) {
  int i, j;
  inv[1] = 1;
  for (i = 2; i < 2000010; i++)
    inv[i] = (1000000007ll - 1000000007ll / i) * inv[1000000007ll % i] %
             1000000007ll;
  cin >> K >> A >> B;
  for ((i) = 0; (i) < (int)(K + 1); (i)++)
    for ((j) = 0; (j) < (int)(K); (j)++) dp[i][j] = -1;
  long long ans = func(0, 0);
  cout << ans << endl;
  return 0;
}
