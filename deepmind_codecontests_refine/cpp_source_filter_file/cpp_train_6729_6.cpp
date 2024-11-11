#include <bits/stdc++.h>
using namespace std;
int getK(int n) {
  int t = 1;
  for (; t <= n; t *= 2) {
  }
  return t / 2;
}
int res[100005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, t, i, j, a, b, k, l, tn;
  cin >> n;
  {
    if (n % 2 == 1) {
      cout << "NO\n";
    } else {
      tn = n;
      while (getK(tn) > 1) {
        t = getK(tn);
        for (i = 1; i <= tn - t + 1; i++) {
          a = t + i - 1;
          b = t - i;
          res[a] = b;
          res[b] = a;
        }
        tn = t * 2 - tn - 2;
      }
      cout << "YES\n";
      for (i = 1; i <= n; i++) {
        cout << res[i] << " ";
      }
      cout << "\n";
    }
  }
  {
    if (n < 6 || getK(n) == n) {
      cout << "NO\n";
    } else if (n == 6) {
      cout << "YES\n";
      cout << "3 6 2 5 1 4\n";
    } else {
      res[1] = 7;
      res[2] = 3;
      res[3] = 6;
      res[4] = 5;
      res[5] = 1;
      res[6] = 2;
      res[7] = 4;
      for (t = 16; t <= n; t *= 2) {
        res[t / 2] = t - 1;
        for (i = t / 2 + 1; i < t; i++) {
          res[i] = i - 1;
        }
      }
      res[t / 2] = n;
      for (i = t / 2 + 1; i < n; i++) {
        res[i] = i - 1;
      }
      cout << "YES\n";
      for (i = 1; i <= n; i++) {
        cout << res[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
