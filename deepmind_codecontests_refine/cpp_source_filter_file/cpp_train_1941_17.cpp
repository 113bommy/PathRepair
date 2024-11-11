#include <bits/stdc++.h>
#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const int inf = (int)2e9, mod = (int)1e9 + 7;
const long long linf = (long long)2e18;
const int maxn = (int)5e5 + 1;
const int maxn2 = (int)1e6 + 1;
int n, a[maxn], q;
int l, r;
string get(bool x) {
  if (x) return "Odd";
  return "Even";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < i; ++j)
      if (a[i] < a[j]) ++cnt;
  cnt %= 2;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> l >> r;
    int len = (r - l + 1);
    if (len % 4 == 2 || len % 4 == 3) cnt ^= 1;
    cout << get(cnt) << "\n";
  }
  exit(0);
}
