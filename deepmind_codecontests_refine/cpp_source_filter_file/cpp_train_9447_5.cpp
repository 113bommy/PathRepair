#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
const long double E = 1e-9;
unsigned char ccc;
bool _minus = false;
template <typename T>
inline T sqr(T t) {
  return (t * t);
}
inline void read(long long &n) {
  n = 0;
  _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') break;
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
}
inline bool read(int &n) {
  n = 0;
  _minus = false;
  while (true) {
    ccc = getchar();
    if (ccc == ' ' || ccc == '\n') {
      if (ccc == '\n') return true;
      break;
    }
    if (ccc == '-') {
      _minus = true;
      continue;
    }
    n = n * 10 + ccc - '0';
  }
  if (_minus) n *= -1;
  return false;
}
char wwww[19];
int kkkk;
inline void write(long long y) {
  long long x = y;
  kkkk = 0;
  if (x < 0) {
    putchar('-');
    x *= -1;
  }
  if (!x) {
    ++kkkk;
    wwww[kkkk] = '0';
  } else
    while (x) {
      ++kkkk;
      wwww[kkkk] = char(x % 10 + '0');
      x /= 10;
    }
  for (int i = kkkk; i >= 1; --i) putchar(wwww[i]);
}
const int MAX = 53;
long long ar[MAX];
bool dp[MAX][MAX];
int n, k;
bool check(long long mask) {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = true;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      if (dp[i][j]) {
        long long sum = 0;
        for (int z = i + 1; z <= n; z++) {
          sum += ar[z];
          if ((sum & mask) == mask) {
            dp[z][j + 1] = true;
          }
        }
      }
    }
  }
  return dp[n][k];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  srand((unsigned int)time(NULL));
  cout.precision(10);
  cout << fixed;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
  }
  long long ans = 0;
  for (int i = 49; i >= 0; i--) {
    if (check(ans | (1LL << i))) {
      ans |= (1LL << i);
    }
  }
  cout << ans << "\n";
}
