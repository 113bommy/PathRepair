#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k;
  double a, b, c, s;
  cin >> n;
  int ar[n];
  for (i = 0; i < n; i++) {
    cin >> ar[i];
  }
  sort(ar, ar + n);
  for (i = i; i < n - 1; i++) {
    if (ar[i - 1] + ar[i] > ar[i + 1]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
