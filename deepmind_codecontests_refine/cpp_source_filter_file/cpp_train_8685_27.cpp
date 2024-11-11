#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int getX(long long t) {
  for (int i = 1; i * i <= t; i++) {
    long long sum = t + i * i;
    long long c = sqrt(sum * 1.0) + 1e-9;
    if (c * c == sum) return i;
  }
  return -1;
}
int main() {
  int n, m;
  cin >> n >> m;
  if (n + m == 2) {
    cout << 1 << endl;
    return 0;
  }
  long long sum = n - 1;
  int t = 2;
  int x;
  long long a[101];
  long long b[101];
  while (1) {
    for (int i = 1; i < n; i++) {
      x = getX(sum);
      if (x != -1) {
        for (int j = 1; j < i; j++) {
          a[j] = t;
        }
        for (int j = i; j < n; j++) {
          a[j] = t - 1;
        }
        a[n] = x;
        break;
      }
      sum += t + t - 1;
    }
    if (n == 1) a[1] = x = 1;
    if (x != -1) break;
    t++;
  }
  sum = m - 1;
  while (1) {
    for (int i = 1; i < m; i++) {
      x = getX(sum);
      if (x != -1) {
        for (int j = 1; j < i; j++) {
          b[j] = t;
        }
        for (int j = i; j < m; j++) {
          b[j] = t - 1;
        }
        b[m] = x;
        break;
      }
      sum += t + t - 1;
    }
    if (m == 1) b[1] = x = 1;
    if (x != -1) break;
    t++;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j > 1) cout << ' ';
      cout << a[i] * b[j];
    }
    cout << endl;
  }
  return 0;
}
