#include <bits/stdc++.h>
using namespace std;
const int maxn = 1024 + 100;
bool a[maxn][maxn];
void build(int n) {
  if (n == 1) {
    a[1][1] = 1;
    return;
  }
  build(n - 1);
  for (int i = 0; i < (1 << (n - 1)); i++)
    for (int j = (1 << (n - 1)); j < (1 << n); j++)
      a[i][j] = !a[i][(1 << n) - j - 1];
  for (int i = (1 << (n - 1)); i < (1 << n); i++)
    for (int j = 0; j < (1 << n); j++)
      if (j < (1 << (n - 1)))
        a[i][j] = a[i - (1 << (n - 1))][j];
      else
        a[i][j] = a[i - (1 << (n - 1))][(1 << n) - 1 - j];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 0) {
    cout << "*" << endl;
    return 0;
  }
  build(n);
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) cout << (a[i][j] ? '*' : '+');
    cout << '\n';
  }
  return 0;
}
