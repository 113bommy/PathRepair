#include <bits/stdc++.h>
#pragma comment(linker, "/stack:102400000,102400000")
using namespace std;
int f_abs(int x) { return x < 0 ? -x : x; }
int lowbit(int x) { return (x & -x); }
int f_max(int a, int b) { return a > b ? a : b; }
int f_min(int a, int b) { return a < b ? a : b; }
int gcd(int a, int b) {
  while (int t = a % b) a = b, b = t;
  return b;
}
bool isdig(char ch) { return ch >= '0' && ch <= '9'; }
bool isup(char ch) { return ch >= 'A' && ch <= 'Z'; }
bool islow(char ch) { return ch >= 'a' && ch <= 'z'; }
void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}
const double eps = 1e-9;
const int mod = 1000000007;
const int inf = 0x7fffffff;
const int N = 1003;
int n, m;
char s[N][N], res[N][N];
void init() {}
void get_data() {
  for (int i = 0; i < n; ++i) cin >> s[i];
}
bool checkr(char a, char b, char c, char d) {
  char x, y, ch;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0)
      x = a, y = b;
    else
      x = c, y = d;
    bool flag = true;
    for (int j = 0; j < m; ++j) {
      if (j % 2 == 0)
        ch = x;
      else
        ch = y;
      res[i][j] = ch;
      if (s[i][j] != '0' && s[i][j] != ch) {
        flag = false;
        break;
      }
    }
    if (flag) continue;
    for (int j = 0; j < m; ++j) {
      if (j % 2 == 1)
        ch = x;
      else
        ch = y;
      res[i][j] = ch;
      if (s[i][j] != '0' && s[i][j] != ch) return false;
    }
  }
  return true;
}
bool checkc(char a, char b, char c, char d) {
  char x, y, ch;
  for (int j = 0; j < m; ++j) {
    if (j % 2 == 0)
      x = a, y = b;
    else
      x = c, y = d;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0)
        ch = x;
      else
        ch = y;
      res[i][j] = ch;
      if (s[i][j] != '0' && s[i][j] != ch) {
        flag = false;
        break;
      }
    }
    if (flag) continue;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 1)
        ch = x;
      else
        ch = y;
      res[i][j] = ch;
      if (s[i][j] != '0' && s[i][j] != ch) return false;
    }
  }
  return true;
}
void disp() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << res[i][j];
    cout << endl;
  }
}
void solve() {
  if (checkr('1', '2', '3', '4')) {
    disp();
    return;
  }
  if (checkr('1', '3', '2', '4')) {
    disp();
    return;
  }
  if (checkr('1', '4', '2', '3')) {
    disp();
    return;
  }
  if (checkr('2', '3', '1', '4')) {
    disp();
    return;
  }
  if (checkr('2', '4', '1', '3')) {
    disp();
    return;
  }
  if (checkr('3', '4', '1', '2')) {
    disp();
    return;
  }
  if (checkc('1', '2', '3', '4')) {
    disp();
    return;
  }
  if (checkc('1', '3', '2', '4')) {
    disp();
    return;
  }
  if (checkc('1', '4', '2', '3')) {
    disp();
    return;
  }
  if (checkc('2', '3', '1', '4')) {
    disp();
    return;
  }
  if (checkc('2', '4', '1', '3')) {
    disp();
    return;
  }
  if (checkc('3', '4', '1', '2')) {
    disp();
    return;
  }
  cout << 0 << endl;
}
int main() {
  while (cin >> n >> m) {
    init();
    get_data();
    solve();
  }
  return 0;
}
