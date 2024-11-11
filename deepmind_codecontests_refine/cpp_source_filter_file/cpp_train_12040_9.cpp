#include <bits/stdc++.h>
using namespace std;
int A[10][1000005];
int f(int x) {
  if (x < 10) return x;
  int i;
  int pro = 1;
  while (x) {
    if (x % 10) pro *= x % 10;
    x = x / 10;
  }
  return f(pro);
}
void solve() {
  int i, j;
  for (i = 1; i < 1000005 - 5; i++) {
    A[f(i)][i]++;
  }
  for (i = 1; i < 10; i++) {
    for (j = 1; j < 1000005 - 5; j++) {
      A[i][j] += A[i][j - 1];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << A[k][r] - A[k][l - 1] << endl;
  }
}
int main() {
  solve();
  return 0;
}
