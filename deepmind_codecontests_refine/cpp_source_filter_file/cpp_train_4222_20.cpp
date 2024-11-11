#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn], b[maxn], len[maxn];
int main() {
  int i, j, n, re, left, right, mid;
  while (cin >> n) {
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      b[a[i]] = i;
    }
    for (i = n; i >= 1; i--) {
      cin >> a[i];
      a[i] = b[a[i]];
    }
    len[0] = 0;
    len[1] = a[1];
    re = 1;
    for (i = 2; i <= n; i++) {
      if (a[i] > len[re]) {
        len[++re] = a[i];
        continue;
      }
      right = re;
      left = 0;
      while (left <= right) {
        mid = (left + right) / 2;
        if (len[mid] > a[i])
          right = mid - 1;
        else
          left = mid + 1;
      }
      len[mid] = a[i];
    }
    cout << re << endl;
  }
  return 0;
}
