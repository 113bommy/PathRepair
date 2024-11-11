#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[n], c = 0, d = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    if (A[i] == i) {
      c++;
    }
    if (A[A[i]] == i) {
      d = 1;
    }
  }
  if (c == n) {
    cout << c;
    return 0;
  }
  if (d == 0) {
    cout << c + 1;
  } else
    cout << c + 2;
  return 0;
}
