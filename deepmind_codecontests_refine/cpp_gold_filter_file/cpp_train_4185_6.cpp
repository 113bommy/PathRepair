#include <bits/stdc++.h>
using namespace std;
vector<long long> row, col;
vector<vector<long long>> a;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  row.resize(n, 0ll);
  col.resize(m, 0ll);
  a.resize(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%lld", &a[i][j]);
      row[i] += a[i][j];
      col[j] += a[i][j];
    }
  }
  if (n <= 4) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += row[i];
    }
    cout << ans << endl;
    return 0;
  }
  if (m <= 4) {
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      ans += col[i];
    }
    cout << ans << endl;
    return 0;
  }
  long long mx = -1;
  vector<long long> temp(row.begin(), row.end());
  sort(temp.begin(), temp.end(), greater<long long>());
  long long ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += temp[i];
  }
  mx = max(mx, ans);
  temp.clear();
  temp.assign(col.begin(), col.end());
  sort(temp.begin(), temp.end(), greater<long long>());
  ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += temp[i];
  }
  mx = max(mx, ans);
  for (int i = 0; i < m; i++) {
    ans = col[i];
    temp.clear();
    temp.assign(row.begin(), row.end());
    for (int j = 0; j < n; j++) {
      temp[j] -= a[j][i];
    }
    sort(temp.begin(), temp.end(), greater<long long>());
    for (int j = 0; j < 3; j++) {
      ans += temp[j];
    }
    mx = max(mx, ans);
  }
  for (int i = 0; i < n; i++) {
    ans = row[i];
    temp.clear();
    temp.assign(col.begin(), col.end());
    for (int j = 0; j < m; j++) {
      temp[j] -= a[i][j];
    }
    sort(temp.begin(), temp.end(), greater<long long>());
    for (int j = 0; j < 3; j++) {
      ans += temp[j];
    }
    mx = max(mx, ans);
  }
  if (m <= n) {
    for (int i = 0; i < m - 1; i++) {
      for (int j = i + 1; j < m; j++) {
        ans = col[i] + col[j];
        long long h1 = 0, h2 = 0;
        for (int k = 0; k < n; k++) {
          row[k] -= a[k][i];
          row[k] -= a[k][j];
          if (row[k] > h1) {
            h2 = h1;
            h1 = row[k];
          } else if (row[k] > h2) {
            h2 = row[k];
          }
          row[k] += a[k][i];
          row[k] += a[k][j];
        }
        ans += (h1 + h2);
        mx = max(mx, ans);
      }
    }
  } else {
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = row[i] + row[j];
        long long h1 = 0, h2 = 0;
        for (int k = 0; k < m; k++) {
          col[k] -= a[i][k];
          col[k] -= a[j][k];
          if (col[k] > h1) {
            h2 = h1;
            h1 = col[k];
          } else if (col[k] > h2) {
            h2 = col[k];
          }
          col[k] += a[i][k];
          col[k] += a[j][k];
        }
        ans += (h1 + h2);
        mx = max(mx, ans);
      }
    }
  }
  cout << mx << endl;
}
