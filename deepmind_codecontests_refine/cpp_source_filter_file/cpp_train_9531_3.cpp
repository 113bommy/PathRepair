#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxn = (int)1e3 + 10;
const int inf = (int)2e9;
const int mod = (int)1e9 + 7;
const long long llinf = (long long)1e18 + 5;
long long gcd(long long x, long long y) {
  while (x && y) {
    if (x > y)
      x %= y;
    else
      y %= x;
  }
  return x + y;
}
int n;
long long k;
pair<int, long long> dp[maxn][6520];
pair<int, long long> p[maxn][6520];
void operator delete(void* x) {}
void operator delete[](void* x) {}
int a[50], b[6520][50], c[50];
long long pw[50][50];
int main() {
  n = nextInt<int>();
  k = nextInt<long long>();
  if (k == 1) {
    int j = 0;
    long long x = llinf;
    for (int i = (0); i < (n); i++) {
      long long y;
      cin >> y;
      if (y < x) x = y, j = i;
    }
    cout << 1 << endl << j + 1 << endl;
    return 0;
  }
  long long y = k;
  vector<long long> f;
  for (long long i = 2; i * i <= y; ++i) {
    if (y % i == 0) {
      f.push_back(i);
      long long mul = 1;
      pw[((int)(f).size()) - 1][0] = 1;
      while (y % i == 0) {
        mul *= i;
        a[((int)(f).size()) - 1]++;
        pw[((int)(f).size()) - 1][a[((int)(f).size()) - 1]] = mul;
        y /= i;
      }
    }
  }
  if (y > 1) {
    f.push_back(y);
    pw[((int)(f).size()) - 1][0] = 1;
    pw[((int)(f).size()) - 1][1] = y;
    a[((int)(f).size()) - 1] = 1;
  }
  for (int i = (0); i < (maxn); i++)
    for (int j = (0); j < (6520); j++) dp[i][j] = make_pair(-1, -1);
  dp[0][0] = make_pair(0, 0);
  vector<long long> d;
  for (long long i = 1; i * i <= k; ++i) {
    if (k % i == 0) {
      d.push_back(i);
      if (i * i != k) d.push_back(k / i);
    }
  }
  unordered_map<long long, int> pos;
  sort((d).begin(), (d).end());
  int N = ((int)(f).size());
  for (int i = (0); i < (((int)(d).size())); i++) {
    long long x = d[i];
    for (int k = (0); k < (N); k++) {
      while (x % f[k] == 0) {
        b[i][k]++;
        x /= f[k];
      }
    }
    pos[d[i]] = i;
  }
  for (int i = (1); i < (n + 1); i++) {
    long long x;
    x = nextInt<long long>();
    long long y = x;
    for (int k = (0); k < (N); k++) {
      c[k] = 0;
      while (y % f[k] == 0) {
        c[k]++;
        y /= f[k];
      }
    }
    for (int j = (0); j < (((int)(d).size())); j++)
      dp[i][j] = dp[i - 1][j], p[i][j] = p[i - 1][j];
    for (int j = (0); j < (((int)(d).size())); j++) {
      if (dp[i - 1][j].first == -1) continue;
      long long val = 1;
      for (int k = (0); k < (N); k++) {
        int cc = min(a[k], b[j][k] + c[k]);
        val *= pw[k][cc];
      }
      pair<int, long long> nd =
          make_pair(dp[i - 1][j].first + 1, dp[i - 1][j].second + x);
      int idx = pos[val];
      if (dp[i][idx] > nd || dp[i][idx].first == -1) {
        dp[i][idx] = nd;
        p[i][idx] = make_pair(j, dp[i - 1][j].second);
      }
    }
  }
  int idx = ((int)(d).size()) - 1;
  for (int j = (n)-1; j >= (1); j--)
    if (dp[j][idx] == dp[n][idx]) n = j;
  if (dp[n][idx].first == -1) {
    printf("%d\n", -1);
    return 0;
  }
  vector<int> ans;
  while (n > 0) {
    ans.push_back(n);
    for (int j = (0); j < (n); j++) {
      if (dp[j][p[n][idx].first] ==
          make_pair(dp[n][idx].first - 1, p[n][idx].second)) {
        idx = p[n][idx].first;
        n = j;
        break;
      }
    }
  }
  printf("%d\n", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); i++) printf("%d ", ans[i]);
  return 0;
}
