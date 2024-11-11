#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temporary = 0, length = 1, h = 1, hmax = 1;
  cin >> n;
  int arr[n];
  for (int i = 1; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        temporary = arr[i];
        arr[i] = arr[j];
        arr[j] = temporary;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      length++;
      h = 1;
    }
    if (arr[i] == arr[i - 1]) {
      h++;
      if (h > hmax) {
        hmax = h;
      }
    }
  }
  cout << hmax << ' ' << length;
  return 0;
}
