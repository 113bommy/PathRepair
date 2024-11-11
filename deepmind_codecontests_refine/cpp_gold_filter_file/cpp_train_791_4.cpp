#include <bits/stdc++.h>
using namespace std;
long long n, i, j, ans = 0;
multiset<long long> m[4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x;
  cin >> n;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= 6; j++) cin >> x, m[i].insert(x);
  if (n == 3) {
    for (i = 1; i <= 999; i++) {
      if (i < 10) {
        if (m[1].find(i) == m[1].end() and m[2].find(i) == m[2].end() and
            m[3].find(i) == m[3].end())
          return cout << i - 1, 0;
      } else if (i < 100) {
        long long y = i / 10, z = i % 10;
        if (m[1].find(y) != m[1].end() and m[2].find(z) != m[2].end()) continue;
        if (m[1].find(z) != m[1].end() and m[2].find(y) != m[2].end()) continue;
        if (m[1].find(y) != m[1].end() and m[3].find(z) != m[3].end()) continue;
        if (m[2].find(y) != m[2].end() and m[3].find(z) != m[3].end()) continue;
        if (m[1].find(z) != m[1].end() and m[3].find(y) != m[3].end()) continue;
        if (m[2].find(z) != m[2].end() and m[3].find(y) != m[3].end()) continue;
        return cout << i - 1, 0;
      } else {
        long long y = i / 100, z = i % 10, x = (i / 10) % 10;
        if (m[1].find(x) != m[1].end() and m[2].find(y) != m[2].end() and
            m[3].find(z) != m[3].end())
          continue;
        if (m[1].find(x) != m[1].end() and m[3].find(y) != m[3].end() and
            m[2].find(z) != m[2].end())
          continue;
        if (m[2].find(x) != m[2].end() and m[1].find(y) != m[1].end() and
            m[3].find(z) != m[3].end())
          continue;
        if (m[2].find(x) != m[2].end() and m[3].find(y) != m[3].end() and
            m[1].find(z) != m[1].end())
          continue;
        if (m[3].find(x) != m[3].end() and m[1].find(y) != m[1].end() and
            m[2].find(z) != m[2].end())
          continue;
        if (m[3].find(x) != m[3].end() and m[2].find(y) != m[2].end() and
            m[1].find(z) != m[1].end())
          continue;
        return cout << i - 1, 0;
      }
    }
  } else if (n == 1) {
    for (i = 1; i <= 9; i++) {
      if (m[1].find(i) == m[1].end()) return cout << i - 1, 0;
    }
  } else if (n == 2) {
    for (i = 1; i <= 99; i++) {
      if (i <= 9) {
        if (m[1].find(i) != m[1].end()) continue;
        if (m[2].find(i) != m[2].end()) continue;
        return cout << i - 1, 0;
      } else {
        long long y = i / 10, z = i % 10;
        if (m[1].find(y) != m[1].end() and m[2].find(z) != m[2].end()) continue;
        if (m[1].find(z) != m[1].end() and m[2].find(y) != m[2].end()) continue;
        return cout << i - 1, 0;
      }
    }
  }
}
