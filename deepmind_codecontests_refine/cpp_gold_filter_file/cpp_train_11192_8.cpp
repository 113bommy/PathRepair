#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200001], b[200001];
int BS(int x) {
  int l = 0, h = n - 1;
  while (l < h) {
    int mid = (l + h + 1) / 2;
    if (a[mid] > x) {
      h = mid - 1;
    } else {
      l = mid;
    }
  }
  return (a[l] <= x ? l + 1 : 0);
}
int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
      if (i) {
        cout << " ";
      }
      cout << BS(b[i]);
    }
    cout << endl;
  }
  return 0;
}
