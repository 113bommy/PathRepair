#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const double eps = 1E-9;
const double Exp = 2.718281828459045;
const double Pi = 3.1415926535897932;
const int NMAX = 1000000 + 5;
const int MMAX = 100000 + 5;
const int INF = 1000000000;
const int BS = 1000000007;
template <typename T>
inline T abs(const T a) {
  if (a < 0) return -a;
  return a;
}
template <typename T>
inline T sqr(const T& a) {
  return a * a;
}
int ca = 0;
long long del[NMAX];
int cd = 0;
void go(long long x, int k) {
  if (ca >= 100000) return;
  if (x == 1 || 0 == k) {
    cout << x << " ";
    ca++;
    return;
  }
  long long i;
  for (i = 0; i < cd && del[i] * del[i] <= x && ca < 100000; i++) {
    if (x % del[i] == 0) {
      go(del[i], k - 1);
    }
  }
  i--;
  if (del[i] * del[i] == x) i--;
  for (; i >= 0 && ca < 100000; i--) {
    if (x % del[i] == 0) {
      go(x / del[i], k - 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  long long x, k;
  cin >> x >> k;
  long long i;
  for (i = 1; i * i <= x; i++) {
    if (x % i == 0) del[cd++] = i;
  }
  k = min(k, 100000ll);
  go(x, k);
  return 0;
}
