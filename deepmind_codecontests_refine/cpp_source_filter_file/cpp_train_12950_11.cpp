#include <bits/stdc++.h>
using namespace std;
const int MAX = 33;
const int NUM = 17;
int n, first;
int g[MAX][MAX];
int tmp[MAX][MAX];
int work(int S) {
  int i, j, ans = 0;
  for ((i) = (1); (i) <= (n); ++(i))
    for ((j) = (1); (j) <= (n); ++(j)) tmp[i][j] = g[i][j];
  int mid = (S >> (first - 1)) & 1;
  for ((i) = (1); (i) <= (first); ++(i)) {
    int t = (S >> (i - 1)) & 1;
    if (t) tmp[first][i] *= -1;
    if (t ^ mid) tmp[first][i + first] *= -1;
  }
  for ((i) = (1); (i) <= (n); ++(i)) ans += tmp[first][i];
  for ((i) = (1); (i) != (first); ++(i))
    for ((j) = (1); (j) <= (first); ++(j))
      if ((S >> (j - 1)) & 1)
        tmp[i][j] -= tmp[i + first][j];
      else
        tmp[i][j] += tmp[i + first][j];
  for ((i) = (1); (i) != (first); ++(i))
    for ((j) = (first + 1); (j) <= (n); ++(j))
      if (((S >> (j - first - 1)) & 1) ^ mid)
        tmp[i][j] -= tmp[i + first][j];
      else
        tmp[i][j] += tmp[i + first][j];
  for ((i) = (1); (i) != (first); ++(i)) {
    int a1 = 0, a2 = 0;
    for ((j) = (1); (j) != (first); ++(j))
      a1 += abs(tmp[i][j] - tmp[i][j + first]);
    a1 -= tmp[i][first];
    for ((j) = (1); (j) != (first); ++(j))
      a2 += abs(tmp[i][j] + tmp[i][j + first]);
    a2 += tmp[i][first];
    ans += max(a1, a2);
  }
  return ans;
}
int main() {
  int i, j;
  scanf("%d", &n);
  int ans = 0;
  for ((i) = (1); (i) <= (n); ++(i))
    for ((j) = (1); (j) <= (n); ++(j)) {
      scanf("%d", &g[i][j]);
      ans += g[i][j];
    }
  first = (n + 1) / 2;
  for ((i) = (0); (i) != (1 << first); ++(i)) ans = max(ans, work(i));
  cout << ans << endl;
  return 0;
}
