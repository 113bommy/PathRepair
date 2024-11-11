#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-11;
template <typename T, typename S>
vector<T>& operator<<(vector<T>& a, S b) {
  a.push_back(b);
  return a;
}
template <typename T>
void operator>>(vector<T>& a, int b) {
  while (b--)
    if (!a.empty()) a.pop_back();
}
bool isprime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long b_pow(long long x, long long n) {
  return n ? b_pow(x * x, n / 2) * (n % 2 ? x : 1) : 1ll;
}
string itos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
double p[201];
int a[201];
double dp[2][220][820];
int main() {
  ios_base::sync_with_stdio(false);
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) cin >> p[i], p[i] *= 0.01;
  for (int i = 0; i < n; i++) cin >> a[i];
  dp[0][0][400 + k] = 1.0;
  for (int i = 0; i < n; i++) {
    int cur = i & 1;
    int next = cur ^ 1;
    for (int j = 0; j < 820; j++)
      for (int w = 0; w < 220; w++) dp[next][w][j] = 0.0;
    for (int j = 0; j <= 800; j++) {
      for (int w = 0; w <= 200; w++) {
        if (dp[cur][w][j] < EPS) continue;
        if (a[i] == -1) {
          dp[next][w + 1][j - 1] += p[i] * dp[cur][w][j];
          dp[next][w][j] += (1 - p[i]) * dp[cur][w][j];
        } else {
          dp[next][w + 1][min(800, j + a[i])] += p[i] * dp[cur][w][j];
          dp[cur][w][j] += (1 - p[i]) * dp[cur][w][j];
        }
      }
    }
  }
  double ans = 0;
  for (int i = l; i < 220; i++) {
    for (int j = 400; j < 820; j++) {
      if (dp[n & 1][i][j]) {
        ans += dp[n & 1][i][j];
      }
    }
  }
  printf("%.8lf\n", ans);
}
