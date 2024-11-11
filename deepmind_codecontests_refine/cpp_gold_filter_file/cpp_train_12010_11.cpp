#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, p = 0;
  cin >> x;
  int arr[x];
  for (int i = 0; i < x; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + x);
  for (int i = 0; i < x; i++)
    if (arr[i] == arr[i + 1]) {
      p++;
    }
  for (int i = 0; i < x; i++) {
    if (arr[i] != arr[0] && x != 0) {
      cout << arr[i];
      break;
    }
    if (x == 1 || (arr[0] == arr[i] && (x - 1) == p)) {
      cout << "NO";
      break;
    }
  }
}
