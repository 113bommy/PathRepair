#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, A[200000], B[200000], i;
  cin >> n;
  vector<long long> C;
  for (i = 0; i < n; i++) cin >> A[i];
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      C.push_back(A[i]);
    }
  }
  for (i = 0; i < n; i++) {
    if (i % 2 == 1) C.push_back(A[i]);
  }
  long long s = 0, mx = -1;
  for (i = 0; i < (n + 1) / 2; i++) {
    s += A[i];
  }
  mx = max(s, mx);
  for (i = (n + 1) / 2; i < 2 * n; i++) {
    s -= A[(i - (n + 1) / 2) % n];
    s += A[i % n];
    mx = max(mx, s);
  }
  cout << mx;
  return 0;
}
