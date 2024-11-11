#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  a[0] = 1;
  a[1] = 2;
  for (int i = 2; i < n + 1; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  char arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = 'o';
  }
  for (int i = 0; i < n + 1; i++) {
    if (a[i] > n + 1) {
      break;
    } else {
      arr[a[i]] = 'O';
    }
  }
  for (int i = 1; i < n + 1; i++) cout << arr[i];
  return 0;
}
