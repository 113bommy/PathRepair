#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long A[n], C[n];
    vector<long long> B;
    for (long long i = 0; i < n; i++) cin >> A[i];
    for (long long i = 0; i < n; i++) {
      cin >> C[i];
      if (C[i] == 0) B.push_back(A[i]);
    }
    sort(B.begin(), B.end());
    for (long long i = 0; i < n; i++) {
      if (C[i] == 0) {
        cout << *B.end() << ' ';
        B.pop_back();
      } else
        cout << A[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
