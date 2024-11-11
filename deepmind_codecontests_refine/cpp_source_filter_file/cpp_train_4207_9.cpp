#include <bits/stdc++.h>
using namespace std;
bool b[1050][1050];
int n, m;
int main() {
  cin >> n;
  m = n - 1 + (n & 1);
  swap(n, m);
  if (n == 4) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int k = i == n ? 1 : i + 1;
    do b[i][k] = 1, k += 2, k -= k > n ? n : 0;
    while (k != i);
  }
  if (n != m) {
    b[m][1] = b[m][2] = 1;
    for (int i = 3; i < m; i++) b[i][m] = 1;
  }
  swap(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar('0' + b[i][j]), putchar(' ');
    puts("");
  }
  return 0;
}
