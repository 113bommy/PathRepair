#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long int ind[N], a[N], l[N], r[N], fen[N], ans[N];
vector<long long int> v[N], d[N];
void upd(int x) {
  for (int i = x; i <= N - 100; i += i & (-i)) fen[i]++;
}
long long int sum(int x) {
  long long int ret = 0;
  for (int i = x; i > 0; i -= i & (-i)) ret += fen[i];
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  long long int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ind[a[i]] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      v[max(ind[i], ind[j])].emplace_back(min(ind[i], ind[j]));
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    d[r[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j : v[i]) upd(j);
    for (int j : d[i]) {
      ans[j] = sum(r[j]) - sum(l[j] - 1);
    }
  }
  for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
