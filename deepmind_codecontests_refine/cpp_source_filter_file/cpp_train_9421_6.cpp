#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x, y;
  int a[2500];
  int h[50] = {0};
  int v[50] = {0};
  int k = 0;
  for (int i = 0; i < n * n; i++) {
    cin >> x >> y;
    if (h[x] == 0 && v[y] == 0) {
      h[x]++;
      v[y]++;
      a[k] = i + 1;
      k++;
    }
  }
  for (int i = 0; i < k; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
