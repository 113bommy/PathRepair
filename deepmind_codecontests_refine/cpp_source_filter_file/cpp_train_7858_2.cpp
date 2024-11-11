#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, A[100010];
  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];
  int max = 0, count = 1, j;
  for (i = 0; i < n; i++) {
    if (A[i] <= A[i + 1]) {
      count++;
      if (count > max) max = count;
    } else
      count = 1;
  }
  cout << max << endl;
  return 0;
}
