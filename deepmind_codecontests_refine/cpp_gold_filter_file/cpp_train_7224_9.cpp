#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  bool row[1005] = {0}, col[1005] = {0};
  row[1] = 1;
  row[n] = 1;
  col[n] = 1;
  col[1] = 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    row[a] = 1;
    col[b] = 1;
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    c += !(row[i]) + !col[i];
  }
  if (!row[n / 2 + 1] && !col[n / 2 + 1] && n % 2) c--;
  cout << c << endl;
}
