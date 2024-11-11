#include <bits/stdc++.h>
using namespace std;
vector<int> pr;
void sieve(int n) {
  bool a[n + 1];
  memset(a, true, sizeof(a));
  for (int i = 2; i * i <= n; i++) {
    if (a[i]) {
      for (int j = i * i; j <= n; j += i) a[j] = false;
    }
    if (a[i]) pr.push_back(i);
  }
}
long long kmp(string s) {
  long long sz = (long long)s.size();
  vector<long long> lps(sz, 0);
  for (long long i = 1; i < sz; i++) {
    long long pred = lps[i - 1];
    while (pred > 0 && s[i] != s[pred]) {
      pred = lps[pred - 1];
    }
    lps[i] = pred + (s[i] == s[pred] ? 1 : 0);
  }
  return lps[sz - 1];
}
bool isp(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  if (n * r != m * c)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int a[n][m];
    memset(a, 0, sizeof(a));
    vector<pair<int, int> > v(m);
    for (long long i = 0; i < m; i++) {
      v[i].first = 0;
      v[i].second = i;
    }
    for (long long i = 0; i < n; i++) {
      for (int j = 0; j < r; j++) {
        sort(v.begin(), v.end());
        v[0].first = v[0].first + 1;
        a[i][v[0].second] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j];
      }
      cout << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
