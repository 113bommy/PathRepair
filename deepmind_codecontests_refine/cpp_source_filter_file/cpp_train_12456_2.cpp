#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    int cnt = 0, j = i, x = 0;
    while (x < 3 && j < n) {
      j = arr[j];
      x++;
    }
    if (i == j && x == 3) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
