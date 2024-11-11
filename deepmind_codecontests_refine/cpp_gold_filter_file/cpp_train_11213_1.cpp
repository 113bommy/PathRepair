#include <bits/stdc++.h>
using namespace std;
void print(int A[], int l, int r) {
  cout << r - l + 1 << endl;
  for (int i = l; i <= r; i++) cout << i + 1 << " ";
}
int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  if (n == 1)
    cout << -1;
  else if (n == 2) {
    if (A[0] == A[1])
      cout << -1;
    else {
      cout << 1 << endl;
      cout << 1;
    }
  } else {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += A[i];
    int lsum = 0;
    for (int i = 0; i < n; i++) {
      sum -= A[i];
      lsum += A[i];
      if (lsum != sum) {
        print(A, 0, i);
        break;
      }
    }
  }
  return 0;
}
