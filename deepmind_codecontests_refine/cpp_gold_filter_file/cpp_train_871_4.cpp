#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const int LEVEL = log2(N) + 1;
long long test = 1, n, vis[N];
map<long long, int> g;
int grundy[30] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6,  2, 1, 8, 7,  5,
                  9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
void solve() {
  cin >> n;
  long long left = n, ans = 0;
  for (int i = 2; i * i <= n; i++) {
    if (vis[i]) continue;
    int ct = 0;
    for (long long j = i; j <= n; j *= i, ct++)
      if (j < N) vis[j] = 1;
    left -= ct;
    ans ^= grundy[ct];
  }
  ans ^= grundy[left % 2];
  cout << ((ans) ? "Vasya" : "Petya") << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
