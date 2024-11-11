#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int a[100005];
  for (int i = 1; i <= 100000; ++i) a[i] = 0;
  int l;
  for (int i = 1; i <= n; ++i) {
    cin >> l;
    a[l] = a[l] + 1;
  }
  for (int i = 1; i <= 100000; ++i) {
    if (a[i] >= 2) {
      cout << 0;
      return 0;
    }
  }
  int b[100005];
  for (int i = 1; i <= 100000; ++i) {
    b[i] = 0;
  }
  for (int i = 1; i <= 100000; ++i) {
    if (a[i] == 1) {
      b[(i & x)] += 1;
    }
  }
  for (int i = 1; i <= 100000; ++i) {
    if (a[i] == 1 && b[i] >= 2) {
      cout << 1;
      return 0;
    }
  }
  for (int i = 1; i <= 100000; ++i) {
    if (a[i] == 1 && b[i] == 1 && i != i & x) {
      cout << 1;
      return 0;
    }
  }
  for (int i = 1; i <= 100000; ++i)
    if (b[i] >= 2) {
      cout << 2;
      return 0;
    }
  cout << -1;
  return 0;
}
