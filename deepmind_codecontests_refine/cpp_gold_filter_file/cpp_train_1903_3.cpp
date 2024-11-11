#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> A(n), l(n);
    for (long long i = 0; i < n; i++) cin >> A[i];
    for (long long i = 0; i < n; i++) cin >> l[i];
    vector<long long> not_blocked;
    for (long long i = 0; i < n; i++) {
      if (l[i] == 0) {
        not_blocked.push_back(A[i]);
      }
    }
    sort(not_blocked.rbegin(), not_blocked.rend());
    long long uk = 0;
    long long sum = 0;
    for (long long i = 0; i < n; i++) {
      if (l[i] == 1) {
        cout << A[i] << ' ';
      } else {
        cout << not_blocked[uk++] << ' ';
      }
    }
    cout << '\n';
  }
}
