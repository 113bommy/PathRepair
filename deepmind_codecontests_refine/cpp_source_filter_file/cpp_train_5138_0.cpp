#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:255000000")
bool firstout = 1;
template <class T>
T &minn(T &a, T b) {
  if (b < a) a = b;
  return a;
}
template <class T>
T &maxx(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int &madd(int &a, int b) {
  a += b;
  if (a >= 1000000009) a -= 1000000009;
  return a;
}
int &msub(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000009;
  return a;
}
int &mmult(int &a, int b) { return a = (long long)a * b % 1000000009; }
int mdiv(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  b = (b % m + m) % m;
  if (a % b == 0) return a / b;
  return (a + m * mdiv(-a, m, b)) / b;
}
int n, m;
int A[3][201234];
int AN[3];
int I[3];
int calc() {
  int res = 0;
  int i, j, r;
  for (i = (0); i < (n); ++i) {
    r = 0;
    for (j = (1); j < (AN[i]); ++j)
      if (A[i][j - 1] > A[i][j]) ++r;
    maxx(res, r);
  }
  return res;
}
void calcp() {
  int i, j;
  set<pair<int, int> > s;
  set<pair<int, int> >::iterator si;
  for (i = (0); i < (n); ++i) I[i] = 1, s.insert(make_pair(A[i][0], i));
  int p = -1;
  for (; s.size();) {
    si = s.find(make_pair(p, -1));
    if (si == s.end()) si = s.begin();
    p = si->first;
    i = si->second;
    printf("%d %d\n", p, i + 1);
    s.erase(si);
    if (I[i] < AN[i]) s.insert(make_pair(A[i][I[i]++], i));
  }
}
int main() {
  int i, j, k;
  char c;
  int a, d;
  int ts;
  for (ts = 1; scanf("%"
                     "d",
                     &(n)) > 0;
       ++ts) {
    int nn = 0;
    for (i = (0); i < (n); ++i) {
      int l, x, y;
      scanf(
          "%"
          "d",
          &(l));
      scanf(
          "%"
          "d",
          &(a));
      scanf(
          "%"
          "d",
          &(x));
      scanf(
          "%"
          "d",
          &(y));
      scanf(
          "%"
          "d",
          &(m));
      nn += l;
      AN[i] = l;
      A[i][0] = a;
      for (j = (1); j < (l); ++j) {
        a = ((long long)a * x + y) % m;
        A[i][j] = a;
      }
    }
    int res = calc();
    printf(
        "%"
        "d",
        (res));
    printf("\n"), firstout = 1;
    if (nn <= 200000) calcp();
  }
  return 0;
}
