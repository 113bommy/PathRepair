#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int i = 0;
  int moves = 0;
  while (i < n - 1) {
    if (arr[i] >= arr[i + 1]) {
      int x = (arr[i] - arr[i + 1]) / d + 1;
      moves += x;
      arr[i + 1] = arr[i] + x * d;
    } else {
      i++;
    }
  }
  cout << moves;
}
