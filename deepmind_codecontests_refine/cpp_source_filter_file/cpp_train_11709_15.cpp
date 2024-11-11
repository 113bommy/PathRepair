#include <bits/stdc++.h>
using namespace std;
unsigned long long mat[2100][40];
int binaryJordanGauss(int r, int c, int right) {
  int b = (c + right + 63) / 64;
  int rnk = 0;
  for (int _n(c), j(0); j < _n; j++) {
    int i = rnk;
    for (; i < r; ++i)
      if (mat[i][j >> 6] & (1ull << (j & 63))) break;
    if (i == r) continue;
    if (i != rnk) {
      for (int _n(b), k(j >> 6); k < _n; k++) swap(mat[i][k], mat[rnk][k]);
    }
    for (i = 0; i < r; ++i) {
      if (i != rnk) {
        if (mat[i][j >> 6] & (1ull << (j & 63))) {
          for (int _n(b), k(j >> 6); k < _n; k++) mat[i][k] ^= mat[rnk][k];
        }
      }
    }
    rnk++;
  }
  return rnk;
}
char buff[2222];
int arr[2222];
int in[2020][2020];
int ind[2222];
int main() {
  int N;
  cin >> N;
  for (int _n(N), x(0); x < _n; x++) {
    scanf("%s", buff);
    int size = (int)strlen(buff);
    for (int _n(size), i(0); i < _n; i++) arr[i] = buff[size - 1 - i] - '0';
    for (int _n(2000), i(0); i < _n; i++) in[x][i] = 0;
    for (int _n(2000), i(0); i < _n; i++) {
      in[x][i] = arr[0] % 2;
      arr[0] /= 2;
      for (int _n(size), j(1); j < _n; j++) {
        arr[j - 1] += 10 * (arr[j] % 2);
        arr[j] /= 2;
      }
      if (arr[size - 1] == 0) size--;
      if (size == 0) break;
    }
  }
  for (int _n(N), i(0); i < _n; i++)
    for (int _n(2000), j(0); j < _n; j++) {
      if (in[i][j]) {
        mat[j][i / 64] |= 1ull << (i % 64);
      }
    }
  binaryJordanGauss(2000, N, 0);
  int k = 0;
  for (int _n(N), i(0); i < _n; i++) {
    if (mat[k][i / 64] & (1ull << (i % 64))) {
      ind[k++] = i;
      cout << 0 << endl;
    } else {
      vector<int> ans;
      for (int _n(k), j(0); j < _n; j++)
        if (mat[j][i / 64] & (1ull << (i % 64))) ans.push_back(ind[j]);
      cout << ans.size();
      for (int t : ans) cout << " " << t;
      cout << endl;
    }
  }
  return 0;
}
