#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int leftLen = 1, rightLen = 1;
  for (int i = 1; i < n; ++i) {
    if (A[i] > A[i - 1])
      ++leftLen;
    else
      break;
  }
  for (int i = n - 2; i >= 0; --i) {
    if (A[i] > A[i + 1])
      ++rightLen;
    else
      break;
  }
  (leftLen % 1 || rightLen % 1) ? printf("Alice") : printf("Bob");
  return 0;
}
