#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, f, A[10001];
  cin >> n >> f;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] <= f) {
      sum += 1;
    } else {
      sum += 2;
    }
  }
  cout << sum;
  return 0;
}
