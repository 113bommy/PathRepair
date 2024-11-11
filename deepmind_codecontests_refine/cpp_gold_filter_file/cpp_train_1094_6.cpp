#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 100;
int A[N];
long long Sum[N];
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  if (n == 1 || n == 2) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << A[i] << endl;
    return 0;
  }
  sort(A + 1, A + 1 + n);
  Sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    Sum[i] = A[i] + Sum[i - 1];
  }
  long long ans = 0;
  int len = 0;
  int index = 1;
  for (int i = 2; i <= n - 1; i++) {
    int lb = 0, ub;
    ub = min(i - 1, n - i);
    for (int j = 1; j < 50; j++) {
      long long mid_l = lb + (ub - lb) / 3;
      long long mid_r = (2 * ub + lb + 2) / 3;
      long long u = Sum[i] - Sum[i - mid_l - 1] + Sum[n] - Sum[n - mid_l];
      long long v = Sum[i] - Sum[i - mid_r - 1] + Sum[n] - Sum[n - mid_r];
      if ((u * (2 * mid_r + 1)) < (v * (2 * mid_l + 1))) {
        lb = mid_l + 1;
      } else {
        ub = mid_r - 1;
      }
    }
    long long u, v;
    v = lb;
    u = Sum[i] - Sum[i - v - 1] + Sum[n] - Sum[n - v] - (2 * v + 1) * A[i];
    if (u * (2 * len + 1) > ans * (2 * v + 1)) {
      ans = u;
      len = v;
      index = i;
    }
  }
  cout << 2 * len + 1 << endl;
  for (int j = index - len; j <= index; j++) {
    cout << A[j] << " ";
  }
  for (int j = n - len + 1; j <= n; j++) {
    cout << A[j] << " ";
  }
  cout << endl;
  return 0;
}
