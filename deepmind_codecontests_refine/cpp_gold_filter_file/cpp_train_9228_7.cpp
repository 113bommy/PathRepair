#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, mx = 0;
  cin >> n;
  vector<int> A(n);
  for (int& x : A) cin >> x;
  int m = -1;
  for (int i = 1; i < n; i++)
    if (abs(A[i] - A[i - 1]) != 1) {
      if (A[i] == A[i - 1]) return cout << "NO", 0;
      if (m == -1)
        m = abs(A[i] - A[i - 1]);
      else if (abs(A[i] - A[i - 1]) != m)
        return cout << "NO", 0;
    }
  if (m == -1) return cout << "YES\n" << 1000000000 << " " << 1, 0;
  for (int i = 1; i < n; i++)
    if (abs(A[i] - A[i - 1]) == 1 && (A[i] - 1) / m != (A[i - 1] - 1) / m)
      return cout << "NO", 0;
  return cout << "YES\n" << 1000000000 << " " << m, 0;
}
