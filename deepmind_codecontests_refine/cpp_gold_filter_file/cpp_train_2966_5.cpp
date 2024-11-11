#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456")
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T sign(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dxK[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dyK[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dxKn[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dyKn[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int N = int(2e3) + 9;
const int M = int(3e3) + 9;
const int LOGN = 22;
const int SQN = 350;
const int MOD = int(1e9) + 7;
const int INF = 1e9 + 100;
const long long INF64 = 2e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-9;
int n, m, k;
int dp[N][N];
int cntBit[N];
bool mat[15][15];
int calc_dp(int msk1, int msk2) {
  int &res = dp[msk1][msk2];
  if (res != -1) return res;
  assert((msk1 & msk2) == msk2);
  if (cntBit[msk1] == 2) {
    int pos1 = -1, pos2;
    for (int i = 0; i < (int)(n); ++i)
      if ((1 << i) & msk1) {
        if (pos1 == -1)
          pos1 = i;
        else
          pos2 = i;
      }
    return res = (msk1 == msk2 && mat[pos1][pos2]);
  }
  res = 0;
  int pos = -1;
  for (int i = 0; i < (int)(n); ++i)
    if ((1 << i) & msk2) pos = i;
  for (int i = 0; i < (int)(n); ++i)
    if (mat[pos][i] && !((1 << i) & msk2) && ((1 << i) & msk1)) {
      int nmsk1 = msk1 ^ (1 << pos);
      int nmsk2 = msk2 ^ (1 << pos);
      res += calc_dp(nmsk1, nmsk2);
      res += calc_dp(nmsk1, nmsk2 ^ (1 << i));
    }
  return res;
}
void solve() {
  for (int i = 1; i < (int)(N); ++i) cntBit[i] = cntBit[i & (i - 1)] + 1;
  cin >> n >> m >> k;
  for (int i = 0; i < (int)(m); ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    mat[x][y] = mat[y][x] = true;
  }
  int res = 0;
  int cnt = 0;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < (int)((1 << n) - 1); ++i)
    if (cntBit[i] == k) res += calc_dp((1 << n) - 1, i), ++cnt;
  cout << res;
}
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  solve();
  return 0;
}
