#include <bits/stdc++.h>
using namespace std;
const long long prime = 1e9 + 7;
const long long maxN = 1e5 + 5;
const long double pi = 3.1415926536;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, u, v, cnt[1001], ans = 0;
  cin >> n;
  for (long long i = (long long)(1); i <= (long long)(n - 1); i++) {
    cin >> u >> v;
    cnt[u]++;
    cnt[v]++;
  }
  for (long long i = (long long)(1); i <= (long long)(n); i++) {
    if (cnt[i] == 1) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
