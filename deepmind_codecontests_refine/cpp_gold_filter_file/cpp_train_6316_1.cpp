#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, c = 0;
  cin >> n >> k;
  int a[n], i = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  i = 0;
  while (a[i] <= k && i < n) {
    c++;
    i++;
  }
  int j = n - 1;
  while (a[j] <= k && j > i - 1) {
    c++;
    j--;
  }
  cout << c;
  return 0;
}
