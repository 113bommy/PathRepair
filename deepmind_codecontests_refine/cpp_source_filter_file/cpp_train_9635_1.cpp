#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  scanf("%d %d", &n, &a);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  sort(v.begin(), v.end());
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 2) {
    cout << min(abs(a - v[0]), abs(a - v[1]));
    return 0;
  }
  if (a < v[0]) {
    cout << abs(a - v[n - 2]);
    return 0;
  }
  if (a > v[n - 1]) {
    cout << abs(a - v[1]);
    return 0;
  }
  long long x1 = 0;
  x1 += (long long)abs(a - v[0]);
  if (v[n - 2] > a) {
    x1 += (long long)abs(a - v[0]);
    x1 += (long long)abs(a - v[n - 2]);
  }
  long long x2 = 0;
  x2 += (long long)abs(a - v[n - 1]);
  if (v[1] < a) {
    x2 += (long long)abs(a - v[n - 1]);
    x2 += (long long)abs(a - v[1]);
  }
  long long x3 = 0;
  x3 += (long long)abs(a - v[1]);
  if (v[n - 1] > a) {
    x3 += (long long)abs(a - v[1]);
    x3 += (long long)abs(a - v[n - 1]);
  }
  long long x4 = 0;
  x4 += (long long)abs(a - v[n - 2]);
  if (v[1] < a) {
    x4 += (long long)abs(a - v[n - 2]);
    x4 += (long long)abs(a - v[0]);
  }
  cout << min(x1, min(x2, min(x3, x4))) << endl;
  return 0;
}
