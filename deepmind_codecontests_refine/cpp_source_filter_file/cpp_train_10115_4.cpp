#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, s, p;
bool f;
string A[500001];
char str[500001];
int main() {
  scanf("%d%d", &n, &m);
  vector<vector<int> > V(n), H(n);
  for (i = 0; i < n; i++) {
    V[i].resize(m);
    H[i].resize(m);
    scanf("%s", str);
    A[i] = str;
    for (j = 0; j < m; j++)
      if (A[i][j] == '1') {
        V[i][j] = 0;
        H[i][j] = 0;
      } else if (A[i][j] == '2') {
        V[i][j] = 1;
        H[i][j] = 0;
      } else if (A[i][j] == '3') {
        V[i][j] = 1;
        H[i][j] = 1;
      } else if (A[i][j] == '4') {
        V[i][j] = 0;
        H[i][j] = 1;
      }
  }
  for (i = 0, f = 1; i < n; i++)
    for (j = 0; j < m; j++)
      if (A[i][j] != '.') {
        for (k = 0; k < m; k++)
          if (A[i][k] != '.' && abs(H[i][j] - H[i][k]) != abs(k - j) % 2) f = 0;
        break;
      }
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      if (A[j][i] != '.') {
        for (k = 0; k < n; k++)
          if (A[k][j] != '.' && abs(V[j][i] - V[k][i]) != abs(j - k) % 2) f = 0;
        break;
      }
  if (!f) {
    printf("0");
    return 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m && A[i][j] == '.'; j++)
      ;
    s += j == m;
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n && A[j][i] == '.'; j++)
      ;
    s += j == n;
  }
  for (i = 0, p = 1; i < s; i++) p = p * 2 % 1000003;
  printf("%d", p);
  return 0;
}
