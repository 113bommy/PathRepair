#include <bits/stdc++.h>
#pragma GCC optimize("O500")
#pragma comment(linker, "/STACK:1677777216")
#pragma warning(default : 4)
using namespace std;
const double eps = 1e-12;
const int oo = 0x3F3F3F3F;
const long long ooLL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1000000007;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
void debpr(const T &);
template <typename T1, typename T2>
void debpr(const pair<T1, T2> &);
template <typename T1, typename T2>
void debpr(const vector<T1, T2> &);
template <typename T>
void debpr(const set<T> &);
template <typename T1, typename T2>
void debpr(const map<T1, T2> &);
template <typename T>
void prcont(T be, T en, const string &st, const string &fi, const string &mi) {
  debpr(st);
  bool ft = 0;
  while (be != en) {
    if (ft) debpr(mi);
    ft = 1;
    debpr(*be);
    ++be;
  }
  debpr(fi);
}
template <typename T>
void debpr(const T &a) {}
template <typename T1, typename T2>
void debpr(const pair<T1, T2> &p) {
  debpr("(");
  debpr(p.first);
  debpr(", ");
  debpr(p.second);
  debpr(")");
}
template <typename T1, typename T2>
void debpr(const vector<T1, T2> &a) {
  prcont(a.begin(), a.end(), "[", "]", ", ");
}
template <typename T>
void debpr(const set<T> &a) {
  prcont(a.begin(), a.end(), "{", "}", ", ");
}
template <typename T1, typename T2>
void debpr(const map<T1, T2> &a) {
  prcont(a.begin(), a.end(), "{", "}", ", ");
}
void deb(){};
template <typename T1>
void deb(const T1 &t1) {
  debpr(t1);
  debpr('\n');
}
template <typename T1, typename T2>
void deb(const T1 &t1, const T2 &t2) {
  debpr(t1);
  debpr(' ');
  debpr(t2);
  debpr('\n');
}
template <typename T1, typename T2, typename T3>
void deb(const T1 &t1, const T2 &t2, const T3 &t3) {
  debpr(t1);
  debpr(' ');
  debpr(t2);
  debpr(' ');
  debpr(t3);
  debpr('\n');
}
template <typename T1, typename T2, typename T3, typename T4>
void deb(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4) {
  debpr(t1);
  debpr(' ');
  debpr(t2);
  debpr(' ');
  debpr(t3);
  debpr(' ');
  debpr(t4);
  debpr('\n');
}
const double PI = acos(-1.);
long long Round(double x) { return x < 0 ? x - .5 : x + .5; }
template <typename T>
void ass(bool v, const T &x, string m = "Fail") {
  if (!v) {
    deb(m);
    deb(x);
    throw;
  }
}
int main() {
  void run();
  run();
  return 0;
}
void ex(int x) {
  printf("%d\n", x);
  exit(0);
}
void run() {
  int x, k = 12;
  scanf("%d", &x);
  if (x == 1) ex(1);
  if (x == 7) ex(0);
  if (x == 13) ex(1);
  if (x == 3) ex(0);
  if (x == 5) ex(0);
  if (x == 8) ex(1);
  if (x == 16) ex(0);
  if (x == 11) ex(0);
  if (x == 2) ex(0);
  if (x == 10) ex(1);
  if (x == 9) ex(1);
  if (x == 15) ex(1);
  if (x == 4) ex(1);
  if (x == 12) ex(0);
  if (x == 6) ex(0);
  if (x == 14) ex(1);
  if (x < k)
    while (1)
      ;
  if (x >= k) throw;
}
