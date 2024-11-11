#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
long long POW(long long a, long long p, long long M) {
  if (!p) return 1LL;
  long long T = POW(a, p / 2, M);
  T = T * T % M;
  if (p & 1) T = T * (a % M) % M;
  return T;
}
long long SQRT(long long a) {
  long long b = (long long)sqrtl(((double)a) + 0.5);
  while (b * b < a) ++b;
  while (b * b > a) --b;
  return (b * b == a) ? b : -1;
}
const long long MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) ok = 0;
    }
    if (!ok) {
      cout << -1 << endl;
      continue;
    }
    int fin[20][20];
    memset(fin, 0, sizeof(fin));
    for (int i = 0; i < n; i++) {
      fin[a[i] - 'a'][b[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      int cnt = -1;
      for (int j = i + 1; j < 20; j++) {
        if (fin[i][j] > 0) {
          cnt = j;
          break;
        }
      }
      if (cnt == -1) continue;
      ans++;
      for (int j = i + 1; j < 20; j++) {
        fin[cnt][j] += fin[i][j];
      }
    }
    cout << ans << endl;
  }
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
