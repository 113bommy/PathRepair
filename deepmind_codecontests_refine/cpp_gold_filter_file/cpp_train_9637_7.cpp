#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= 1000000007) a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= 1000000007) res %= 1000000007;
    a = a * a;
    if (a >= 1000000007) a %= 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool contains[10];
int main() {
  memset(contains, false, sizeof contains);
  int x, y;
  for (int i = 0; i <= 9; i++) {
    string pr = to_string(i) + to_string(i) + to_string(i) + to_string(i);
    cout << pr << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
    if (x > 0) contains[i] = true;
  }
  int a[4];
  int c = 0;
  for (int i = 0; i < 10; i++) {
    if (contains[i]) a[c++] = i;
  }
  if (c == 4) {
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < c; j++) {
        if (j == i) continue;
        for (int k = 0; k < c; k++) {
          if (k == i || k == j) continue;
          for (int l = 0; l < c; l++) {
            if (l == k || l == j || l == i) continue;
            cout << a[i] << a[j] << a[k] << a[l] << "\n";
            fflush(stdout);
            cin >> x >> y;
            if (x == 4 && y == 0) {
              return 0;
            }
          }
        }
      }
    }
  } else if (c == 3) {
    int rep = 0, rep_k = 0, rep_l = 0;
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < c; j++) {
        if (j == i) {
          if (rep == 0)
            rep = 1;
          else
            continue;
        }
        for (int k = 0; k < c; k++) {
          if (k == i || k == j) {
            if (rep == 0)
              rep_k = 1;
            else
              continue;
          }
          for (int l = 0; l < c; l++) {
            if (l == k || l == j || l == i) {
              if (rep == 0 && rep_k == 0)
                rep_l = 1;
              else
                continue;
            }
            cout << a[i] << a[j] << a[k] << a[l] << "\n";
            fflush(stdout);
            cin >> x >> y;
            if (x == 4 && y == 0) {
              return 0;
            }
            rep_l = 0;
          }
          rep_k = 0;
        }
        rep = 0;
      }
    }
  } else if (c == 2) {
    cout << a[0] << a[1] << a[0] << a[1] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
    cout << a[0] << a[1] << a[1] << a[0] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
    cout << a[1] << a[0] << a[1] << a[0] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
    cout << a[1] << a[1] << a[0] << a[0] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
    cout << a[0] << a[0] << a[1] << a[1] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
    cout << a[1] << a[0] << a[0] << a[1] << "\n";
    fflush(stdout);
    cin >> x >> y;
    if (x == 4 && y == 0) {
      return 0;
    }
  }
  return 0;
}
