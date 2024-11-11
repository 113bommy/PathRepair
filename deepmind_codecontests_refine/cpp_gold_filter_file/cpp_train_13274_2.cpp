#include <bits/stdc++.h>
using namespace std;
const int MAX = 1 << 9;
int k;
bool ans[MAX][MAX];
void f(int n) {
  if (n == 1) {
    ans[0][0] = 1;
    return;
  }
  int m = n / 2;
  f(m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) {
      int x = ans[i][j];
      ans[i + m][j] = x;
      ans[i][j + m] = x;
      ans[i + m][j + m] = !x;
    }
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(0);
  cin >> k;
  int n = 1 << k;
  f(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << (ans[i][j] ? '+' : '*');
    cout << '\n';
  }
  return 0;
}
