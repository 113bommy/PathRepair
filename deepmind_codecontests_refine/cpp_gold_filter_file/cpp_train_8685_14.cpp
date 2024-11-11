#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], b[110];
void make(int k, int a[]) {
  if (k == 1) {
    a[1] = 1;
  } else if (k == 2) {
    a[1] = 3;
    a[2] = 4;
  } else if (k % 2 == 0) {
    for (int i = 1; i < k; i++) a[i] = 1;
    a[k] = k / 2 - 1;
  } else {
    for (int i = 1; i < k - 1; i++) a[i] = 1;
    a[k - 1] = 2;
    a[k] = (k + 1) / 2;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  make(n, a);
  make(m, b);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i] * b[j] << " ";
    cout << endl;
  }
  return 0;
}
