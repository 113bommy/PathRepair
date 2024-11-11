#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int maxn = 200005;
const int mod = 1000000007;
void task() {
  int n;
  cin >> n;
  std::vector<long long> a(n), b(n);
  std::map<long long, long long> cnt, same;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    cnt[b[i]]++;
    if (a[i] == b[i]) same[a[i]]++;
  }
  long long m;
  cin >> m;
  long long ans = 1;
  for (auto x : cnt) {
    long long now = 1;
    long long tot = same[x.first];
    long long N = x.second;
    for (long long i = 1; i <= N; i++) {
      long long p = i;
      while (p % 2 == 0 and tot > 0) {
        p /= 2;
        tot--;
      }
      now *= p;
      now %= m;
    }
    ans *= now;
    ans %= mod;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  for (int __ = 1; __ <= T; __++) {
    task();
  }
  return 0;
}
