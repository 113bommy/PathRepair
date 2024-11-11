#include <bits/stdc++.h>
using namespace std;
int sum_without_every_kth(vector<int> &v, int sum, int k, int b, int n) {
  for (int i = b; i < n; i += k) sum -= v[i];
  return abs(sum);
}
int main() {
  int n, k, maxx, sum = 0;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (auto x : v) sum += x;
  maxx = abs(sum);
  for (int b = 0; b < k; b++)
    maxx = max(maxx, sum_without_every_kth(v, sum, k, b, n));
  cout << abs(maxx);
  return 0;
}
