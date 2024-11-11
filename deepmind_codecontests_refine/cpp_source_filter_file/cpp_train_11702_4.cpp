#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000;
int a[MaxN], res;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> d(n + 1, INT_MAX);
  d[0] = -INT_MAX;
  for (int i = 0; i < n; i++) {
    int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
    if (d[j - 1] < a[i] && a[i] < d[j]) d[j] = a[i];
  }
  res = 1;
  for (int i = 0; i < n; i++) {
    if (d[i] != INT_MAX) {
      res = i;
    }
  }
  cout << int(res);
  return 0;
}
