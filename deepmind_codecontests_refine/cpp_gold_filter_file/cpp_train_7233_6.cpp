#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  int a[n][m];
  struct a {
    int o;
    int p;
  } arr[q];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int fo[n];
  for (int i = 0; i < n; i++) {
    int c = 0;
    int max = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) c++;
      if (c > max) max = c;
      if (a[i][j] == 0) c = 0;
    }
    fo[i] = max;
  }
  for (int i = 0; i < q; i++) {
    cin >> arr[i].o;
    cin >> arr[i].p;
    arr[i].o--;
    arr[i].p--;
  }
  for (int i = 0; i < q; i++) {
    a[arr[i].o][arr[i].p] = a[arr[i].o][arr[i].p] ^ 1;
    int max = 0;
    int c = 0;
    for (int j = 0; j < m; j++) {
      if (a[arr[i].o][j] == 1) c++;
      if (c > max) max = c;
      if (a[arr[i].o][j] == 0) c = 0;
    }
    fo[arr[i].o] = max;
    int maxi = 0;
    for (int j = 0; j < n; j++) {
      if (fo[j] > maxi) maxi = fo[j];
    }
    cout << maxi << endl;
  }
  return 0;
}
