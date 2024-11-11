#include <bits/stdc++.h>
using namespace std;
const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
  if (rsz <= 0) {
    ptr = 0;
    rsz = fread(bf, 1, bfsz, stdin);
    if (rsz <= 0) return EOF;
  }
  --rsz;
  return bf[ptr++];
}
void ga(char &c) {
  c = EOF;
  while (!isalpha(c)) c = gc();
}
int gs(char s[]) {
  int l = 0;
  char c = gc();
  while (isspace(c)) c = gc();
  while (c != EOF && !isspace(c)) {
    s[l++] = c;
    c = gc();
  }
  s[l] = '\0';
  return l;
}
template <class T>
bool gi(T &v) {
  v = 0;
  char c = gc();
  while (c != EOF && c != '-' && !isdigit(c)) c = gc();
  if (c == EOF) return false;
  bool neg = c == '-';
  if (neg) c = gc();
  while (isdigit(c)) {
    v = v * 10 + c - '0';
    c = gc();
  }
  if (neg) v = -v;
  return true;
}
bool exitInput = false;
int ntest = 1, itest = 1;
const int dx[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
const int dy[8] = {+1, -1, +2, -2, +2, -2, +1, -1};
const long long Mod = 1e9 + 7;
const int maxn = 200 + 5;
const int maxv = 1e5 + 2;
const int maxe = 1 + 5;
int n, p[maxn], cnt[maxn], f[maxn][2];
vector<int> adj[maxn];
int dp(int idx, int cross) {
  int &ref = f[idx][cross];
  if (ref != -1) return ref;
  ref = 0;
  int i, j, k;
  if (cross == 1) {
    return ref = (dp(idx - 1, 0) + 1) % Mod;
  } else {
    k = (dp(idx, 1) - dp(p[idx], 1)) % Mod;
    return ref = (dp(idx, 1) % Mod + 1 + k) % Mod;
  }
}
void brute() {
  int cur = 1, next;
  long long res = 0;
  while (cur != n + 1) {
    cnt[cur]++;
    if (cnt[cur] & 1) {
      cur = p[cur];
    } else {
      ++cur;
    }
    res = (res + 1) % Mod;
  }
  cout << "BRUTE: " << res << endl;
}
void pre() {}
void read() {
  gi(n);
  int i;
  for (i = 1; i <= n; ++i) {
    gi(p[i]);
    adj[p[i]].push_back(i);
  }
}
void solve() {
  memset(f, -1, sizeof(f));
  f[1][1] = 0;
  f[1][0] = 1;
  int res = dp(n, 0);
  res = (res + 1) % Mod;
  printf("%d\n", res);
}
int main() {
  pre();
  for (itest = 1; itest <= ntest; ++itest) {
    read();
    if (exitInput) {
      break;
    }
    solve();
  }
  return 0;
}
