#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const long long int nax = 1e5 + 5;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n), b(n, 0), c(n);
  vector<vector<long long int> > v(n);
  for (auto &x : a) cin >> x;
  ;
  if (n < 3) {
    for (auto x : a) cout << x << " ";
    cout << "\n";
    ;
    return;
  }
  for (long long int i = 0; i < n; i++) {
    if (i == 0) {
      if (i + 1 < n && a[i + 1] < a[i]) b[i] = 1;
    } else if (i == n - 1) {
      if (i - 1 >= 0 && a[i] > a[i - 1]) b[i] = 1;
    } else {
      if (a[i] > a[i + 1] && a[i] > a[i - 1]) b[i] = 1;
    }
  }
  vector<long long int> mxv;
  long long int mx = 0;
  for (long long int ia = 0; ia < n; ia++) {
    if (b[ia] == 1) {
      vector<long long int> t = a;
      long long int i = ia + 1, j = ia - 1;
      while (i + 1 < n) {
        if (a[i + 1] > a[i]) a[i + 1] = a[i];
        i++;
      }
      while (j - 1 >= 0) {
        if (a[j - 1] > a[j]) a[j - 1] = a[j];
        j--;
      }
      long long int fs = accumulate(a.begin(), a.end(), 0LL);
      if (fs > mx) {
        mxv = a;
        mx = fs;
      }
      a = t;
    }
  }
  for (auto x : mxv) cout << x << " ";
  cout << "\n";
  ;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
