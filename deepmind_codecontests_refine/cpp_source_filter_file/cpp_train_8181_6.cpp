#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
const string a[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int n;
int A[1 << 10];
int dp[1 << 10][1 << 10];
int p[1 << 10][1 << 10];
int f(int k, int first) {
  if (k == n - 1) {
    if (first != k) return max(A[first], A[n - 1]);
    return A[k];
  }
  if (k == n - 2 && first == n - 2) return max(A[k], A[k + 1]);
  if (k == n) {
    if (first == k) return 0;
    return A[first];
  }
  if (dp[k][first] == -1) {
    int& res = dp[k][first];
    res = inf;
    if (k == first) {
      int tt = max(A[k], A[k + 1]) + f(k + 2, k + 2);
      if (tt < res) {
        res = tt;
        p[k][first] = 0;
      }
      tt = max(A[k], A[k + 2]) + f(k + 3, k + 1);
      if (tt < res) {
        res = tt;
        p[k][first] = 1;
      }
      tt = max(A[k + 1], A[k + 2]) + f(k + 3, k);
      if (tt < res) {
        res = tt;
        p[k][first] = 1;
      }
    } else {
      int tt = max(A[first], A[k]) + f(k + 1, k + 1);
      if (tt < res) {
        res = tt;
        p[k][first] = 0;
      }
      tt = max(A[first], A[k + 1]) + f(k + 2, k);
      if (tt < res) {
        res = tt;
        p[k][first] = 1;
      }
      tt = max(A[k], A[k + 1]) + f(k + 2, first);
      if (tt < res) {
        res = tt;
        p[k][first] = 1;
      }
    }
  }
  return dp[k][first];
}
int main() {
  memset(dp, -1, sizeof(dp));
  memset(p, -1, sizeof(p));
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  cout << f(0, 0) << endl;
  int k = 0, first = 0;
  while (1) {
    switch (p[k][first]) {
      case -1:
        if (k == n - 1) {
          if (first != k)
            cout << first + 1 << " " << n << endl;
          else
            cout << n << endl;
          return 0;
        }
        if (k == n - 2 && first == n - 2) {
          cout << n - 1 << " " << n << endl;
          return 0;
        }
        if (k == n) {
          if (first == k) return 0;
          cout << first + 1 << endl;
          return 0;
        }
        break;
      case 0:
        if (k == first) {
          cout << k + 1 << " " << k + 2 << endl;
          k = k + 2;
          first = k;
        } else {
          cout << first + 1 << " " << k + 1 << endl;
          k = k + 1;
          first = k;
        }
        break;
      case 1:
        if (k == first) {
          cout << k + 1 << " " << k + 3 << endl;
          first = k + 1;
          k = k + 3;
        } else {
          cout << first + 1 << " " << k + 2 << endl;
          first = k;
          k = k + 2;
        }
        break;
      case 2:
        if (k == first) {
          cout << k + 2 << " " << k + 3 << endl;
          first = k;
          k = k + 3;
        } else {
          cout << k + 1 << " " << k + 2 << endl;
          k = k + 2;
        }
        break;
    }
  }
  return 0;
}
