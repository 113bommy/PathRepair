#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int left = 0, maxlength = 0, distinct = 0;
  int min = 0, max_num = 0;
  for (int right = 0; right < n; right++) {
    if (A[right] > A[max_num]) {
      max_num = right;
      distinct = A[max_num] - A[min];
    }
    if (A[right] < A[min]) {
      min = right;
      distinct = A[max_num] - A[min];
    }
    while (distinct > 1) {
      left++;
      if (left > min) min = left;
      if (left > max_num) max_num = left;
      distinct = A[max_num] - A[min];
    }
    maxlength = max(maxlength, right - left + 1);
  }
  cout << maxlength;
  return 0;
}
