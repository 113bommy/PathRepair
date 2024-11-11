#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n, x, k, A[100001];
int main() {
  memset(A, -1, sizeof(A));
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> k;
    if (A[k] < x - 1) {
      cout << "NO";
      return 0;
    }
    A[k] = max(A[k], x);
  }
  cout << "YES";
  return 0;
}
