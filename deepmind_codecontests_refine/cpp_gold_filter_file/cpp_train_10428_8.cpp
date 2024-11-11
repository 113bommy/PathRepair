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
    while (!isdigit(c) && !isalpha(c) && c != '#' && c != '.' && c != '=' &&
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
const long long MOD = 998244353;
template <typename T>
T Mymo(const T &x) {
  return x >= MOD ? x - MOD : x;
}
template <typename T>
void Mymod(T &x) {
  x = x >= MOD ? x - MOD : x;
}
inline long long Pow(long long a, long long b, const long long p = MOD) {
  long long ret = 1;
  for (; b; a = a * a % p, b >>= 1LL)
    if (b & 1LL) ret = ret * a % p;
  return ret;
}
inline long long Inv(long long a, const long long p = MOD) {
  return Pow(a, p - 2LL, p);
}
const int MAXN = 1024;
int n, k;
int a[MAXN], mxa;
long long ansl[131072];
int dp[MAXN][MAXN], dpsum[MAXN][MAXN];
int Solve(int delta) {
  if (delta > mxa / (k - 1)) return 0;
  for (int(i) = 1; (i) <= (n); ++(i))
    for (int(j) = 1; (j) <= (k); ++(j)) dp[i][j] = dpsum[i][j] = 0;
  int pre = 0;
  int ans = 0;
  for (int(i) = 1; (i) <= (n); ++(i)) {
    while (pre != i - 1 and a[i] - a[pre + 1] >= delta) ++pre;
    for (int(j) = (2); (j) <= (((i) < (k) ? (i) : (k))); ++(j)) {
      if (j == 2)
        dp[i][j] = pre;
      else {
        if (pre) {
          dp[i][j] = dpsum[pre][j - 1];
          Mymod(dp[i][j]);
        }
      }
      dpsum[i][j] = Mymo(dpsum[i - 1][j] + dp[i][j]);
    }
    ans += dp[i][k];
    Mymod(ans);
  }
  return ans;
}
int main() {
  FILEIO();
  Read(n, k);
  Read(a, 1, n);
  sort(a + 1, a + 1 + n);
  mxa = a[n];
  for (int(i) = (0); (i) <= (mxa); ++(i)) {
    ansl[i] = Solve(i);
  }
  long long ans = 0;
  for (int(i) = (0); (i) <= (mxa); ++(i)) {
    long long cnt = ansl[i] - ansl[i + 1] + MOD;
    ans += cnt * i % MOD;
    Mymod(ans);
  }
  cout << ans << endl;
  END();
}
