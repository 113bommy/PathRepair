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
int n;
int h[1024], ph[1024];
int v[1024], pv[1024];
vector<pair<pair<int, int>, pair<int, int>>> ansl;
int main() {
  FILEIO();
  Read(n);
  for (int(i) = 1; (i) <= (n); ++(i)) {
    Read(h[i]);
    ph[h[i]] = i;
  }
  for (int(i) = 1; (i) <= (n); ++(i)) {
    Read(v[i]);
    pv[v[i]] = i;
  }
  for (int(i) = 1; (i) <= (n); ++(i)) {
    if (h[i] == i and v[i] == i) continue;
    ansl.push_back({{ph[i], i}, {i, pv[i]}});
    int vh = ph[i];
    swap(h[i], h[vh]);
    ph[h[i]] = i;
    ph[h[vh]] = vh;
    int vv = pv[i];
    swap(v[i], v[vv]);
    pv[v[i]] = i;
    pv[v[vv]] = vv;
  }
  printf("%d\n", ansl.size());
  for (auto [p1, p2] : ansl) {
    printf("%d %d %d %d\n", p1.first, p1.second, p2.first, p2.second);
  }
  END();
}
