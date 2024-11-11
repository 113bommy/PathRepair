#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (signed i = 0; i < n; i++) cin >> a[i];
  vector<std::pair<long long, long long> > ans;
  ans.reserve(n * n / 2 + 1);
  vector<long long> b(n);
  iota(b.begin(), b.end(), 0);
  sort(b.begin(), b.end(), [&](long long i, long long j) {
    if (a[i] == a[j]) return i < j;
    return a[i] < a[j];
  });
  for (signed j = 0; j < n; j++) {
    for (signed i = 0; i < n - 1; i++) {
      if (b[i + 1] < b[i]) {
        ans.emplace_back(b[i + 1], b[i]);
        swap(b[i], b[i + 1]);
      }
    }
  }
  cout << ans.size() << '\n';
  for (const auto &x : ans) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
}
signed main(signed argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && (string)argv[1] == "local") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    while (cin.peek() != EOF) {
      if (isspace(cin.peek()))
        cin.get();
      else {
        cout << '\n';
        solve();
      }
    }
  } else {
    solve();
  }
  return 0;
}
