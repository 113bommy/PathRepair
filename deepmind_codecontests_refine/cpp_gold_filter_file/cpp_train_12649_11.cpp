#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  int j = 0;
  int min = 100000000000;
  while (j < n / 2) {
    if (min > (A[n / 2 + j] - A[j])) {
      min = (A[n / 2 + j] - A[j]);
    }
    j++;
  }
  cout << min;
}
