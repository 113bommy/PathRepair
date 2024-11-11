#include <bits/stdc++.h>
using namespace std;
int n, i, j, x, answer = 0;
int A[100000];
int main() {
  cin >> n >> x;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  sort(A, A + n);
  bool ok = false;
  for (int i = 0; i < n; ++i)
    if (A[i] == x) ok = true;
  if (!ok) {
    answer = 1;
    A[n] = x;
    n++;
  }
  sort(A, A + n);
  ok = false;
  for (int i = 1; i <= n; ++i)
    if (A[i - 1] == x) {
      if (i == (n + 1) / 2) ok = true;
    }
  if (ok)
    cout << answer << endl;
  else {
    int MIN = 1000000;
    for (int i = 1; i <= n; ++i)
      if (A[i - 1] == x) {
        int nn, ii, R = 1000000;
        if (i < (n + 1) / 2) {
          nn = n;
          ii = i;
          for (int j = 1; j <= 10000; ++j) {
            nn++;
            ii++;
            if (ii == (nn + 1) / 2) {
              R = j;
              break;
            }
          }
        } else {
          nn = n;
          ii = i;
          for (int j = 1; j <= 10000; ++j) {
            nn++;
            if (ii == (nn + 1) / 2) {
              R = j;
              break;
            }
          }
        }
        if (R < MIN) MIN = R;
      }
    answer = answer + MIN;
    cout << answer << endl;
  }
}
