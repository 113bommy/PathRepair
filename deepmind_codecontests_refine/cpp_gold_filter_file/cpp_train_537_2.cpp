#include <bits/stdc++.h>
using namespace std;
int countDistinct(int arr[], int n) {
  int res = 1;
  for (int i = 1; i < n; i++) {
    int j = 0;
    for (j = 0; j < i; j++)
      if (arr[i] == arr[j]) break;
    if (i == j) res++;
  }
  return res;
}
int main() {
  int t, n, k, d, i = 0, j = 0, l = 0, ind = 0;
  cin >> t;
  int a[t];
  for (i = 0; i < t; i++) {
    cin >> n >> k >> d;
    int s[n], b = 0, c = 0, m = d, ds[d], p = 0;
    for (j = 0; j < n; j++) {
      cin >> s[j];
    }
    for (j = 0; j < n - d + 1; j++) {
      b = s[j];
      p = 0;
      for (l = j; l < j + d; l++) {
        ds[p] = s[l];
        p++;
      }
      c = countDistinct(ds, d);
      if (j == 0)
        m = c;
      else {
        if (m > c) {
          m = c;
        }
      }
    }
    a[ind] = m;
    ind++;
  }
  for (i = 0; i < t; i++) {
    cout << a[i] << endl;
  }
  return 0;
}
