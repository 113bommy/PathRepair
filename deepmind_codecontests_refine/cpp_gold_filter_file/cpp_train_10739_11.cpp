#include <bits/stdc++.h>
using namespace std;
struct InputReader {
  char buf[1048576];
  int p;
  inline InputReader() { p = 1048576; }
  inline void Flush() {
    p = 0;
    fread(buf, 1, 1048576, stdin);
  }
  inline char C() {
    if (p >= 1048576) Flush();
    return buf[p++];
  }
  inline char Readnum() {
    char ch = C();
    while (!isdigit(ch) && ch != '-') ch = C();
    return ch;
  }
  inline void Readalpha(char &c) {
    c = C();
    while (!isalpha(c)) c = C();
  }
  int operator()() {
    int ans = 0, fu = 1;
    char ch = Readnum();
    if (ch == '-') fu = -1, ch = C();
    while (ch >= '0' && ch <= '9') {
      ans = ans * 10 + ch - '0';
      ch = C();
    }
    return ans * fu;
  }
  long long Readll() {
    long long ans = 0LL, fu = 1LL;
    char ch = Readnum();
    if (ch == '-') fu = -1LL, ch = C();
    while (ch >= '0' && ch <= '9') {
      ans = ans * 10LL + ch - '0';
      ch = C();
    }
    return ans * fu;
  }
  inline void Readstring(string &x) {
    x.clear();
    char ch = C();
    while (!isdigit(ch) && !isalpha(ch) && ch != '#' && ch != '.') ch = C();
    while (isdigit(ch) || isalpha(ch) || ch == '#' || ch == '.') {
      x += ch;
      ch = C();
    }
  }
  inline void Readchstring(char s[]) {
    int len = 0;
    char ch = C();
    while (!isdigit(ch) && !isalpha(ch)) ch = C();
    while (isdigit(ch) || isalpha(ch)) {
      s[len++] = ch;
      ch = C();
    }
    s[len] = '\0';
  }
  inline void Specialread(char &c) {
    c = C();
    while (!isdigit(c) && !isalpha(c) && c != '*' && c != '.' && c != '=' &&
           c != 'B')
      c = C();
  }
} In;
inline void Read(int &x) { x = In(); }
inline void Read(int &x, int &y) {
  x = In();
  y = In();
}
inline void Read(int &x1, int &x2, int &x3) {
  x1 = In();
  x2 = In();
  x3 = In();
}
inline void Read(int &x1, int &x2, int &x3, int &x4) {
  x1 = In();
  x2 = In();
  x3 = In();
  x4 = In();
}
inline void Read(long long &x) { x = In.Readll(); }
inline void Read(long long &x, long long &y) {
  x = In.Readll();
  y = In.Readll();
}
inline void Read(long long &x1, long long &x2, long long &x3) {
  x1 = In.Readll();
  x2 = In.Readll();
  x3 = In.Readll();
}
inline void Read(long long &x1, long long &x2, long long &x3, long long &x4) {
  x1 = In.Readll();
  x2 = In.Readll();
  x3 = In.Readll();
  x4 = In.Readll();
}
template <typename T>
void Read(T a[], int st, int ed) {
  for (int(i) = (st); (i) <= (ed); ++(i)) Read(a[i]);
}
inline void FILEIO() {}
inline void FILEIO(string pname) {
  freopen((pname + ".in").c_str(), "r", stdin);
  freopen((pname + ".out").c_str(), "w", stdout);
}
inline void FILEIO_OICONTEST(string pname) {
  freopen((pname + ".in").c_str(), "r", stdin);
  freopen((pname + ".out").c_str(), "w", stdout);
}
void Printtime() {}
void END() {
  Printtime();
  exit(0);
}
template <typename T>
void END(T mes) {
  cout << mes << endl;
  END();
}
template <typename T>
void Print(T a[], int s, int t, char sp = ' ', char ed = '\n') {
  if (s > t) return;
  for (int i = s; i < t; i++) cout << a[i] << sp;
  cout << a[t] << ed;
  cout.flush();
}
template <typename T>
void Print(T a, int s = 0, int t = -1, char sp = ' ', char ed = '\n') {
  if (t == -1) t = a.size() - 1;
  for (int i = s; i <= t; i++) cout << a[i] << sp;
  cout << ed;
  cout.flush();
}
vector<int> Range(int l, int r) {
  vector<int> ret{};
  for (int(i) = (l); (i) <= (r); ++(i)) ret.push_back(i);
  return ret;
}
mt19937 Rand(0xe38195e38293);
inline long long Pow(long long a, long long b,
                     const long long p = (998244353LL)) {
  long long ret = 1;
  for (; b; a = a * a % p, b >>= 1LL)
    if (b & 1LL) ret = ret * a % p;
  return ret;
}
inline long long Inv(long long a, const long long p = (998244353LL)) {
  return Pow(a, p - 2LL, p);
}
const int MAXM = 1048576;
const int MAXN = 1024;
int n, m;
int col[MAXM], nn;
vector<int> poses[MAXN];
long long dp[MAXN][MAXN];
long long Dfs(int l, int r) {
  if (l > r) return 1;
  if (~dp[l][r]) return dp[l][r];
  int mincol = (0x3f3f3f3f);
  for (int(i) = (l); (i) <= (r); ++(i)) (mincol) = min((mincol), (col[i]));
  if (poses[mincol][0] < l or poses[mincol].back() > r) return dp[l][r] = 0;
  long long ans = 1;
  int lastapp = -1;
  for (auto p : poses[mincol]) {
    if (lastapp != -1) (ans *= Dfs(lastapp + 1, p - 1)) %= (998244353LL);
    lastapp = p;
  }
  long long lsum = 0, rsum = 0;
  for (int(i) = (poses[mincol][0]); (i) >= (l); --(i))
    (lsum += Dfs(l, i - 1) * Dfs(i, poses[mincol][0] - 1)) %= (998244353LL);
  for (int(i) = (poses[mincol].back()); (i) <= (r); ++(i))
    (rsum += Dfs(poses[mincol].back() + 1, i) * Dfs(i + 1, r)) %= (998244353LL);
  ans = ans * lsum % (998244353LL) * rsum % (998244353LL);
  return dp[l][r] = ans;
}
int main() {
  FILEIO();
  memset(dp, -1, sizeof(dp));
  Read(n, m);
  for (int(i) = 1; (i) <= (m); ++(i)) {
    int c;
    Read(c);
    ;
    if (!nn or col[nn] != c) col[++nn] = c;
  }
  m = nn;
  if (m > 2 * n) END(0);
  for (int(i) = 1; (i) <= (m); ++(i)) poses[col[i]].push_back(i);
  long long ans = Dfs(1, m);
  cout << ans << endl;
  END();
}
