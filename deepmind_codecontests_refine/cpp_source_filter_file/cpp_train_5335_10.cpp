#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int M = 1e9 + 7;
const double P = acos(-1);
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 10);
  int sum = 0;
  for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
  int v = 1;
  int sa = a[1];
  int i = 2, j = n, ln = a[i];
  while (i <= j) {
    int tp = 0;
    while (tp <= ln && j >= i) {
      tp += a[j];
      j--;
    }
    v++;
    ln = tp;
    if (j < i) break;
    tp = 0;
    while (tp <= ln && i <= j) {
      tp += a[i];
      i++;
    }
    sa += tp;
    v++;
    ln = tp;
    if (j < i) break;
  }
  cout << v << ' ' << sa << ' ' << sum - sa << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
