#include <bits/stdc++.h>
using namespace std;
long long int r, c;
char a[1001][1001];
pair<long long int, long long int> p1, p2;
queue<pair<long long int, long long int> > q;
template <class T>
T max3(const T &a, const T &b, const T &c) {
  return max(a, max(b, c));
}
template <class T>
T min3(const T &a, const T &b, const T &c) {
  return min(a, min(b, c));
}
template <class T>
T gcd(const T a, const T b) {
  return (b ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(const T a, const T b) {
  return (a / gcd<T>(a, b) * b);
}
int main() {
  long long int n, m, i = 0, j = 0, k = 0, ans = 0;
  cin >> n;
  long long int p[n];
  map<long long int, long long int> m1, m2;
  for (i = 0; i < n; i++) {
    long long int b;
    cin >> p[i] >> b;
    m1[p[i]] = b;
  }
  cin >> m;
  long long int q[m];
  for (i = 0; i < m; i++) {
    long long int b;
    cin >> q[i] >> b;
    m2[q[i]] = b;
  }
  for (i = 0; i < n; i++) {
    if (((m2).find(p[i]) != (m2).end())) {
      if (m2[p[i]] <= m1[p[i]]) ans += m1[p[i]];
    } else
      ans += m1[p[i]];
  }
  for (i = 0; i < m; i++) {
    if (((m1).find(q[i]) != (m1).end())) {
      if (m1[q[i]] < m2[q[i]]) ans += m2[q[i]];
    } else
      ans += m2[q[i]];
  }
  cout << ans << endl;
  return 0;
}
