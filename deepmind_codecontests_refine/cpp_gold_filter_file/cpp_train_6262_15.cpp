#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
long long me[5000][5000], b[5001], mod = 998244353;
long long power(long long t, long long x) {
  t = t % mod;
  long long r = 1;
  while (x != 0) {
    if (x & 1) r = (r * t) % mod;
    x >>= 1;
    t = (t * t) % mod;
  }
  return r;
}
long long call(int i, int j) {
  if (j == 0) return 1;
  if (i < 0) return 0;
  if (me[i][j] != -1) return me[i][j];
  me[i][j] = call(i - 1, j);
  long long s = (a[i] * b[n - j + 1]) % mod;
  s = (s * call(i - 1, j - 1)) % mod;
  me[i][j] = (me[i][j] + s) % mod;
  return me[i][j];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j;
  long long r = 0, s, p;
  for (i = 0; i < 5001; i++) b[i] = power(i, mod - 2);
  cin >> n;
  map<int, int> m;
  map<int, int>::iterator it;
  for (i = 0; i < n; i++) {
    cin >> j;
    m[j]++;
  }
  it = m.begin();
  while (it != m.end()) {
    a.push_back(it->second);
    it++;
  }
  memset(me, -1, sizeof(me));
  for (i = a.size() - 1; i >= 0; i--) {
    if (a[i] > 1) {
      s = a[i] * (a[i] - 1);
      for (j = i; j >= 0; j--) {
        p = call(i - 1, j);
        p = (p * s) % mod;
        p = (p * b[n - j]) % mod;
        p = (p * b[n - j - 1]) % mod;
        r = (r + p) % mod;
      }
    }
  }
  cout << r;
  return 0;
}
