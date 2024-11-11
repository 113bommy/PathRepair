#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const int INF = 1 << 30;
template <typename T>
inline bool chkmax(T& aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T& aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
int rint();
char rch();
long long rlong();
const int mn = 5004;
class KMP {
 public:
  int fail[mn + 10];
  int memo[26][mn + 10];
  char p[mn];
  int gm;
  int dfa(int j, char x) {
    int oldj = j;
    int z = x - 'a';
    if (memo[z][j] != -1) {
      return memo[z][j];
    }
    ++j;
    while (j > 0 && x != p[j - 1]) {
      j = fail[j];
    }
    memo[z][oldj] = j;
    return j;
  }
  void buildfail() {
    int m = gm;
    int j = 0;
    for (int i = 1; i <= m; i++) {
      fail[i] = j;
      while (j > 0 && p[i - 1] != p[j - 1]) {
        j = fail[j];
      }
      j++;
    }
    fail[m + 1] = j;
  }
  void initstr(string pattern) {
    int m = pattern.length();
    gm = m;
    for (int i = 0; i < m; i++) p[i] = pattern[i];
    common_init();
  }
  void common_init() {
    int m = gm;
    for (int i = 0; i < 26; i++) {
      memset(memo[i], -1, sizeof(int) * (m + 2));
    }
    for (int i = 0; i <= m + 1; i++) fail[i] = 0;
    buildfail();
  }
};
int f[mn];
KMP k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  f[0] = 0;
  for (int x = 1; x < mn; x++) f[x] = INT_MAX;
  for (int x = 0; x < n; x++) {
    chkmin(f[x + 1], f[x] + a);
    k.initstr(s.substr(x));
    int maxgo = 0;
    int state = 0;
    for (int y = 0; y < x; y++) {
      state = k.dfa(state, s[y]);
      chkmax(maxgo, state);
    }
    chkmin(maxgo, n - x);
    for (int y = x + 1; y < x + 1 + maxgo; y++) {
      chkmin(f[y], f[x] + b);
    }
  }
  printf("%d\n", f[n]);
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int rint() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char rch() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong() {
  readAhead(32);
  long long x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
