#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
inline int readInt() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 300003;
long long dp[2][61][61];
int bitcount(long long x) {
  int ret = 0;
  while (x) {
    if (x & 1LL) ret++;
    x >>= 1;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  dp[0][0][0] = 1LL;
  long long ret = 0;
  for (int i = 0; i < (int)n; ++i) {
    memset(dp[(i + 1) & 1], 0, sizeof(dp[(i + 1) & 1]));
    dp[(i + 1) & 1][0][0] = 1;
    long long x;
    cin >> x;
    int b = bitcount(x);
    for (int j = 0; j < (int)61; ++j) {
      for (int k = j; k <= 60; k += 2) {
        int y;
        if (j - b <= 0 && k - b <= 0)
          y = (j + b) % 2;
        else
          y = min(abs(j - b), abs(k - b));
        dp[(i + 1) & 1][y][min(b + k, 60 - (b + k) % 2)] += dp[i & 1][j][k];
      }
    }
    for (int j = 1; j < (int)61; ++j) ret += dp[(i + 1) & 1][0][j];
  }
  cout << ret << endl;
  return 0;
}
