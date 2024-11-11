#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, q;
    cin >> n >> q;
    vector<long long> A;
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      A.push_back(a);
    }
    vector<long long> ans;
    long long rotate = 0;
    for (long long i = 0; i < A.size() - 1; i++) {
      if (A[i] > A[i + 1] && rotate == 0) {
        ans.push_back(A[i]);
        rotate = 1;
      } else if (A[i] < A[i + 1] && rotate == 1) {
        ans.push_back(-A[i]);
        rotate = 0;
      }
    }
    if (rotate == 0) {
      ans.push_back(A.back());
    }
    if (ans.back() < 0) ans.pop_back();
    cout << accumulate(ans.begin(), ans.end(), 0LL) << endl;
  }
  return 0;
}
