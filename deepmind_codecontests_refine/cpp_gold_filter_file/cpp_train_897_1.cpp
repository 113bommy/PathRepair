#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ul = unsigned long long;
const int maxN = 1e6 + 1;
const int mod = 1e9 + 7;
const lli infty = 1e18;
void FastInput() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
void InputFile() {
  freopen("a.INP", "r", stdin);
  freopen("a.OUT", "w", stdout);
}
int n, m;
int a[maxN];
int mn[maxN];
int mark[maxN];
void Read() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void Solve() {
  lli res(0);
  mn[1] = 1;
  mark[1] = 1;
  for (int i = 2; i <= n; i++) {
    mn[i] = max(mn[i - 1], a[i] + 1);
  }
  mark[n] = mn[n];
  for (int i = n - 1; i > 1; i--) {
    mark[i] = max(mn[i], mark[i + 1] - 1);
  }
  for (int i = 1; i <= n; i++) {
    res += mark[i] - a[i] - 1;
  }
  cout << res;
}
void Debug() {}
int main() {
  FastInput();
  int test;
  test = 1;
  while (test--) {
    Read();
    Solve();
  }
}
