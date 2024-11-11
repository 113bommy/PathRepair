#include <bits/stdc++.h>
using namespace std;
long long int func(vector<vector<long long int>> &d, vector<int> &v, int i,
                   int k) {
  if (d[k][i - 1] != 0) return d[k][i - 1];
  if (k && (i + v[i - 1] <= d.size())) {
    d[k][i - 1] = -1;
    long long int y = func(d, v, i + v[i - 1], 1 - k);
    if (y != -1) y += v[i - 1];
    return d[k][i - 1] = y;
  } else if (k)
    return d[k][i - 1] = v[i - 1];
  else if (i - v[i - 1] > 0) {
    d[k][i - 1] = -1;
    long long int y = func(d, v, i - v[i - 1], 1 - k);
    if (y != -1) y += v[i - 1];
    return d[k][i - 1] = y;
  } else
    return d[k][i - 1] = v[i - 1];
}
int main() {
  long long int n, x, y, k = 1;
  cin >> n;
  vector<int> v;
  v.push_back(0);
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    v.push_back(x);
  }
  vector<vector<long long int>> d(2, vector<long long int>(n));
  for (int i = 1; i < n; i++) {
    y = 0;
    v[0] = i;
    d[1][0] = d[0][0] = -1;
    y = func(d, v, v[0] + 1, 0);
    if (y != -1) y += i;
    cout << y << endl;
  }
  return 0;
}
