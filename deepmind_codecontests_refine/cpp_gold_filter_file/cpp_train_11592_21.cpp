#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {0, 1, -1, 0, 0, -1, -1, 1, 1},
          dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
const int base = 1000000007;
const int maxn = 12;
int n;
int a[maxn][maxn], b[maxn], sum;
int diff1() {
  int i, j;
  int res = 0;
  for (i = 1; i <= n; i++) {
    int ht = 0;
    for (j = 1; j <= n; j++) ht += a[i][j];
    res += abs(ht - sum);
  }
  return res;
}
int diff2() {
  int i, j;
  int res = 0;
  for (j = 1; j <= n; j++) {
    int ht = 0;
    for (i = 1; i <= n; i++) ht += a[i][j];
    res += abs(ht - sum);
  }
  return res;
}
int diff3() {
  int i, j;
  int res = 0, ht = 0;
  for (i = 1; i <= n; i++) ht += a[i][i];
  res += abs(ht - sum);
  ht = 0;
  for (i = 1; i <= n; i++) ht += a[i][n - i + 1];
  res += abs(ht - sum);
  return res;
}
bool ok(int i, int j) { return (i > 0 && j > 0 && i <= n && j <= n); }
int main() {
  int i, j, k, u, v, first, second;
  scanf("%d", &n);
  sum = 0;
  for (i = 1; i <= n * n; i++) {
    scanf("%d", &b[i]);
    sum += b[i];
  }
  sum /= n;
  bool stop = false, dd;
  int trytime = 800;
  for (int t = 1; t <= trytime; t++) {
    random_shuffle(b + 1, b + n * n + 1);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) a[i][j] = b[(i - 1) * n + j];
    for (int p = 1; p <= 800; p++) {
      i = rand() % n + 1;
      j = rand() % n + 1;
      for (k = 1; k <= 8; k++) {
        first = i + dx[k];
        second = j + dy[k];
        if (!ok(first, second)) continue;
        int t1 = diff1(), t2 = diff2(), t3 = diff3();
        swap(a[i][j], a[first][second]);
        int q1 = diff1(), q2 = diff2(), q3 = diff3();
        if (q1 == 0 && q2 == 0 && q3 == 0) {
          stop = true;
          break;
        }
        if (q1 < t1 || q2 < t2 || q3 < t3)
          dd = true;
        else
          swap(a[i][j], a[first][second]);
      }
    }
    if (stop) break;
  }
  cout << sum << "\n";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cout << a[i][j] << " ";
    cout << '\n';
  }
  return 0;
}
