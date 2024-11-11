#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; ++i) cin >> A[i];
  int flag = 0;
  int i = 0;
  while (i < n - 1 && A[i] < A[i + 1]) {
    i++;
  }
  while (i < n - 1 && A[i] > A[i + 1]) {
    i++;
  }
  if (i != n - 1)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
