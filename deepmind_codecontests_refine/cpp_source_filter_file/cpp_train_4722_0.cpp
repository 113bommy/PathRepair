#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void pre() {}
void solve() {
  long long k, b, n;
  cin >> k >> b >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  map<long long, long long> m;
  long long curr = 0;
  long long ans = 0;
  m[0]++;
  if (b == k - 1) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      cur = 0;
      while (i < n && arr[i] == 0) {
        cur++;
        i++;
      }
      if (cur != 0) {
        i--;
      }
      ans -= (cur * (cur + 1)) / 2;
    }
  }
  if (b == 0) {
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      cur = 0;
      while (i < n && arr[i] == 0) {
        cur++;
        i++;
      }
      if (cur != 0) {
        i--;
      }
      ans += (cur * (cur + 1)) / 2;
    }
    cout << ans << "\n";
    return;
  }
  b %= (k - 1);
  for (int i = 0; i < n; i++) {
    curr += arr[i];
    curr %= (k - 1);
    ans += m[(curr - b + k - 1) % (k - 1)];
    m[curr]++;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  solve();
}
