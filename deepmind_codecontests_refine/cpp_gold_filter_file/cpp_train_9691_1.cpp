#include <bits/stdc++.h>
using namespace std;
const long long N = 100001;
long long A[N];
set<long long> s;
int main() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      s.insert(A[i] - k);
    } else {
      if (A[i] - k - A[i - 1] >= k) {
        s.insert(A[i] - k);
      }
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (i == n - 1) {
      s.insert(A[i] + k);
    } else {
      if (A[i + 1] - (A[i] + k) >= k) {
        s.insert(A[i] + k);
      }
    }
  }
  long long sz = s.size();
  cout << sz << endl;
  return 0;
}
