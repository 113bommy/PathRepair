#include <bits/stdc++.h>
using namespace std;
long long bin_pow(long long a, long long b) {
  if (!b) return 1;
  long long ans = bin_pow(a, b / 2);
  ans = ans * ans;
  if (b % 2) ans = ans * a;
  return ans;
}
int main() {
  long long x[3], y[3];
  int i = 0;
  for (; i < 3; i++) {
    cin >> x[i] >> y[i];
  }
  if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])) {
    cout << 1;
    return 0;
  }
  i = 0;
  int j = 1;
  int k = 2;
  if (((x[i] == x[k] || x[j] == x[k]) &&
       ((min(y[i], y[j]) <= y[k]) && (y[k] <= max(y[i], y[j])))) ||
      ((y[i] == y[k] || y[j] == y[k]) &&
       ((min(x[i], x[j]) <= x[k]) && (x[k] <= max(x[i], x[j]))))) {
    cout << 2;
    return 0;
  }
  i = 1;
  j = 0;
  k = 2;
  if (((x[i] == x[k] || x[j] == x[k]) &&
       ((min(y[i], y[j]) <= y[k]) && (y[k] <= max(y[i], y[j])))) ||
      ((y[i] == y[k] || y[j] == y[k]) &&
       ((min(x[i], x[j]) <= x[k]) && (x[k] <= max(x[i], x[j]))))) {
    cout << 2;
    return 0;
  }
  i = 2;
  j = 1;
  k = 0;
  if (((x[i] == x[k] || x[j] == x[k]) &&
       ((min(y[i], y[j]) <= y[k]) && (y[k] <= max(y[i], y[j])))) ||
      ((y[i] == y[k] || y[j] == y[k]) &&
       ((min(x[i], x[j]) <= x[k]) && (x[k] <= max(x[i], x[j]))))) {
    cout << 2;
    return 0;
  }
  cout << 3;
  return 0;
}
