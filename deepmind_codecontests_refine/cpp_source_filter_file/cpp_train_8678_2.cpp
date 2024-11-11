#include <bits/stdc++.h>
using namespace std;
int b[100000];
int DP[4001][4001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int last = -1;
    DP[i][i] = 1;
    for (int j = 0; j < i; j++) {
      if (last != -1)
        DP[j][i] = DP[last][j] + 1;
      else
        DP[j][i] = 2;
      if (b[j] == b[i]) last = j;
      mx = max(mx, DP[j][i]);
    }
  }
  cout << mx << endl;
  return 0;
}
