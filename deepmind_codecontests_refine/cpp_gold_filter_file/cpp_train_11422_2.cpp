#include <bits/stdc++.h>
using namespace std;
bool checker(char arr[], int start, int end0) {
  for (int i = start; i <= end0; i++) {
    if (arr[i] != arr[end0 - i]) return 0;
  }
  return 1;
}
int main() {
  string a;
  int n;
  cin >> a;
  n = a.size();
  char *arr = &a[0u];
  if (checker(arr, 0, n - 1)) {
    for (int i = 0; i < n - 2; i++) {
      if (a[i] != a[i + 1]) {
        cout << n - 1;
        return 0;
      }
    }
    cout << 0;
  } else
    cout << n;
}
