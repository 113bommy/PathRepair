#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m;
char ch[N][N];
int r[N], c[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> ch[i][j];
      if (ch[i][j] == '*') r[i]++, c[j]++;
    }
  int kq = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (ch[i][j] == '*') kq += (r[i] - 1) * (c[j] - 1);
  cout << kq;
  return 0;
}
