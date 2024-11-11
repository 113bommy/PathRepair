#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n, p;
    cin >> n >> p;
    vector<long long> A(n), B(p);
    long long i;
    for (i = 0; i < n; i++) cin >> A[i];
    for (i = 0; i < p; i++) {
      cin >> B[i];
      B[i]--;
    }
    sort(B.begin(), B.end());
    long long minn = B[0], maxx = B[0] + 1;
    for (i = 0; i < p - 1; i++) {
      if (B[i] + 1 != B[i + 1]) {
        sort(A.begin() + minn, A.begin() + maxx + 1);
        minn = B[i + 1];
        maxx = B[i + 1] + 1;
      } else {
        maxx = B[i + 1] + 1;
      }
    }
    sort(A.begin() + minn, A.begin() + maxx + 1);
    long long f = 0;
    for (i = 0; i < n; i++) {
      if (A[i] > A[i + 1]) f = 1;
    }
    if (f == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
