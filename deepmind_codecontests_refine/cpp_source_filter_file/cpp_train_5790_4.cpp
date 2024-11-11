#include <bits/stdc++.h>
using namespace std;
vector<int> ve;
int n, m;
bool a[5003][5003];
int p[5003][5003];
void work() {
  for (int i = 2; i <= 2500; i++) {
    bool ok = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) ve.push_back(i);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) a[i][j] = str[j] - '0';
  }
  for (int i = 0; i <= 5000; i++) {
    p[i][0] = a[i][0];
    for (int j = 1; j <= 5000; j++) {
      p[i][j] = p[i][j - 1] + a[i][j];
    }
  }
  work();
  int mini = 100000008, sum, v1, v2, cnt;
  for (int l = 0; l < ve.size(); l++) {
    sum = 0;
    for (int i = 0; i < n; i += ve[l]) {
      for (int j = 0; j < m; j += ve[l]) {
        v1 = 0, v2 = 0, cnt = 0;
        for (int ii = i; ii < i + ve[l] && ii < n; ii++) {
          v2 += p[ii][j + ve[l]] - p[ii][j - 1];
        }
        v1 = ve[l] * ve[l] - v2;
        sum += min(v1, v2);
      }
    }
    if (sum < mini) mini = sum;
  }
  cout << mini;
  return 0;
}
