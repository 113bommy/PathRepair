#include <bits/stdc++.h>
using namespace std;
int V[102][102], M2[2][102];
int main() {
  int n, a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &a);
      M2[0][i] += a;
      M2[1][j] += a;
    }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (M2[0][i] < M2[1][j]) cnt++;
  cout << cnt << endl;
}
