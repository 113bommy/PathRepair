#include <bits/stdc++.h>
using namespace std;
int n, m, A[100];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  int max_ = A[n - 1] + m;
  for (int i = 0; i < n; i++) {
    m -= (A[n - 1] - A[i]);
  };
  int c = (m % n == 0) ? 0 : 1;
  int min_;
  if (m == 0)
    min_ = A[n - 1];
  else
    min_ = (m <= n) ? A[n - 1] + 1 : A[n - 1] + m / n + c;
  cout << min_ << " " << max_;
}
