#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(INT_MAX / 2);
const int N = (int)(0);
const long long mod = (int)(1e+9 + 7);
int n, m, a, b[2], x, y, k, k1, k2, s, ans, pos, last, cnt, tam;
int main() {
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0, j = n - 1; (i > j);) {
    b[(i + j) % 2] += (v[i] > v[j] ? v[i] : v[j]);
    (v[i] > v[j] ? i++ : j--);
  }
  if ((n - 1) % 2 != 0) swap(b[0], b[1]);
  cout << b[0] << " " << b[1];
  return 0;
}
