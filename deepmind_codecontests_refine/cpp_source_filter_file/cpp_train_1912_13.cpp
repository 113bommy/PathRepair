#include <bits/stdc++.h>
using namespace std;
const unsigned long long N = 110;
const unsigned long long M = 10100;
const unsigned long long INF = 1000 * 1000 * 1000;
long long n, m, s;
long long i, j, x, y;
char a[N][M], c;
long long d[N][M];
unsigned long long sum[M];
int main(int argc, char* argv[]) {
  cin >> n >> m;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      cin >> c;
      a[i][j] = c - '0';
      d[i][j] = INF;
      if (a[i][j]) d[i][j] = 0;
    }
  for (long long row = 0; row < n; row++) {
    for (long long col = 0; col < m; col++)
      if (d[row][col] == 0) {
        i = (col + 1) % m;
        s = 1;
        while (d[row][i] > s) {
          d[row][i] = s;
          i = (i + 1) % m;
          s++;
        }
        i = (col - 1) % m;
        s = 1;
        while (d[row][i] > s) {
          d[row][i] = s;
          i = (i - 1) % m;
          s++;
        }
      }
  }
  unsigned long long min = INF;
  for (j = 0; j < m; j++) {
    sum[j] = 0;
    for (i = 0; i < n; i++) {
      sum[j] += d[i][j];
    }
    if (sum[j] < min) min = sum[j];
  }
  if (min >= INF) {
    cout << -1 << endl;
  } else {
    cout << min << endl;
  }
  return 0;
}
