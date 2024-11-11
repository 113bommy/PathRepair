#include <bits/stdc++.h>
using namespace std;
int a[3000000], zero[3000000];
int main(void) {
  int n, i, j;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    a[i] = j;
    if (j == 0) zero[i] = 1;
  }
  for (i = 1; i < n; i++) zero[i] += zero[i - 1];
  long long min = 0;
  j = n - 1;
  for (i = 0; i < n; i++) {
    if (a[i] == 1) min += (zero[j] - zero[i]);
  }
  cout << min;
  return 0;
}
