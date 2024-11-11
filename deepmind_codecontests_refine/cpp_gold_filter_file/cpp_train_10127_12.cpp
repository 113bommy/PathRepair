#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int A[n];
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (i + 1 == n) {
        res.push_back(A[i]);
      } else if (i + 1 < n and A[i] < A[i + 1]) {
        continue;
      } else if (i + 1 < n and A[i] > A[i + 1]) {
        res.push_back(A[i]);
        int j = i + 1;
        while (j < n and A[j] < A[j - 1]) {
          j++;
        }
        i = j - 1;
        res.push_back(A[i]);
      }
    }
    int le = res.size();
    if (le % 2 == 0) le -= 1;
    long long ans = 0;
    for (int i = 0; i < le; i += 2) {
      if (i + 1 < le)
        ans += res[i] - res[i + 1];
      else
        ans += res[i];
    }
    cout << ans << endl;
  }
  return 0;
}
