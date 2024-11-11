#include <bits/stdc++.h>
using namespace std;
const int N = 301;
int a[N], b[N];
int n, t;
int v[N];
int c[N][N];
int d[N][N];
int main() {
  memset(c, 0, sizeof(c));
  memset(v, 0, sizeof(v));
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    string ss;
    cin >> ss;
    for (int j = 0; j < n; j++) {
      c[i][j] = ss[j] - '0';
      d[i][j] = c[i][j];
    }
  }
  for (int i = 0; i < n; i++) c[i][i] = 1;
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (c[i][k] && c[k][j]) c[i][j] = 1;
      }
  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      v[i] = 1;
      vector<int> a1;
      vector<int> a2;
      for (int j = 0; j < n; j++) {
        if (c[i][j]) {
          a1.push_back(j);
          v[j] = 1;
          a2.push_back(a[j]);
        }
      }
      sort(a2.begin(), a2.end());
      sort(a1.begin(), a1.end());
      for (int j = 0; j < a1.size(); j++) a[a1[j]] = a2[j];
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1)
      printf(" ");
    else
      printf("\n");
  };
  return 0;
}
