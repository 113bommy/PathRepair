#include <bits/stdc++.h>
using namespace std;
struct Pair {
  string colour{" "};
  string name{" "};
};
int last(int a[], int m, int n) {
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == m) {
      j = i;
    }
  }
  return j + 1;
}
int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[m];
  int c[m];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        c[k] = a[i];
        ++k;
        break;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    cout << c[i] << " ";
  }
  return 0;
}
