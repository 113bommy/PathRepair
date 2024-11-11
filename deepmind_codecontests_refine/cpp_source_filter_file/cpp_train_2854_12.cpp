#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int c = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int s[n];
  s[0] = arr[0];
  for (int i = 1; i < n; i++) {
    s[i] = s[i - 1] + arr[i];
  }
  int l[n];
  l[0] = 1;
  l[1] = 2;
  if (arr[2] == arr[0] + arr[1]) {
    l[2] = 3;
  } else {
    l[2] = 1;
  }
  for (int i = 3; i < n; i++) {
    if (arr[i] == s[i - 1] - s[i - 3]) {
      l[i] = 1 + l[i - 1];
    } else {
      l[i] = 1;
    }
  }
  int sol = 0;
  if (n <= 2) {
    cout << n;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    sol = max(sol, l[i]);
  }
  cout << sol;
  return 0;
}
