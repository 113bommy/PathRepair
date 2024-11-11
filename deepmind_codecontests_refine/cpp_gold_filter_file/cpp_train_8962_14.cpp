#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> input) {
  os << "(" << input.first << ", " << input.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> input) {
  for (auto t : input) os << t << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> input) {
  for (auto t : input) os << t << "\n";
  return os;
}
long long x[300002], y[300002], d[300002], ord[300002];
long long pref[300002], suff[300002], ans[300002];
bool cmp(int i, int j) { return d[i] < d[j]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    d[i] = x[i] - y[i];
    ord[i] = i;
  }
  sort(ord + 1, ord + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
  }
  for (int i = 1; i <= n; i++) {
    int in = ord[i];
    pref[i] = pref[i - 1] + x[in];
  }
  for (int i = n; i >= 1; i--) {
    int in = ord[i];
    suff[i] = suff[i + 1] + y[in];
  }
  for (int i = 1; i <= n; i++) {
    ans[ord[i]] =
        pref[i - 1] + suff[i + 1] + (i - 1) * y[ord[i]] + (n - i) * x[ord[i]];
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    int ians = min(x[l] + y[r], x[r] + y[l]);
    ans[l] -= ians;
    ans[r] -= ians;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
