#include <bits/stdc++.h>
using namespace std;
int IOS = []() {
  ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
void dbg_out() { cerr << "\b\b )" << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << H << ", ";
  dbg_out(T...);
}
const int N = 5e5 + 5;
int a[N];
int n, m;
int z[N], zn = 0;
int t[N];
void prep_zs(int x) {
  int i, j;
  t[1] = 1;
  for (i = 2; i <= x; i++) {
    if (!t[i]) z[++zn] = i, t[i] = i;
    for (j = 1; i * z[j] <= x && j <= zn; j++) {
      t[i * z[j]] = z[j];
      if (i % z[j] == 0) break;
    }
  }
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) t[i] = i / t[i];
  sort(t + 1, t + n + 1);
  for (int i = 1; i < n; i++) cout << t[i] << " ";
  return;
}
void init() { prep_zs(50000); }
int main() {
  init();
  int _T = 1;
  while (_T--) {
    solve();
  };
  ;
  return 0;
}
