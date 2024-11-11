#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] >= 0) {
      A[i] = -A[i] - 1;
    }
  }
  if (n % 2 == 1) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
      if (A[i] != -1) pos = i;
    }
    if (pos != -1) {
      for (int i = 0; i < n; i++) {
        if (A[i] == -1) continue;
        if (abs(A[pos]) < abs(A[i])) {
          pos = i;
        }
      }
    } else {
      A[0] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (i == pos) {
        cout << (-A[i] - 1) << " ";
      } else {
        cout << A[i] << " ";
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
  }
}
