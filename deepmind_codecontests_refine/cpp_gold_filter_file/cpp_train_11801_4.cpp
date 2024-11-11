#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(int &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid < x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(long long &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid < x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
int n, m, l, k, i, j, id, dp[1 << 15][16 * 16], nxt[500005][16], cnt,
    ans = 0x3bbbbbbb, ans2 = 0x3bbbbbbb;
string st;
map<string, int> ha;
vector<int> seq[16];
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin >> n;
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      cin >> st;
      ha[st] = i;
    }
  cin >> m;
  if ((1) <= ((m)))
    for (((id)) = (1); ((id)) <= ((m)); ((id))++) {
      cin >> l;
      if ((1) <= ((l)))
        for (((j)) = (1); ((j)) <= ((l)); ((j))++) {
          cin >> st;
          seq[id].push_back(ha[st] - 1);
        }
      memset(dp, 22, sizeof(dp));
      memset(nxt, 22, sizeof(nxt));
      for (j = l - 1; j >= 0; j--) {
        memcpy(nxt[j], nxt[j + 1], sizeof(nxt[j]));
        if (seq[id][j] >= 0) {
          nxt[j][seq[id][j]] = j;
        }
      }
      dp[0][0] = -1;
      for (i = 0; i < (1 << n); i++) {
        for (j = 0; j <= n * (n - 1) / 2; j++) {
          for (k = 0; k < n; k++) {
            if (dp[i][j] > l) continue;
            if ((1 << k) & i) continue;
            int ni = i | (1 << k);
            int nj = j + __builtin_popcount(i >> k);
            dp[ni][nj] = min(dp[ni][nj], nxt[dp[i][j] + 1][k]);
          }
        }
      }
      for (j = 0; j <= n * (n - 1) / 2; j++)
        if (dp[(1 << n) - 1][j] < l) {
          if (j < ans) {
            ans = j;
            ans2 = id;
          }
        }
    }
  if (ans2 > 100) return cout << "Brand new problem!", 0;
  cout << ans2 << "\n[:";
  if ((1) <= ((n * (n - 1) / 2 + 1 - ans)))
    for (((i)) = (1); ((i)) <= ((n * (n - 1) / 2 + 1 - ans)); ((i))++)
      cout << "|";
  cout << ":]\n";
  return 0;
}
