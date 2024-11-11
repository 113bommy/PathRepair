#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 1e6 + 5;
int n, a[N];
void code() {
  cin >> n;
  vector<int> cnt(3 * N);
  for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
  for (int i = 0; i < 3e6; i++) {
    int x = cnt[i] / 2;
    if (x) {
      cnt[i] -= x * 2;
      cnt[i + 1] += x;
    }
  }
  int ans = 0;
  for (int i = 0; i <= 3e6; i++) ans += (cnt[i] == 1);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  while (t-- > 0) {
    code();
  }
}
