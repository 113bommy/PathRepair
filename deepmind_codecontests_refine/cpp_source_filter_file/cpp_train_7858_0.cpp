#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, res = 0;
  cin >> n;
  int a[n];
  vector<int> q;
  for (int i = 0; i < n; ++i) cin >> a[i];
  q.push_back(a[0]);
  for (int i = 1; i < n; ++i) {
    if (a[i] >= q[q.size() - 1])
      q.push_back(a[i]);
    else {
      int size = q.size();
      res = max(res, size);
      q.clear();
      q.push_back(a[i]);
    }
    if (i == n - 1) {
      int size = q.size();
      res = max(res, size);
    }
  }
  cout << res;
}
