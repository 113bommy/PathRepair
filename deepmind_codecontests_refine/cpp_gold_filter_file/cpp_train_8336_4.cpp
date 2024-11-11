#include <bits/stdc++.h>
using namespace std;
int binsearch(long long int* a, int n, long long int val) {
  int l = 0, h = n - 1;
  int m = (l + h) >> 1;
  while (l <= h) {
    if (a[m] == val)
      return m;
    else if (a[m] > val)
      h = m - 1;
    else
      l = m + 1;
    m = (l + h) >> 1;
  }
  return -1;
}
int main() {
  int n;
  cin >> n;
  long long int a[n];
  int vis[n];
  for (int i = 0; i < n; ++i) {
    vis[i] = 0;
    cin >> a[i];
  }
  sort(&a[0], &a[n]);
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    long long int temp = 1;
    int ind;
    while (temp - a[i] <= a[n - 1]) {
      long long int sea = temp - a[i];
      ind = binsearch(a, n, sea);
      if (ind != -1) {
        if (ind == i) {
          if ((ind - 1 >= 0 and a[ind] == a[ind - 1]) or
              (ind + 1 < n and a[ind + 1] == a[ind]))
            vis[i] = 1;
        } else
          vis[i] = 1;
      }
      temp *= 2;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
