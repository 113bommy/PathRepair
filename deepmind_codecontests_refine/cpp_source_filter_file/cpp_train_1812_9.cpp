#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
long long int power(long long int a, long long int p, long long int m) {
  long long int re = 1;
  re %= m;
  for (; p; p >>= 1) {
    if (p & 1) re = re * a % m;
    a = a * a % m;
  }
  return re;
}
long long int inverseMOD(long long int a, long long int m) {
  return power(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, k;
  cin >> n >> m >> k;
  string s[n];
  for (long long int i = 0; i < n; i++) {
    cin >> s[i];
  }
  vector<pair<long long int, long long int> > v[160];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (s[i][j] == '.') continue;
      for (long long int k = 1; k < 150; k++) {
        long long int i1 = i - k;
        long long int i2 = i + k;
        long long int j1 = j - k;
        long long int j2 = j + k;
        if (i1 < 0 || j1 < 0 || i2 >= n || j2 >= m) break;
        if (s[i1][j] == '*' && s[i2][j] == '*' && s[i][j1] == '*' &&
            s[i][j2] == '*') {
          v[k - 1].push_back({i, j});
        }
      }
    }
  }
  long long int k1 = 0;
  for (long long int i = 0; i < 160; i++) {
    k1 += v[i].size();
    if (k1 >= k) {
      k1 -= v[i].size();
      long long int p = k - k1 - 1;
      vector<pair<long long int, long long int> > tmp = v[i];
      pair<long long int, long long int> res = tmp[p];
      cout << res.first + 1 << " " << res.second + 1 << endl;
      cout << res.first - i << " " << res.second + 1 << endl;
      cout << res.first + i + 2 << " " << res.second + 1 << endl;
      cout << res.first + 1 << " " << res.second - i << endl;
      cout << res.first + 1 << " " << res.second + i + 2 << endl;
      k1 += v[i].size();
      break;
    }
  }
  if (k1 < k) {
    cout << -1 << endl;
  }
}
