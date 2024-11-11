#include <bits/stdc++.h>
using namespace std;
long long k, x, n, m;
long long d[8][51];
int f(int t, int n) {
  if (n <= 2) {
    if (t == 0 || t == 1) return n;
    if (2 <= t && t <= 5) return 0;
    if (t == 6) return n == 1;
    return n == 2;
  }
  if (d[t][n] >= 0) return d[t][n];
  if (t == 0)
    return d[t][n] = f(t, n - 2);
  else if (t == 1)
    return d[t][n] = f(t, n - 1);
  else if (t == 2)
    return d[t][n] = f(t, n - 1) + f(t, n - 2) +
                     (f(1, n - 2) == 1 && f(0, n - 1) == 1);
  else if (t == 3)
    return d[t][n] = f(t, n - 1) + f(t, n - 2) +
                     (f(1, n - 2) == 1 && f(0, n - 1) == 2);
  else if (t == 4)
    return d[t][n] = f(t, n - 1) + f(t, n - 2) +
                     (f(1, n - 2) == 2 && f(0, n - 1) == 1);
  else if (t == 5)
    return d[t][n] = f(t, n - 1) + f(t, n - 2) +
                     (f(1, n - 2) == 2 && f(0, n - 1) == 2);
  else
    return d[t][n] = f(t, n - 1) + f(t, n - 2);
}
int main() {
  memset(d, -1, sizeof(d));
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k >> x >> n >> m;
  long long c11 = f(2, k), c12 = f(3, k), c21 = f(4, k), c22 = f(5, k),
            c1 = f(6, k), c2 = f(7, k);
  vector<long long> v;
  v.push_back(c12);
  v.push_back(c22);
  v.push_back(c21);
  v.push_back(c11);
  for (int i = 0; i < (1 << 4); i++) {
    if ((i & (1 << 1)) && m == 1) continue;
    if ((i & (1 << 3)) && n == 1) continue;
    if ((i & (1 << 0)) && (i & (1 << 2)) && (n == 1 || m == 1)) continue;
    long long r1, r2;
    if ((i & (1 << 3)) || ((i & (1 << 0)) && (i & (1 << 2))))
      r1 = (n - 2) / 2;
    else if ((i & (1 << 0)) || (i & (1 << 2)))
      r1 = (n - 1) / 2;
    else
      r1 = n / 2;
    if ((i & (1 << 1)) || ((i & (1 << 0)) && (i & (1 << 2))))
      r2 = (m - 2) / 2;
    else if ((i & (1 << 0)) || (i & (1 << 2)))
      r2 = (m - 1) / 2;
    else
      r2 = m / 2;
    long long sum = 0;
    for (int j = 0; j < 4; j++) {
      if (i & (1 << j)) sum += v[j];
    }
    for (long long t1 = 0; t1 <= r1; t1++) {
      for (long long t2 = 0; t2 <= r2; t2++) {
        if (sum + t1 * c1 + t2 * c2 == x) {
          string s1 = "", s2 = "";
          if ((i & (1 << 2)) || (i & (1 << 3))) s1 += 'C';
          if ((i & (1 << 0)) || (i & (1 << 1))) s2 += 'C';
          for (int j = 0; j < t1; j++) s1 += "AC";
          for (int j = 0; j < t2; j++) s2 += "AC";
          if ((i & (1 << 0)) || (i & (1 << 3))) s1 += 'A';
          if ((i & (1 << 1)) || (i & (1 << 2))) s2 += 'A';
          while (s1.size() < n) {
            if (!s1.empty() && s1[0] == 'C')
              s1.insert(s1.begin() + 1, 'X');
            else
              s1.insert(s1.begin(), 'X');
          }
          while (s2.size() < m) {
            if (!s2.empty() && s2[0] == 'C')
              s2.insert(s2.begin() + 1, 'X');
            else
              s2.insert(s2.begin(), 'X');
          }
          cout << s1 << "\n" << s2 << "\n";
          return 0;
        }
      }
    }
  }
  cout << "Happy new year!\n";
  return 0;
}
