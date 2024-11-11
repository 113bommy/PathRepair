#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, j, k, p, m, n;
  cin >> n;
  bool sum_given[n];
  vector<int> parent(n), arr(n, 0), sum(n);
  vector<vector<int>> child(n);
  parent[0] = -1;
  for (i = 1; i < n; i++) {
    cin >> p;
    parent[i] = p - 1;
    child[p - 1].push_back(i);
  }
  for (i = 0; i < n; i++) {
    cin >> sum[i];
    sum_given[i] = sum[i] == -1 ? 0 : 1;
  }
  arr[0] = sum[0];
  for (i = 1; i < n; i++) {
    if (sum_given[i] == 0) {
      if (child[i].size() == 0) {
        arr[i] = 0;
        sum[i] = sum[parent[i]];
      } else {
        j = sum[child[i][0]];
        for (k = 1; k < child[i].size(); k++) {
          j = min(sum[child[i][k]], j);
        }
        p = sum[parent[i]];
        if (j < p) {
          cout << "-1 ";
          return 0;
        } else {
          sum[i] = j;
          arr[i] = j - p;
        }
      }
    }
  }
  for (i = 1; i < n; i++) {
    if (sum_given[i] == 1) {
      p = sum[parent[i]];
      if (sum[i] > p) {
        cout << "-1";
        return 0;
      } else {
        arr[i] = sum[i] - p;
      }
    }
  }
  long long a = 0;
  for (i = 0; i < n; i++) {
    a += arr[i];
  }
  cout << a;
  return 0;
}
