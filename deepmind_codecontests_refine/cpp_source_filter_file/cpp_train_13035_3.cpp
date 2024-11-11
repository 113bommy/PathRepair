#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (!b) ? a : gcd(b, a % b);
}
int n, s, k;
int a[1005];
set<int> st;
void solve() {
  cin >> n >> s >> k;
  int tr = 1;
  st.clear();
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    st.insert(a[i]);
    if (a[i] == s) {
      tr = 0;
    }
  }
  if (tr) {
    cout << 0 << '\n';
  } else {
    for (int i = 0; i <= 500; i++) {
      if (!((st).find(max(s - i, 1)) != (st).end()) ||
          !((st).find(min(s + i, n)) != (st).end())) {
        cout << i << '\n';
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
