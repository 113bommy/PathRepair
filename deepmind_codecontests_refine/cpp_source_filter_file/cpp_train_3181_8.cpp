#include <bits/stdc++.h>
using namespace std;
int f1[20 + 1][100100];
int f2[20 + 1][100100];
int a[100100];
int lg[100100];
int n;
int ask1(int l, int r) {
  int x = lg[r - l + 1];
  return max(f1[x][l], f1[x][r - (1 << x) + 1]);
}
int ask2(int l, int r) {
  int x = lg[r - l + 1];
  return min(f2[x][l], f2[x][r - (1 << x) + 1]);
}
int ask(int l, int r) { return ask1(l, r) - ask2(l, r); }
int main() {
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f1[0][i] = a[i];
    f2[0][i] = a[i];
  }
  n++;
  f1[0][n] = f2[0][n] = a[n] = 0x3f3f3f3f;
  for (int _ = 1; _ <= 20; _++) {
    for (int j = 1; j <= n; j++) {
      if (j + (1 << _ - 1) > n)
        f1[_][j] = f1[_ - 1][j];
      else
        f1[_][j] = max(f1[_ - 1][j], f1[_ - 1][j + (1 << _ - 1)]);
    }
    for (int j = 1; j <= n; j++) {
      if (j + (1 << _ - 1) > n)
        f2[_][j] = f2[_ - 1][j];
      else
        f2[_][j] = min(f2[_ - 1][j], f2[_ - 1][j + (1 << _ - 1)]);
    }
  }
  for (int i = 1; i <= n; i++) {
    lg[i] = log2(i);
  }
  stringstream ss;
  int M = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    int l = i;
    int r = n + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (ask(i, mid) > k)
        r = mid;
      else
        l = mid + 1;
    }
    if (l - i > M) {
      ss.str("");
      M = l - i;
      ss << i << ' ' << l - 1 << endl;
      tot = 1;
    } else if (l - i == M) {
      ss << i << ' ' << l - 1 << endl;
      tot++;
    }
  }
  cout << M << ' ' << tot << endl;
  cout << ss.str();
}
