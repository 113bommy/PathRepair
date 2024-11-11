#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long LINF = 1e18;
const long double EPS = 1e-10;
const long double PI = 3.141592653589;
const int N = 1e6;
int d[N + 1];
int a[N + 1];
int b[N + 1];
void cut(int &x) {
  if (x >= 10) {
    x -= 10;
  }
  if (x < 0) {
    x += 10;
  }
}
void ans(int n) {
  fill(b, b + N, 0);
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    b[j] = a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < 0 || a[i] > 9 || b[i] < 0 || b[i] > 9) {
      return;
    }
  }
  int t = 0;
  for (int i = 0; i < N; i++) {
    int cur = a[i] + b[i] + t;
    if (cur % 10 != d[i]) {
      return;
    }
    t = cur / 10;
  }
  if (a[0] != 0) {
    for (int i = 0; i < n; i++) {
      cout << a[i];
    }
    cout << "\n";
    exit(0);
  }
  if (b[0] != 0) {
    for (int i = 0; i < n; i++) {
      cout << b[i];
    }
    cout << "\n";
    exit(0);
  }
}
void solve(int n) {
  fill(a, a + N, 0);
  int f = 0;
  int t = d[n];
  int end = n % 2 == 0 ? n / 2 : n / 2 + 1;
  for (int i = 0; i < end; i++) {
    int j = n - i - 1;
    int y1 = d[i];
    int y2 = d[j];
    int s = y1 - f;
    cut(s);
    int k = y2 - s;
    cut(k);
    int fs = 10 * t + y2 - k;
    a[i] = fs / 2;
    a[j] = fs - a[i];
    t = k;
    f = (fs + f) / 10;
  }
  ans(n);
}
int main() {
  ios::sync_with_stdio(false);
  float tbegin = clock();
  srand(42);
  if ("" != "") {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    d[(int)s.size() - i - 1] = s[i] - '0';
  }
  solve((int)s.size() - 1);
  solve((int)s.size());
  cout << "0\n";
  return 0;
}
