#include <bits/stdc++.h>
using namespace std;
const long long int K = 998244353;
long long int mu(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int q = mu(a, n / 2);
  if (n % 2 == 0) return q * q % K;
  return q * q % K * a % K;
}
long long int d[55][55][55][55], inv[305];
int isLiked[55], weight[55];
int n, m, total;
long long int a, b;
long long int calc(int w, int A, int B, int m, int i) {
  if (w * isLiked[i] + weight[i] < 0 || A + a < 0 || b - B < 0) return 0;
  if (m == 0) {
    return w * isLiked[i] + weight[i];
  }
  if (d[w][A][B][m] != -1) return d[w][A][B][m];
  long long int deno = inv[w * isLiked[i] + A - B + weight[i] + a + b];
  long long int res = 0;
  res += (A + a) * calc(w, A + 1, B, m - 1, i) % K;
  res %= K;
  res += (b - B) * calc(w, A, B + 1, m - 1, i) % K;
  res %= K;
  res += (weight[i] + w * isLiked[i]) * calc(w + 1, A, B, m - 1, i) % K;
  res %= K;
  res = res * deno % K;
  return d[w][A][B][m] = res % K;
}
long long int solve(int i) {
  memset(d, -1, sizeof(d));
  a = 0, b = 0;
  for (int j = 1; j <= n; j++) {
    if (j == i) continue;
    if (isLiked[j] == 1) {
      a += weight[j];
    } else {
      b += weight[j];
    }
  }
  return calc(0, 0, 0, m, i);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  for (int i = 1; i <= 300; i++) {
    inv[i] = mu(i, K - 2);
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> isLiked[i];
    if (!isLiked[i]) isLiked[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> weight[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << solve(i) << endl;
  }
  return 0;
}
