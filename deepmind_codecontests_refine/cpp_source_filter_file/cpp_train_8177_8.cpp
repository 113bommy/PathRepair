#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
int N, M, vl[500100][2];
bitset<7> a[MAXN];
int main() {
  cin >> N >> M;
  int i, j;
  for (i = 1; i <= M; i++) {
    cin >> vl[i][0] >> vl[i][1];
    a[vl[i][0]][vl[i][1]] = 1;
  }
  for (i = 1; i <= N; i++) a[i][N + i] = 1;
  for (j = 1; j <= N; j++) {
    int ind = j;
    for (i = j; i <= N; i++)
      if (a[i][j]) ind = i;
    swap(a[ind], a[j]);
    for (i = j + 1; i <= N; i++)
      if (a[i][j] == 1) a[i] ^= a[j];
  }
  for (i = N; i > 0; i--)
    for (j = 1; j < i; j++)
      if (a[j][i]) a[j] ^= a[i];
  for (i = 1; i <= M; i++)
    if (!a[vl[i][1]][N + vl[i][0]])
      cout << "YES\n";
    else
      cout << "NO\n";
  return 0;
}
