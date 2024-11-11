#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-3;
const int inf = 1000000000;
const long long linf = 1000000000000000000LL;
template <class T>
inline T sqr(T x) {
  return x * x;
}
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
char src[110][11000];
int ar[110][11000];
int n, m;
int main() {
  cin >> n >> m;
  gets(src[0]);
  for (int i = 0; i < (n); ++i) {
    gets(src[i]);
    bool f = false;
    for (int j = 0; j < (m); ++j) {
      src[i][j] -= '0';
      if (src[i][j]) f = true;
    }
    if (!f) {
      cout << -1;
      exit(0);
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = 0; j < (m); ++j) {
      ar[i][j] = inf;
    }
    for (int j = 0; j < (m + m); ++j) {
      if (!src[i][j % m]) continue;
      ar[i][j % m] = 0;
      for (int k = j + 1; !src[i][k % m]; ++k) {
        ar[i][k % m] = min(ar[i][k % m], k - j);
      }
    }
    reverse(src[i], src[i] + m);
    reverse(ar[i], ar[i] + m);
    for (int j = 0; j < (m + m); ++j) {
      if (!src[i][j % m]) continue;
      ar[i][j % m] = 0;
      for (int k = j + 1; !src[i][k % m]; ++k) {
        ar[i][k % m] = min(ar[i][k % m], k - j);
      }
    }
  }
  int r = inf;
  for (int j = 0; j < (m); ++j) {
    int s = 0;
    for (int i = 0; i < (n); ++i) {
      s += ar[i][j];
    }
    r = min(r, s);
  }
  cout << r;
  return 0;
}
