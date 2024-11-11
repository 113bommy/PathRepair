#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int n, cnt, sum, a[N], c[N], F[N];
void Add() {
  int curr = 0;
  for (int i = 1; i <= 7; i++) curr = curr * 10 + c[i];
  cnt++, a[cnt] = curr;
}
void quasi(int i) {
  if (i > 7) {
    Add();
    return;
  }
  for (int j = 0; j <= 1; j++) {
    c[i] = j;
    quasi(i + 1);
  }
}
void Solve() {
  for (int i = 1; i <= n; i++) F[i] = 1e8;
  for (int i = 1; i <= cnt; i++) F[a[i]] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= cnt; j++) {
      if (a[j] <= i)
        F[i] = min(F[i], F[i - a[j]] + 1);
      else
        break;
    }
  }
  cout << F[n] << '\n';
  int t = n;
  for (int i = F[n] - 1; i >= 1; i--) {
    for (int j = 1; j <= cnt; j++) {
      if (F[t - a[j]] == i && n - a[j] >= 0) {
        cout << a[j] << " ";
        sum += a[j], t -= a[j];
        break;
      }
    }
  }
  cout << n - sum << '\n';
}
int main() {
  cin >> n;
  quasi(1);
  Solve();
  return 0;
}
