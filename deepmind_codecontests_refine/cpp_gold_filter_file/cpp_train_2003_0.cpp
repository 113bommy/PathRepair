#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    long long A[n];
    for (int j = 0; j < n; j++) {
      cin >> A[j];
    }
    int count = 0;
    int p = 0;
    int max = 0;
    for (int j = 0; j < n - 1; j++) {
      count = 0;
      if (A[j] > A[j + 1]) {
        while (A[j] > A[j + 1]) {
          long long g = pow(2, p);
          A[j + 1] = A[j + 1] + g;
          p++;
          count++;
        }
        if (count > max) {
          max = count;
        }
        p = 0;
        A[j + 1] = A[j];
      }
    }
    cout << max << endl;
  }
  return 0;
}
