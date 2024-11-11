#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) cin >> x;
  return in;
}
template <typename T>
ostream& operator<<(ostream& in, vector<T>& v) {
  for (auto& x : v) in << x << " ";
  return in;
}
long long fast(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= static_cast<long long>(1e9 + 7);
    }
    b >>= 1;
    a *= a;
    a %= static_cast<long long>(1e9 + 7);
  }
  return ans;
}
class solve {
 public:
  solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > v(n, vector<int>(m));
    cin >> v;
    int Mov = 0, Sco = 0;
    for (int i = 0; i < m; i++) {
      int a[] = {0, 0};
      for (int j = 0; j < k; j++) {
        a[v[j][i]]++;
      }
      int mv = 0, sc = a[1], cm = 0;
      for (int j = k; j < n; j++) {
        a[v[j][i]]++;
        a[v[j - k][i]]--;
        if (a[v[j - k][i]]) cm++;
        if (a[1] > sc) {
          sc = a[1];
          mv = cm;
        }
      }
      Mov += mv;
      Sco += sc;
    }
    cout << Sco << " " << Mov;
  }
};
int32_t main() {
  int t = 1, i = 1;
  if (0) scanf("%d", &t);
  while (t--) {
    if (0) printf("Case #%d: ", i++);
    new solve;
  }
  return 0;
}
