#include <bits/stdc++.h>
using namespace std;
int A[1000];
void quicksort(int l, int r) {
  int b = l;
  if (r - l < 1) {
    return;
  }
  for (int i = l; i < r; ++i) {
    if (A[i] < A[r]) {
      swap(A[i], A[b]);
      b = b + 1;
    }
  }
  swap(A[r], A[b]);
  quicksort(l, b - 1);
  quicksort(b + 1, r);
}
int main() {
  int r;
  cin >> r;
  for (int i = 0; i < r; ++i) {
    cin >> A[i];
  }
  quicksort(0, r - 1);
  if (r % 2 > 0) {
    cout << A[(r / 2)];
  } else {
    cout << min(A[r / 2], A[r / 2 - 1]);
  }
  return 0;
}
