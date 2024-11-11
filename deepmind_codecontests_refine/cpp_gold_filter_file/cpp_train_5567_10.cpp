#include <bits/stdc++.h>
using namespace std;
long long MOD_EXPO(long long b, long long p, long long m) {
  if (p == 0) return 1;
  long long ret = MOD_EXPO(b, p / 2, m) % m;
  ret = (ret * ret) % m;
  return ((p & 1) ? (ret * b) % m : ret % m);
}
long long POWER(long long N, long long K) {
  long long i, ans = 1;
  for (i = 1; i <= K; i++) ans *= N;
  return ans;
}
int SET(int N, int pos) { return (N | (1 << pos)); }
int RESET(int N, int pos) { return (N & !(1 << pos)); }
bool CHECK(int N, int pos) { return (N & (1 << pos)); }
int dx4[] = {1, -1, 0, 0};
int dy4[] = {0, 0, 1, -1};
int dx6[] = {0, 0, 1, -1, 0, 0};
int dy6[] = {1, -1, 0, 0, 0, 0};
int dz6[] = {0, 0, 0, 0, 1, -1};
int dx8[] = {1, -1, 0, 0, -1, 1, -1, 1};
int dy8[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dkx8[] = {-1, 1, -1, 1, -2, -2, 2, 2};
int dky8[] = {2, 2, -2, -2, 1, -1, 1, -1};
int tc = 1;
const double eps = 1e-9;
const double pi = acos(-1.0);
const long long int mx = 30000;
const long long int mn = 500;
const long long int mod = 1e9 + 7;
int dp[mx + 5][mn + 5];
int n, d, arr[mx + 5];
int calc(int i, int j) {
  if (i > mx) return 0;
  int k = j - (d - 250);
  int &ret = dp[i][k];
  if (ret != -1) return ret;
  ret = 0;
  if (j == 1) ret = max(calc(i + j, j), calc(i + j + 1, j + 1)) + arr[i];
  if (j >= 2)
    ret = max(calc(i + j - 1, j - 1),
              max(calc(i + j, j), calc(i + j + 1, j + 1))) +
          arr[i];
  return ret;
}
int main() {
  int i, x;
  cin >> n >> d;
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    arr[x]++;
  }
  memset(dp, -1, sizeof(dp));
  cout << calc(d, d) << "\n";
  return 0;
}
