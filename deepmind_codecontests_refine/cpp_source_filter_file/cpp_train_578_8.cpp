#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  int A[n], B[n];
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) {
    cin >> B[i];
  }
  for (int i = 1; i < l; i++) {
    if (A[i] != B[i]) {
      cout << "FALSE";
      return 0;
    }
  }
  for (int i = r + 1; i <= n; i++) {
    if (A[i] != B[i]) {
      cout << "FALSE";
      return 0;
    }
  }
  vector<int> a, b;
  for (int i = l; i <= r; i++) {
    a.push_back(A[i]);
    b.push_back(B[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      cout << "FALSE";
      return 0;
    }
  }
  cout << "TRUTH";
}
