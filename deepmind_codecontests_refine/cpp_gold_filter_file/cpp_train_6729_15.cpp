#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int p[N];
int n, ans[N];
void solveNotAnd(int n) {
  if (n & 1) {
    puts("NO");
    return;
  }
  int mx = 1;
  cout << "YES\n";
  while (mx <= n) mx = mx + mx;
  mx /= 2;
  for (; n; n = mx + mx - n - 2) {
    while (mx > n) mx /= 2;
    for (int i = mx, j = mx - 1; i <= n; i++, j--) p[i] = j, p[j] = i;
  }
  for (int i = 1; p[i]; i++) cout << p[i] << ' ';
  cout << '\n';
}
int fix[] = {0, 7, 3, 6, 5, 1, 2, 4};
bool solveAnd(int n) {
  if (n < 6 || n == (n & -n)) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  if (n == 6) {
    cout << "3 6 2 5 1 4\n";
  } else if (n == 7) {
    cout << "7 3 6 5 1 2 4\n";
  } else {
    for (int i = 1; i <= 7; i++) p[i] = fix[i];
    for (int l = 8; l < n; l = l + l) {
      int r = l + l - 1;
      r = min(r, n);
      for (int i = l; i < r; i++) p[i] = i + 1;
      p[r] = l;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
  }
}
int main() {
  int n;
  while (cin >> n) {
    solveNotAnd(n);
    solveAnd(n);
  }
  return 0;
}
