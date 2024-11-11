#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000000000000LL;
int n;
int m;
int dx[6][666666];
int dy[6][666666];
long long d[33];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m - 1; i++)
    for (int j = 0; j < n; j++) cin >> dx[j][i];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> dy[j][i];
  fill(d, d + 33, INF);
  d[(1 << n) - 1] = 0;
  for (int i = 0; i < m - 1; i++) {
    for (int k = 0; k < (1 << n); k++) {
      for (int j = 0; j < n; j++) {
        if (((k >> j) & 1) ^ ((k >> (j + 1) % n & 1))) d[k] += dy[j][i];
      }
    }
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < (1 << n); k++) {
        d[k ^ (1 << j)] = min(d[k ^ (1 << j)], d[k] + dx[j][i]);
        d[k] = min(d[k], d[k ^ (1 << j)] + dx[j][i]);
      }
    }
  }
  cout << d[0] << endl;
  return 0;
}
