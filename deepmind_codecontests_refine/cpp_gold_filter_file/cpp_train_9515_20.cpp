#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, max = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int cnt = 0;
      for (int k = i; k <= j; k++) {
        if (arr[k] == 0) cnt++;
      }
      for (int c = 0; c < i; c++) {
        if (arr[c] == 1) cnt++;
      }
      for (int c = j + 1; c < n; c++) {
        if (arr[c] == 1) cnt++;
      }
      if (cnt > max) max = cnt;
    }
  }
  cout << max << endl;
}
