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
int ar[105][105], br[105][105], com[105][105];
vector<int> row, clm;
int main() {
  int n = nxt();
  int m = nxt();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) ar[i][j] = nxt(), br[i][j] = ar[i][j];
  for (int i = 0; i < n; i++) sort(br[i], br[i] + m);
  bool f = 0;
  if (n < m) {
    for (int i = 0; i < n; i++) {
      int x = br[i][0];
      while (x) row.push_back(i), x--;
      for (int j = 0; j < m; j++) com[i][j] += br[i][0];
    }
    for (int i = 0; i < m; i++) {
      int x = max(0, ar[0][i] - com[0][i]);
      int y = x;
      while (x) clm.push_back(i), x--;
      for (int j = 0; j < n; j++) {
        com[j][i] += y;
        if (com[j][i] != ar[j][i]) f = 1;
      }
    }
  } else {
    for (int i = 0; i < m; i++) {
      int mn = 505;
      for (int j = 0; j < n; j++) {
        mn = min(mn, ar[j][i]);
      }
      int x = mn;
      while (x) clm.push_back(i), x--;
      for (int j = 0; j < n; j++) com[j][i] += mn;
    }
    for (int i = 0; i < n; i++) {
      int x = max(0, ar[i][0] - com[i][0]);
      int y = x;
      while (x) row.push_back(i), x--;
      for (int j = 0; j < n; j++) {
        com[i][j] += y;
        if (com[i][j] != ar[i][j]) f = 1;
      }
    }
  }
  if (f)
    puts("-1");
  else {
    printf("%d\n", (int)row.size() + clm.size());
    for (int i = 0; i < row.size(); i++) printf("row %d\n", row[i] + 1);
    for (int i = 0; i < clm.size(); i++) printf("col %d\n", clm[i] + 1);
  }
  return 0;
}
