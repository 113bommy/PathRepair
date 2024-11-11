#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cmax = 0;
  int a[n];
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a')
      a[i] = 1;
    else
      a[i] = -1;
  }
  int k1 = k;
  int l = 0;
  int r = 0;
  int total = 0;
  while (r < n) {
    if (a[r] == 1) {
      total += 1;
      r++;
    } else {
      if (k1 > 0) {
        total += 1;
        k1--;
        r++;
      } else {
        if (l < r) {
          if (a[l] == 1) {
            l++;
            total--;
          } else {
            l++;
            total--;
            k1++;
          }
        } else {
          l++;
          r++;
        }
      }
    }
    cmax = max(cmax, total);
  }
  int b[n];
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b')
      b[i] = 1;
    else
      b[i] = -1;
  }
  k1 = k;
  l = 0;
  r = 0;
  total = 0;
  while (r < n) {
    if (b[r] == 1) {
      total += 1;
      r++;
    } else {
      if (k1 > 0) {
        total += 1;
        k1--;
        r++;
      } else {
        if (l < r) {
          if (b[l] == 1) {
            l++;
            total--;
          } else {
            l++;
            total--;
            k1++;
          }
        } else {
          l++;
          r++;
        }
      }
    }
    cmax = max(cmax, total);
  }
  cout << cmax;
}
