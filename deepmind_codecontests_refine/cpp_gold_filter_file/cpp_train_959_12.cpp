#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
const int N = 4e5 + 5;
long long f(vector<int> &b, int limit) {
  long long res = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    while (l <= r && b[r] + b[l] > limit) r--;
    if (l > r) break;
    res += r - l;
    l++;
  }
  return res;
}
long long solve(vector<int> &b, int L, int R) { return f(b, R) - f(b, L - 1); }
bool ok(int k) {
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = a[i] % (1 << (k + 1));
  }
  sort(b.begin(), b.end());
  return (solve(b, (1 << k), (1 << (k + 1)) - 1) +
          solve(b, (1 << (k + 1)) + (1 << k), 1000000000)) %
         2;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  a.resize(n);
  for (auto &x : a) cin >> x;
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (ok(i)) ans += (1 << i);
  }
  cout << ans << endl;
  return 0;
}
