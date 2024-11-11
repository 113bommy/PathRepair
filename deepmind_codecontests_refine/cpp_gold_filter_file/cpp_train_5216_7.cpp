#include <bits/stdc++.h>
using namespace std;
int a[200000];
int b[200000] = {0};
int main() {
  int n;
  int m = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] <= a[i]) b[i] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (b[i] != 0) b[i] += b[i - 1];
  }
  for (int i = 0; i < n; i++)
    if (b[i] >= m) m = b[i];
  cout << m + 1;
  return 0;
}
