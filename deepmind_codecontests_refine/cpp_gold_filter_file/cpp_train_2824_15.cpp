#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, count, c;
  cin >> n >> k;
  count = c = 1;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  i = 0;
  while (i < n) {
    count = 1;
    for (j = i; j < n - 1; j++) {
      if (arr[j] != arr[j + 1]) {
        count++;
      } else {
        break;
      }
    }
    c = max(c, count);
    i = j + 1;
  }
  cout << c << '\n';
  return 0;
}
