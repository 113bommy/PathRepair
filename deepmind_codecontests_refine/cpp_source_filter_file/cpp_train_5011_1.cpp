#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, n, max = 0, min = 0, pr, cost;
  cin >> n;
  char arr[n], a[n], b[n], c[n];
  scanf("%s", arr);
  for (i = 1; i < n; i++) {
    if (i != n - 1) {
      if (arr[i] == arr[i - 1]) {
        cost++;
        arr[i] = 'R';
        if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1]) arr[i] = 'G';
        if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1]) arr[i] = 'B';
      }
    } else {
      if (arr[i] == arr[i - 1]) {
        cost++;
        arr[i] = 'R';
        if (arr[i] == arr[i - 1]) arr[i] = 'G';
        if (arr[i] == arr[i - 1]) arr[i] = 'B';
      }
    }
  }
  cout << cost << endl;
  for (i = 0; i < n; i++) {
    cout << arr[i];
  }
}
