#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
int n, k, m, a[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> m;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n, greater<int>());
  double sum = 0, bst = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    if (n - i - 1 <= m)
      bst = max(bst, (sum + min(m - (n - i - 1), (i + 1) * k)) / (i + 1));
  }
  cout << setprecision(15) << fixed << bst;
}
