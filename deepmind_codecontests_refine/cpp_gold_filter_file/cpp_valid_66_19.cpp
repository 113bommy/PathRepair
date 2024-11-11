#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
void read(vector<long long int> &a, int n) {
  a.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
}
bool fine = 1;
vector<long long int> a, b;
long long int n, m, k, x, y, p, q, u, v;
long long int d;
void solve() {
  cin >> n;
  int c = 0;
  for (int i = 1; i <= 2000; i++) {
    if (i % 3 == 0 || i % 10 == 3) continue;
    ++c;
    if (c == n) {
      cout << i << "\n";
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fine) {
    int t;
    cin >> t;
    while (t--) {
      solve();
    }
  } else
    solve();
  return 0;
}
