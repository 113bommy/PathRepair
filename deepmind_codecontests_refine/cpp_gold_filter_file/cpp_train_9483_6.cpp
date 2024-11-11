#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a > b) return b;
  return a;
}
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int main() {
  int n, m;
  cin >> n >> m;
  int c[n], a[m];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int j = 0, flag = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (c[i] <= a[j]) {
      flag++;
      j++;
    }
  }
  cout << flag;
  return 0;
}
