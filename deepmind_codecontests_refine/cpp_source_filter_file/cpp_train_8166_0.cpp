#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcountll(s);
}
const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
  if (rsz <= 0) {
    ptr = 0;
    rsz = (int)fread(bf, 1, bfsz, stdin);
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
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
string s;
int n;
int a[5005], b[5005], c[5005][5005], f[5005][5005];
void zfunc(int n, int v[], int z[]) {
  int l = 0, r = -1;
  z[0] = 0;
  for (int i = (1); i <= (n - 1); ++i) {
    int k = (i > r) ? 0 : min(z[i - l], r - i + 1);
    while (i + k < n && v[k] == v[i + k]) ++k;
    z[i] = k;
    if (i + k - 1 > r) {
      l = i;
      r = i + k - 1;
    }
  }
  z[0] = n;
}
int cal(int i) {
  int RR = 0;
  for (int j = i; j < n; j++) RR = (RR + RR + a[j]) % 1000000007;
  RR = (RR + f[i][n]) % 1000000007;
  return RR;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  n = ((int)(s).size());
  for (int i = 0; i < (n); ++i) a[i] = s[i] - '0';
  a[n] = 1;
  int z[5005];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      b[j - i] = a[j];
    }
    zfunc(n - i, b, z);
    for (int j = i + 1; j < n; j++) {
      int k = j + j - i, d = j - i;
      if (k > n) continue;
      if (z[d] >= d || (z[d] < d && a[i + z[d]] < a[j + z[d]])) {
        c[i][j] = 1;
      }
    }
  }
  memset(f, 0, sizeof(f));
  for (int i = (1); i <= (n); ++i)
    if (a[i]) f[0][i] = 1;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      int run = i - 1, RR = 0;
      for (int j = i + 1; j <= n; j++) {
        while (run >= 0 &&
               (i - run < j - i || (run + j == i + i && c[run][i]))) {
          if (a[i] == 1) RR = (RR + f[run][i]) % 1000000007;
          run--;
        }
        f[i][j] = RR;
      }
    }
  int RR = 0;
  for (int i = n - 1; i >= 0; i--) {
    RR = (RR + f[i][n]) % 1000000007;
  }
  cout << RR << endl;
  memset(f, 0x3f, sizeof(f));
  for (int i = (1); i <= (n); ++i)
    if (a[i]) f[0][i] = 1;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      int run = i - 1, RR = 1000000005;
      for (int j = i + 1; j <= n; j++) {
        while (run >= 0 &&
               (i - run < j - i || (run + j == i + i && c[run][i]))) {
          if (a[i] == 1) RR = min(RR, f[run][i] + 1);
          run--;
        }
        f[i][j] = min(f[i][j], RR);
      }
    }
  bool ok = true;
  for (int i = n - 1; i >= 0; i--)
    if (f[i][n] < 1000000005) {
      if (n - i < 20) {
        ok = true;
      }
    }
  int res;
  if (ok) {
    res = 1000000005;
    for (int i = n - 1; i >= 0; i--)
      if (f[i][n] < 1000000005 && n - i < 20) {
        res = min(res, cal(i));
      }
  } else {
    for (int i = n - 1; i >= 0; i--)
      if (f[i][n] < 1000000005) {
        res = cal(i);
        break;
      }
  }
  cout << res << endl;
  return 0;
}
