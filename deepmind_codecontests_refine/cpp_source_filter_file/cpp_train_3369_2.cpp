#include <bits/stdc++.h>
using namespace std;
int c2(int x) { return x * (x - 1) / 2; }
bool mat[1000][1000];
int main() {
  int n, cnt = 1;
  cin >> n;
  for (int i = 1; i <= n; i++, cnt++) {
    int x = i;
    while (c2(x) > n) x--;
    for (int j = 0; j < x; j++) mat[j][i] = mat[i][j] = true;
    n -= c2(x);
  }
  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < cnt; j++) cout << mat[i][j];
    cout << endl;
  }
}
