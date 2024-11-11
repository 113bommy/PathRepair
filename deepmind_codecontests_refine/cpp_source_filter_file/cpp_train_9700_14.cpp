#include <bits/stdc++.h>
using namespace std;
int n, k, q, d, A[500], w, c;
bool status;
double mi = 100500, ma = 0, b = 0, h = 0;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  d = n / k;
  for (int i = 0; i < q; i++) {
    status = true;
    b = 0;
    for (int j = 0; j < d; j++) {
      cin >> w;
      if (A[w - 1] != -1) {
        b += A[w - 1];
        A[w - 1] = -1;
      } else {
        status = false;
      }
    }
    if (status) {
      c++;
      if (b / d > ma) ma = b / d;
      if (b / d < mi) mi = b / d;
    }
  }
  if (c < k) {
    sort(A, A + n);
    b = h = 0;
    for (int i = 0; i < d; i++) {
      b += A[i + c * d];
      h += A[n - 1 - i];
    }
    if (b / d < mi) mi = b / d;
    if (h / d > ma) ma = b / d;
  }
  printf("%.10f %.10f", mi, ma);
}
