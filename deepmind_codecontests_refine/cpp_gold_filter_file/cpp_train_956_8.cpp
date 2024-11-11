#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const long double pi = acosl(-1);
const int mod = 998244353;
const int mod1 = 1e9 + 7;
mt19937_64 rnd(time(0));
void faster() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
}
signed main() {
  faster();
  double start = clock();
  int n, m, d;
  cin >> n >> m >> d;
  d--;
  vector<long long> a(m);
  vector<long long> pr(m + 1, 0);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    pr[i + 1] = pr[i] + a[i];
  }
  vector<long long> ans(n);
  long long prev = n;
  int lol = m;
  for (int i = m - 1; i >= 0; i--) {
    long long start = max(prev - d - a[i], pr[i]);
    prev = start;
    for (int j = start; j < start + a[i]; j++) ans[j] = lol;
    lol--;
  }
  lol = 0;
  while (lol + 1 < n && ans[lol] == 0) {
    lol++;
  }
  if (lol > d)
    cout << "NO";
  else {
    cout << "YES"
         << "\n";
    for (auto i : ans) cout << i << " ";
  }
  return 0;
}
