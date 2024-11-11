#include <bits/stdc++.h>
using namespace std;
int maxn = 100000;
int cup[230][230];
int n, t;
void fil(int r, int l, int yu) {
  if (r > n) return;
  cup[r][l] += yu;
  if (cup[r][l] > maxn) {
    int yuu = cup[r][l] - maxn;
    cup[r][l] = maxn;
    fil(r + 1, l, yuu / 2);
    fil(r + 1, l + 1, yuu / 2);
  }
}
int main() {
  int as = 0;
  memset(cup, 0, sizeof(cup));
  cin >> n >> t;
  while (t--) fil(1, 1, maxn);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      if (cup[i][j] == maxn) as++;
  cout << as << endl;
}
