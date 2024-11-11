#include <bits/stdc++.h>
using namespace std;
void RI(int& x) {
  x = 0;
  char c = getchar();
  while (!(c >= '0' && c <= '9' || c == '-')) c = getchar();
  bool flag = 1;
  if (c == '-') {
    flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (!flag) x = -x;
}
void RII(int& x, int& y) { RI(x), RI(y); }
void RIII(int& x, int& y, int& z) { RI(x), RI(y), RI(z); }
void RC(char& c) {
  c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
}
char RC() {
  char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
const long long mod = 1e9 + 7;
const long long LINF = 1e18;
const int INF = 1e9;
const double EPS = 1e-8;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int main() {
  int n;
  RI(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  int sum = 0;
  int ttt = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i] & 1) {
      sum++;
      ttt = i;
    }
  }
  if (sum > 1) {
    cout << 0 << endl;
    return 0;
  }
  int R = 1;
  for (int i = n; i >= 1; i--) {
    if (i > (n + 1) / 2) {
      c[a[i]]++;
      if (c[a[i]] > b[a[i]] / 2) {
        R = i;
        break;
      }
    } else {
      if (a[i] != a[n - i + 1]) {
        R = i;
        break;
      }
    }
  }
  if (n & 1) {
    if (a[n / 2 + 1] != ttt) {
      R = max(R, n / 2 + 1);
    }
  }
  long long ans = n - R + 1;
  for (int L = 2; L <= n; L++) {
    R = max(L, R);
    if (L - 1 < (n) / 2 + 1) {
      if (a[L - 1] != a[n - L + 2]) {
        R = max(R, n - L + 2);
      }
      d[a[L - 1]]++;
      if (d[a[L - 1]] > b[a[L - 1]] / 2) {
        break;
      }
    } else {
      if (a[L - 1] != a[n - L + 2]) {
        break;
      }
    }
    ans += n - R + 1;
  }
  cout << ans << endl;
}
