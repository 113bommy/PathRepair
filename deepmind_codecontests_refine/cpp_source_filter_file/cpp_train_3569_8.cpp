#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int n, a[N], p[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] ^ a[i];
  }
  set<pii> res;
  for (int i = 1; i <= n; i++) {
    int k = 31 - __builtin_clz(a[i]);
    long long sum = (1LL << k);
    long long s = 0;
    for (int j = i + 1; j < n && s < sum; j++) {
      s += (long long)a[j];
      if (s == (a[i] ^ a[j + 1])) {
        res.insert({i, j + 1});
      }
    }
    s = 0;
    for (int j = i - 1; j > 1 && s < sum; j--) {
      s += (long long)a[j];
      if (s == (a[i] ^ a[j - 1])) {
        res.insert({j - 1, i});
      }
    }
  }
  cout << res.size() << '\n';
  return 0;
}
