#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
void fixPrecision(ostream &cout, int prec = 10) {
  cout.precision(prec);
  cout << fixed << showpoint;
}
template <class T>
inline void opt(T &a, T b) {
  a = max(a, b);
}
inline int rndInt(int x) { return rnd() % x; }
inline int R(int l, int r) { return l + rndInt(r - l + 1); }
char Cur;
inline char getChar() {
  char t = Cur;
  Cur = getchar();
  return t;
}
template <class telem>
inline void readInt(telem &a) {
  a = 0;
  while (!isdigit(Cur) && Cur != '-') getChar();
  telem mlt = 1;
  if (Cur == '-') {
    mlt = -1;
    getChar();
  }
  while (isdigit(Cur)) {
    a *= 10;
    a += getChar() - '0';
  }
  a *= mlt;
}
template <class T1, class T2>
inline void readInt(T1 &a, T2 &b) {
  readInt(a);
  readInt(b);
}
template <class T1, class T2, class T3>
inline void readInt(T1 &a, T2 &b, T3 &c) {
  readInt(a);
  readInt(b);
  readInt(c);
}
void readToken(string &t) {
  t.clear();
  while (isspace(Cur)) getChar();
  while (!isspace(Cur) && Cur != EOF) t += getChar();
}
void pre() {}
int n, a, b;
string ans[1111];
void load() { readInt(n, a, b); }
void build(int v, int cnt) {
  int r = v + cnt - 1;
  for (int i = v; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      ans[i][j] = ans[j][i] = '1';
    }
  }
}
void build(int cnt) {
  int v = 0;
  int lst = n;
  while (cnt > 1) {
    build(v, 1);
    lst--;
    v++;
    cnt--;
  }
  build(v, lst);
}
void stupid() {
  if (n == 1) {
    cout << "YES" << endl;
    cout << "0" << endl;
    exit(0);
  }
  if (n == 2 || n == 3) {
    cout << "NO" << endl;
    exit(0);
  }
  for (int i = 1; i < n; i++) {
    ans[i][i - 1] = ans[i - 1][i] = '1';
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  exit(0);
}
void revAns() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      ans[i][j] = '1' - ans[i][j] + '0';
    }
  }
}
void solve() {
  for (int i = 0; i < n; i++) {
    ans[i] = string(n, '0');
  }
  if (a == 1 && b == 1) {
    stupid();
  }
  if (min(a, b) > 1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  bool rev = false;
  if (a == 1) {
    rev = true;
    swap(a, b);
  }
  build(a);
  if (rev) revAns();
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  double st = clock();
  int T = 1;
  while (T-- > 0) {
    load();
    solve();
  }
  return 0;
}
