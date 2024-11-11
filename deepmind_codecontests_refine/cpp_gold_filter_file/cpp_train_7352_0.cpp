#include <bits/stdc++.h>
using namespace std;
const int N = 1000010, MOD = 1000000007;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int n, ar[N];
bool flag[N] = {true};
vector<pair<int, int> > v;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    if (i) {
      if (ar[i] == 0) continue;
      v.push_back({max(1, i - ar[i]), i - 1});
    }
  }
  sort(v.begin(), v.end());
  int ans = n;
  if (v.size()) {
    int l = v[0].first, r = v[0].second;
    for (int i = 1; i < v.size(); i++) {
      if (v[i].first <= r) {
        r = max(r, v[i].second);
      } else {
        ans -= r - l + 1;
        l = v[i].first, r = v[i].second;
      }
    }
    ans -= r - l + 1;
  }
  cout << ans;
  return 0;
}
