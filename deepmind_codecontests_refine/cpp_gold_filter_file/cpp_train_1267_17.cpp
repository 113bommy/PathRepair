#include <bits/stdc++.h>
using namespace std;
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
bool CMP(int a, int b) { return a > b; }
template <class T>
inline bool fastread(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a;
  for (int I = 0; I < n; I++) {
    int X;
    scanf("%d", &X);
    a.push_back(X);
  };
  for (int i = 0; i < n; i++) {
    int mn = a[i];
    for (int j = i - 1; j >= 0 and j >= i - x; j--) mn = min(mn, a[j]);
    for (int j = i + 1; j < n and j <= i + y; j++) mn = min(mn, a[j]);
    if (mn == a[i]) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  return 0;
}
