#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char ch[N][N];
int x[N], y[N], n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf(" %c", &ch[i][j]);
    }
  }
  for (int i = 0; i < n; ++i) {
    y[i] = -1;
    for (int j = 0; j < m; ++j) {
      if (ch[i][j] == 'X') {
        y[i] = j;
        break;
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    x[j] = -1;
    for (int i = 0; i < n; ++i) {
      if (ch[i][j] == 'X') {
        x[j] = i;
        break;
      }
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      sum += (long long)(m - (y[i] >= 0)) * (m - (y[j] >= 0)) * (j - i) * 2;
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      sum += (long long)(n - (x[i] >= 0)) * (n - (x[j] >= 0)) * (j - i) * 2;
    }
  }
  for (int i = 0; i < m; ++i) {
    if (x[i] == -1) continue;
    int below = n - 1 - x[i], above = x[i];
    sum += (long long)(below)*above * 4;
    for (int j = i + 1; j < m; ++j) {
      if (x[j] == -1 || x[j] > x[j - 1]) {
        break;
      }
      above = x[j];
      sum += (long long)(below)*above * 4;
    }
    above = x[i];
    for (int j = i - 1; j >= 0; --j) {
      if (x[j] == -1 || x[j] > x[j + 1]) {
        break;
      }
      above = x[j];
      sum += (long long)(below)*above * 4;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (y[i] == -1) continue;
    int below = y[i], above = m - 1 - y[i];
    sum += (long long)(below)*above * 4;
    for (int j = i + 1; j < n; ++j) {
      if (y[j] == -1 || y[j] < y[j - 1]) {
        break;
      }
      above = m - 1 - y[j];
      sum += (long long)(below)*above * 4;
    }
    above = m - 1 - y[i];
    for (int j = i - 1; j >= 0; --j) {
      if (y[j] == -1 || y[j] < y[j + 1]) {
        break;
      }
      above = m - 1 - y[j];
      sum += (long long)(below)*above * 4;
    }
  }
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += m - (y[i] >= 0);
  }
  ans = ans * ans;
  ans = sum / ans;
  printf("%.10f\n", ans);
  return 0;
}
