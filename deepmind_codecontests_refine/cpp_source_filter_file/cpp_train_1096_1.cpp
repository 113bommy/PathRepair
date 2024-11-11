#include <bits/stdc++.h>
using namespace std;
int maximum(int a, int b, int c, int d) {
  if (a >= b && a > c && a > d)
    return a;
  else if (b > a && b > c && b > d)
    return b;
  else if (c > a && c > b && c > d)
    return c;
  else
    return d;
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  int max = 0, min = INT_MAX, min_loc, max_loc;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > max) {
      max = arr[i];
      max_loc = i;
    }
    if (arr[i] < min) {
      min = arr[i];
      min_loc = i;
    }
  }
  if (min_loc == 0 && max_loc == n - 1)
    cout << n - 1;
  else if (max_loc == 0 && min_loc == n - 1)
    cout << n - 1;
  else {
    cout << maximum(max_loc, min_loc, n - min_loc - 1, n - max_loc - 1);
  }
  return 0;
}
