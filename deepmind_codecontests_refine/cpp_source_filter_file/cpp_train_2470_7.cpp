#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, last;
  do {
    cin >> n;
  } while (n < 1 || n > 1000);
  int a[n];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i < n; i++) {
    int s = a[i];
    int j = i - 1;
    while (j > 0 && a[j] > s) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = s;
  }
  last = a[(n + 1) / 2];
  cout << last;
  return 0;
}
