#include <bits/stdc++.h>
using namespace std;
int n, m;
int a1, a2;
bool check(vector<vector<int>> &a, int mid) {
  vector<int> mask(1 << m, -1);
  for (int i = 0; i < n; ++i) {
    int cur = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] >= mid) {
        cur ^= (1 << j);
      }
    }
    mask[cur] = i;
  }
  if (mask[(1 << m) - 1] != -1) {
    a1 = a2 = mask[(1 << m) - 1];
    return true;
  }
  for (int i = 0; i < (1 << m); ++i) {
    for (int j = 0; j < (1 << m); ++j) {
      if (mask[i] != -1 && mask[j] != -1 && (i | j) == (1 << m) - 1) {
        a1 = mask[i];
        a2 = mask[j];
        return true;
      }
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  int left = 0, right = 1e9 + 43;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (check(a, mid))
      left = mid + 1;
    else
      right = mid - 1;
  }
  cout << a1 + 1 << " " << a2 + 1;
}
