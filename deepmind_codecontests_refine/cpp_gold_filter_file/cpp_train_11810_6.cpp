#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<vector<long long> > d;
long long power[20000];
int main(void) {
  int n, k;
  power[0] = 1;
  for (int i = 1; i < 20000; ++i) power[i] = (power[i - 1] * 2) % 1000000007;
  scanf("%d%d", &n, &k);
  int m = 1;
  for (int i = 0; i < k; ++i) m *= 2;
  m += 1;
  d.resize(n);
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    d[i].resize(max(m, 10));
  }
  long long cursum = 0;
  if (a[0] == 2) d[0][2] = 1;
  if (a[0] == 4) d[0][4] = 1;
  if (a[0] == 0) {
    d[0][2] = 1;
    d[0][4] = 1;
  }
  cursum = d[0][2];
  for (int i = 1; i < n; ++i) {
    if (a[i] == 4)
      d[i][4] = cursum;
    else if (a[i] == 0) {
      d[i][4] = (cursum + d[i - 1][2]) % 1000000007;
    } else
      d[i][4] = d[i - 1][2];
    for (int j = 5; j < d[i].size(); ++j) {
      if (a[i] == 4) {
        if (j % 4 == 0) {
          if (i == 0) {
            if (j == 4)
              d[i][j] = 1;
            else
              d[i][j] = 0;
          } else
            d[i][j] = d[i - 1][j - 4];
        } else
          d[i][j] = 0;
      }
      if (a[i] == 2) {
        if (j >= 2) {
          if (i == 0) {
            if (j == 2)
              d[i][j] = 1;
            else
              d[i][j] = 0;
          } else
            d[i][j] = d[i - 1][j - 2];
        }
      }
      if (a[i] == 0) {
        d[i][j] = 0;
        if (j >= 2) {
          if (i == 0) {
            if (j == 2)
              d[i][j] = 1;
            else
              d[i][j] = 0;
          } else
            d[i][j] = d[i - 1][j - 2];
        }
        if (j % 4 == 0) {
          if (i == 0) {
            if (j == 4) d[i][j] = (d[i][j] + 1) % 1000000007;
          } else
            d[i][j] = (d[i - 1][j - 4] + d[i][j]) % 1000000007;
        }
      }
    }
    cursum = 0;
    for (int j = 0; j < d[i].size(); ++j)
      if (j % 4 == 2) cursum = (cursum + d[i][j]) % 1000000007;
  }
  long long sum = 0;
  int st = 0;
  for (int i = 0; i < n; ++i)
    if (a[i] == 0) st++;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) st--;
    sum = (sum + (d[i][m - 1] * power[st]) % 1000000007) % 1000000007;
  }
  cout << sum << endl;
}
