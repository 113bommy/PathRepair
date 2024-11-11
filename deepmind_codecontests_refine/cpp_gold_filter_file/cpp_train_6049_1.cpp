#include <bits/stdc++.h>
using namespace std;
int A[1001];
int main() {
  int n, a, b, cost = 0, a1, f = 0;
  cin >> n >> a >> b;
  a1 = min(a, b);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n / 2; i++) {
    if (A[i] == 1) {
      if (A[n - i - 1] == 0) {
        f = 1;
      } else if (A[n - i - 1] == 2) {
        cost += b;
      }
    } else if (A[i] == 0) {
      if (A[n - i - 1] == 1) {
        f = 1;
      } else if (A[n - i - 1] == 2) {
        cost += a;
      }
    } else {
      if (A[n - i - 1] == 1) {
        cost += b;
      } else if (A[n - 1 - i] == 0) {
        cost += a;
      } else
        cost += a1 + a1;
    }
  }
  if (n % 2 != 0) {
    if (A[n / 2] == 2) cost += a1;
  }
  if (f == 1) {
    cout << "-1" << endl;
  } else
    cout << cost << endl;
  return 0;
}
