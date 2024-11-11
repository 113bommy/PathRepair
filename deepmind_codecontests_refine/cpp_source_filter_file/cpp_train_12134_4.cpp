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
  int n;
  cin >> n;
  vector<int> a;
  for (int I = 0; I < n; I++) {
    int X;
    scanf("%d", &X);
    a.push_back(X);
  };
  int ans = -10000007, c = 1;
  for (int i = 1; i < n; i++) {
    ans = max(c, ans);
    if (a[i] > a[i - 1]) {
      c++;
      ans = max(c, ans);
    } else {
      c = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
