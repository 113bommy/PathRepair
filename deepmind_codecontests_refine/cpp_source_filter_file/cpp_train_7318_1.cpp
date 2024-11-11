#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long int lxt() {
  long long int aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
int ar[105][105];
int mx[105][105];
int go(int x, int t) {
  int mx = 0;
  int sum = 0;
  for (int i = 0; i < t + 1; i++) {
    int c = i;
    if (i) sum += ar[x][i];
    int last = ar[x][0];
    int tot = 0;
    for (int j = last; c < t; j--, c++) {
      tot += ar[x][j];
    }
    mx = max(mx, tot + sum);
  }
  return mx;
}
int dp[105][105];
int n;
int come(int pos, int k) {
  if (k == 0) return 0;
  if (pos > n) return -1e9;
  int &res = dp[pos][k];
  if (res != -1) return res;
  res = 0;
  for (int i = 0; i < ar[pos][0] + 1; i++) {
    if (k >= i) res = max(res, come(pos + 1, k - i) + mx[pos][i]);
  }
  return res;
}
int main() {
  n = nxt();
  int m = nxt();
  for (int i = 1; i < n + 1; i++) {
    int x = nxt();
    ar[i][0] = x;
    for (int j = 1; j < x + 1; j++) ar[i][j] = nxt();
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < ar[i][0] + 1; j++) {
      mx[i][j] = go(i, j);
    }
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", come(1, m));
  return 0;
}
