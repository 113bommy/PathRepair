#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1e5 + 100, mod = 1e9 + 7, mxs = 100000;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (int i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i];
  os << '\n';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  for (int i = 0; i < v.size(); i++) os << v[i];
  os << '\n';
  return os;
}
long long max(long long a, int b) { return a > b ? a : b; }
long long max(int a, long long b) { return a > b ? a : b; }
long long bp(long long b, long long p) {
  if (p <= 0) return 1;
  return p % 2 ? b * bp(b * b, p / 2) : bp(b * b, p / 2);
}
void solve() {
  long long n, k, t, m;
  char a[3] = {'R', 'G', 'B'};
  cin >> t;
  while (t--) {
    string s;
    m = 0;
    long long sum[3] = {0, 0, 0};
    cin >> n >> k;
    cin >> s;
    for (long long i = 0; i < n; i++) {
      for (long long i1 = 0; i1 < 3; i1++) {
        if (s[i] == a[(i + i1) % 3]) sum[i1]++;
        if (i >= k) {
          if (s[i - k] == a[(i + i1 - k) % 3]) sum[i1]--;
        }
        if (i >= (k - 1)) m = max(sum[i1], m);
      }
    }
    cout << k - m << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
