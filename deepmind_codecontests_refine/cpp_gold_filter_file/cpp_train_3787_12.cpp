#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  int arr[n];
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      arr[i] = 1;
    else
      arr[i] = 0;
  }
  int temp;
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < n - 1;) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        j += 2;
      } else
        j += 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1)
      cout << "B";
    else
      cout << "G";
  }
  return 0;
}
