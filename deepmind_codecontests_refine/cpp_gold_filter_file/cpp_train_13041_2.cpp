#include <bits/stdc++.h>
using namespace std;
const int maxp = 18;
const long double EPS = 1e-18;
const long long INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 2e5 + 1;
void yesno(bool a) {
  if (a) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
long long power(long long x, long long n, long long m) {
  if (n == 0) return 1;
  long long u = power(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2) u = (u * x) % m;
  return u;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  int n = s.size(), i;
  int arr[n + 1];
  for (i = 0; i < n; i++) arr[i] = s[i] - 'a' + 1;
  arr[n] = 0;
  unsigned long long hsh[n + 1][maxp];
  int siz[n + 1], lift[n + 1][maxp], go[n + 1];
  int j;
  for (i = 0; i < maxp; i++) {
    hsh[n][i] = 0;
    lift[n][i] = n;
  }
  for (i = 0; i <= n; i++) {
    go[i] = i;
  }
  siz[n] = 0;
  unsigned long long pp[n + 1];
  unsigned long long q = 31;
  pp[0] = 1;
  for (i = 1; i <= n; i++) {
    pp[i] = pp[i - 1] * q;
  }
  for (i = n - 1; i >= 0; i--) {
    int x = go[i + 1];
    siz[i] = siz[x] + 1;
    lift[i][0] = x;
    hsh[i][0] = arr[i];
    for (j = 1; j < maxp; j++) {
      int y = lift[i][j - 1];
      lift[i][j] = lift[y][j - 1];
      hsh[i][j] = hsh[i][j - 1] * pp[min(1 << (j - 1), n)] + hsh[y][j - 1];
    }
    if (i + 1 < n && arr[i] == arr[i + 1]) {
      int x = go[i];
      int y = go[i + 2];
      for (j = maxp - 1; j >= 0; j--) {
        if (hsh[x][j] == hsh[y][j]) {
          x = lift[x][j];
          y = lift[y][j];
        }
      }
      if (arr[y] < arr[x]) {
        go[i] = go[go[i + 2]];
        siz[i] = siz[go[i]];
      }
    }
  }
  for (i = 0; i < n; i++) {
    cout << siz[i] << " ";
    int until = siz[i];
    if (siz[i] > 10) until = 5;
    int x = go[i];
    for (j = 0; j < until; j++) {
      cout << s[x];
      x = lift[x][0];
    }
    if (siz[i] > 10) {
      cout << "...";
      int k = siz[i] - 7;
      for (j = maxp - 1; j >= 0; j--) {
        if (k >= (1 << j)) {
          k -= (1 << j);
          x = lift[x][j];
        }
      }
      for (j = 0; j < 2; j++) {
        cout << s[x];
        x = lift[x][0];
      }
    }
    cout << '\n';
  }
}
